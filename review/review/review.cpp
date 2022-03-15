#include <iostream>
using namespace std;

void number(int x0, int count);
int main()
{
	int choice;
	cout << "1. Using 5 or more variables\n";
	cout << "2. Using loop only\n";
	cout << "3. Using loop and Array(1 dimensional only)\n";
	cout << "4. Using recursion\n";
	cin >> choice;


	switch (choice)
	{
	case 1:
		int num1, num2, num3, num4, num5;
		cout << "Please enter a number:";
		cin >> num1;
		cout << "Please enter a number:";
		cin >> num2;
		if (num1 > num2) {
			cout << " the current number is less than the previous " << endl;
		}
		else if (num1 < num2) {
			cout << " the current number is greater than the previous " << endl;
		}
		else {
			cout << "the current number is equal to the previous numbe" << endl;
		}
		cout << "Please enter a number:";
		cin >> num3;
		if (num3 > num2) {
			cout << " the current number is greater than the previous: " << endl;
		}
		else if (num3 < num2) {
			cout << " the current number is less than the previous: " << endl;
		}
		else {
			cout << "the current number is equal to the previous numbe" << endl;
		}
		cout << "Please enter a number:";
		cin >> num4;
		if (num4 > num3) {
			cout << " the current number is greater than the previous: " << endl;
		}
		else if (num4 < num3) {
			cout << " the current number is less than the previous: " << endl;
		}
		else {
			cout << "the current number is equal to the previous numbe" << endl;
		}
		cout << "Please enter a number:";
		cin >> num5;
		if (num5 > num4) {
			cout << " the current number is greater than the previous: " << endl;
		}
		else if (num5 < num4) {
			cout << " the current number is less than the previous: " << endl;
		}
		else {
			cout << "the current number is equal to the previous numbe" << endl;
		}
		break;
	case 2:
		int x0, x1;
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
		break;
	case 3:
		int x[5];
		cout << "input a number: ";
		cin >> x[0];
		for (int i = 0; i < 4; i++) {
			cout << "input a number: ";
			cin >> x[i + 1];
			if (x[i] < x[(i + 1)]) {
				cout << "the current number is greater than the previous number\n";
			}
			if (x[i] > x[(i + 1)]) {
				cout << "the current number is less than the previous number\n";
			}
			else if (x[i] == x[(i + 1)]) {
				cout << "the current number is equal to the previous number\n";
			}
		}
		break;

	case 4:
		int x4;
		cout << "input a number: ";
		cin >> x4;
		number(x4, 1);
		break;

	default:
		break;
	}
}
void number(int x0, int count)
{
	int x1;
	cout << "input a number: ";
	cin >> x1;
	if (x0 < x1) {
		cout << "the current number is greater than the previous number\n";
	}if (x0 > x1) {
		cout << "the current number is less than the previous number\n";
	}
	else if (x0 == x1) {
		cout << "the current number is equal to the previous number\n";
	}
	count++;
	if (count == 5) {
		cout << "end";
	}
	else
	{
		number(x1, count);
	}
}