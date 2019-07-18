#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class BineroTile {
public:
	BineroTile() {
		clear();
	}
	bool zero;
	bool one;

	void clear() {
		zero = true;
		one = true;
	}

	bool hasValue() {
		return zero ^ one;
	}

	int getValue() {
		if (!hasValue()) {
			return -1;
		}
		return one ? 1 : 0;
	}

	void set(int value) {
		zero = value == 0;
		one = value == 1;
	}
	friend std::ostream& operator<<(std::ostream& os, const BineroTile& dt);

	void operator=(const int &value) {
		set(value);
	}

	bool operator == (const BineroTile &other) const {
		if (this->zero && this->one) {
			return false;
		}
		return (this->zero == other.zero) && (this->one == other.one);
	}
};

std::ostream &operator<<(std::ostream &os, const BineroTile &m) {
	if (m.one && m.zero) {
		return os << "_";
	}
	if (!m.one && !m.zero) {
		return os << "#";
	}
	return os << (m.one ? "1" : "0");
}

class BineroMatch {
	std::vector<BineroTile*> tiles;
	int unknown;

public:
	BineroMatch(std::vector<BineroTile*> tiles) : tiles(tiles) {
	}

	bool scan() {
		bool simplified = false;
		unsigned int zeros = 0;
		unsigned int ones = 0;
		for (unsigned int i = 0; i < tiles.size(); i++) {
			BineroTile* current = tiles[i];

			if (current->getValue() == 0) {
				zeros++;
			}
			if (current->getValue() == 1) {
				ones++;
			}

			if (i < tiles.size() - 1) {
				BineroTile* next = tiles[i + 1];

				// Find Pairs - compare the current value with the next value
				if (*current == *next) {

					int value = 1 - current->getValue();

					if (i > 0) {
						BineroTile* before = tiles[i - 1];
						simplified |= !before->hasValue();
						before->set(value);
					}
					if (i < tiles.size() - 2) {
						BineroTile* after = tiles[i + 2];
						simplified |= !after->hasValue();
						after->set(value);
					}
				}

				// Avoid trios - compare the current value with the value two steps next
				if (i < tiles.size() - 2) {
					BineroTile* twoNext = tiles[i + 2];
					if (*current == *twoNext) {
						int value = 1 - current->getValue();
						simplified |= !next->hasValue();
						next->set(value);
					}
				}
			}
		}

		// Complete rows and columns
		if (zeros + ones < tiles.size()) {
			int halfSize = tiles.size() / 2;
			int maxKnown = std::max(zeros, ones);
			int value = zeros > ones ? 1 : 0;
			if (halfSize == maxKnown) {
				for (unsigned int i = 0; i < tiles.size(); i++) {
					if (!tiles[i]->hasValue()) {
						tiles[i]->set(value);
						simplified = true;
					}
				}
			}
		}

		if (tiles.size() - zeros - ones != unknown) {
			unknown = tiles.size() - zeros - ones;
		}

		// Not implemented: Eliminate impossible combinations in this line
		// Not implemented: Eliminate impossible combinations based on completed rows and columns
		return simplified;
	}

};

class BineroMatchSet {
	std::vector<BineroMatch> matches;

public:
	BineroMatchSet(std::vector<BineroMatch> matches) : matches(matches) {
	}

	bool scan() {
		bool simplified = false;
		for (auto match : matches) {
			simplified |= match.scan();
		}
		return simplified;
	}
};


class BineroPuzzle {
public:
	int width;
	int height;
	std::vector<std::vector<BineroTile>> grid;
	std::vector<BineroMatchSet> match_sets;

	BineroPuzzle(int width, int height) : width(width), height(height) {
		std::vector<BineroMatch> rows;
		std::vector<BineroMatch> columns;

		for (int y = 0; y < height; y++) {
			std::vector<BineroTile> a;
			std::vector<BineroTile*> rowPointers;
			for (int x = 0; x < width; x++) {
				BineroTile tile;
				a.push_back(tile);
			}
			grid.push_back(a);
		}

		for (int x = 0; x < width; x++) {
			std::vector<BineroTile*> columnTiles;
			for (int y = 0; y < height; y++) {
				BineroTile* tile = &grid[y][x];
				columnTiles.push_back(tile);
			}
			columns.push_back(BineroMatch(columnTiles));
		}

		for (int y = 0; y < height; y++) {
			std::vector<BineroTile*> rowTiles;
			for (int x = 0; x < width; x++) {
				BineroTile* tile = &grid[y][x];
				rowTiles.push_back(tile);
			}
			rows.push_back(BineroMatch(rowTiles));
		}

		match_sets.push_back(BineroMatchSet(rows));
		match_sets.push_back(BineroMatchSet(columns));
	}

	void print() {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				std::cout << grid[y][x];
			}
			std::cout << "\n";
		}
	}

	void clear() {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				grid[y][x].clear();
			}
		}
	}

	void set(int x, int y, int value) {
		grid[y][x].set(value);
	}

	void solve() {
		bool simplified = false;
		do {
			simplified = false;
			for (auto set : match_sets) {
				simplified |= set.scan();
			}
		} while (simplified);
	}

};

struct Puzzle {
public:
	BineroPuzzle puzzle;
	Puzzle() : puzzle(BineroPuzzle(4, 4)) {}
};

BineroPuzzle* readFromInput() {
	std::cout << "Enter Dimension: ";
	int size;
	std::cin >> size;
	BineroPuzzle* puzzle = new BineroPuzzle(size, size);

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			char ch;
			std::cin >> ch;
			if (ch == '1') {
				puzzle->set(x, y, 1);
			}
			else if (ch == '0') {
				puzzle->set(x, y, 0);
			}
			else if (ch == 'x') {
			}
			else {
				std::cout << "Unknown char: " << ch;
			}
		}
	}
	return puzzle;
}

void readLine(BineroPuzzle* puzzle, const int y, const std::string line) {
	for (unsigned int x = 0; x < line.length(); x++) {
		char ch = line[x];
		if (ch == '1') {
			puzzle->set(x, y, 1);
		}
		else if (ch == '0') {
			puzzle->set(x, y, 0);
		}
	}
}

BineroPuzzle* readFromFile(const std::string fileName) {
	std::ifstream file;
	file.open(fileName);
	std::string line;
	if (file.is_open()) {
		getline(file, line);
		unsigned int size = line.length();
		BineroPuzzle* puzzle = new BineroPuzzle(size, size);
		readLine(puzzle, 0, line);
		for (unsigned int y = 1; y < size; y++) {
			getline(file, line);
			readLine(puzzle, y, line);
		}
		file.close();
		return puzzle;
	}
	file.close();
	BineroPuzzle* puzzle = new BineroPuzzle(1, 1);
	return puzzle;
}

int main() {
	//BineroPuzzle puzzle = readFromInput();
	BineroPuzzle* puzzle;

	puzzle->print();
	std::cin.get();
	std::cout << puzzle->width << " x " << puzzle->height << "\n";
	puzzle->solve();
	std::cout << "Solution:\n";
	puzzle->print();
	std::cin.get();
	delete puzzle;
	return 0;
}