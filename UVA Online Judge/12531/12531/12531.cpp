#include <iostream>
#include <cmath>

using namespace std;

int lower_angle(int, int);

int main() {
	int angle, minute_angle, hour_angle;
	bool there_is_equal;

	while (cin >> angle) {
		there_is_equal = false;

		for (int minutes = 0; minutes < 720; minutes++) {
			minute_angle = (minutes % 60) * 6;
			hour_angle = minutes / 12 * 6;

			if (angle == lower_angle(minute_angle, hour_angle)) {
				there_is_equal = true;
				break;
			}
		}

		if (there_is_equal) cout << 'Y' << endl;
		else cout << 'N' << endl;
	}

	return 0;
}

int lower_angle(int minute_angle, int hour_angle) {
	int angle = abs(minute_angle - hour_angle);

	if (angle < 180) return angle;
	else return 360 - angle;
}