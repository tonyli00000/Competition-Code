#include <cstdio>
#include <vector>

#define MP make_pair
#define PB push_back
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
	ll R, C;
	scanf("%lld %lld\n", &R, &C);
	vector<vector<char> > G(R, vector<char>(C, ' '));
	for (ll r = 0; r<R; r++) {
		char buf[100];
		scanf("%s", buf);
		for (ll c = 0; c<C; c++) {
			G[r][c] = buf[c];
		}
	}
	vector<pll> A;

	for (ll r = 0; r<R; r++) {
		for (ll c = 0; c<C; c++) {
			bool horizontal = (c + 2<C && G[r][c] == '.' && G[r][c + 1] == '.' && G[r][c + 2] == '.' &&
				(c == 0 || G[r][c - 1] == '#'));
			bool vertical = (r + 2<R && G[r][c] == '.' && G[r + 1][c] == '.' && G[r + 2][c] == '.' &&
				(r == 0 || G[r - 1][c] == '#'));
			if (horizontal || vertical) {
				A.PB(MP(r + 1, c + 1));
			}
		}
	}
	printf("%lu\n", A.size());
	for (pll clue : A) {
		printf("%lld %lld\n", clue.X, clue.Y);
	}
}