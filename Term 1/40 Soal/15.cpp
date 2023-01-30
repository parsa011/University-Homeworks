#include "global.h"

int main()
{
	int units = 300;
	float price = 200;

	int target_unit = 0;
	float max_price = 0;

	while (units > 0) {
		if (units * price > target_unit * max_price) {
			target_unit = units;
			max_price = price;
		}
		price += 2.5;
		units--;
	}

	cout << "Best State is " << target_unit << " Units with " << max_price << " $" << endl;
	return 0;
}
