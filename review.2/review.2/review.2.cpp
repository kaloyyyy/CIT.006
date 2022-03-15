#include <iostream>
using namespace std;


int main()
{
	int x0,x1;
	cout << "input a number: ";
	cin >> x0;
	for (int i = 0; i < 4; i++) {
		cout << "input a number: ";
		cin >> x1;
		if (x0 < x1) {
			cout << "the current number is greater than the previous number\n";
		}
		if (x0 > x1) {
			cout << "the current number is less than the previous number\n";
		}
		else if (x0 == x1) {
			cout << "the current number is equal to the previous number\n";
		}

		x0 = x1;
	}
}