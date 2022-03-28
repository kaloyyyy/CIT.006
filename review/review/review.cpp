#include <iostream>
using namespace std;

int main()
{
	// linear complexity
	int sum = 0, i;
	clock_t start, stop;
	start = clock();
	for (i = 1; i <= 10000000; i++) {
		sum = sum + i;
	}
	stop = clock();
	cout << sum<<endl;
	cout << "running time is " << stop - start << endl;

	//logarithmic complexity
	start = clock();
	int array[100];

	for (i = 1; i <= 100; i=i*2) {
		array[i] = i;
		cout << array[i] << endl;
	}
	stop = clock();
	cout << "running time is " << stop - start << endl;

	// linear complexity
	start = clock();
	int x = 20;
	for (i = 1; i <= 10000000; i++) {
		x = x + x;
	}
	stop = clock();
	cout <<endl<<"running time is " << stop - start << endl;
}