#include <iostream>
#include <ctime>
#include <cstdio>
//N--номер числа 

using namespace std;


//эта рeкурсия
int Fib(int y) {
	int value = 0;
	if (y < 1) return 0;
	if (y == 1) return 1;
	return Fib(y - 1) + Fib(y - 2);
}


int main() {
	setlocale(LC_ALL, "Russian");
	int N, a;
	cin >> N;
	const int n = 500;
	long int x[n];
	double start = clock();
	x[0] = 0; 
	cout << x[0] << endl;
	x[1] = 1; 
	cout << x[1] << endl;

	for (int i = 2; i < N; i++) {
		x[i] = x[i - 1] + x[i - 2];
		cout << x[i] << "  " << endl;
	}
	cout << endl << endl;
	
	printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);


	double start2 = clock();
	int y = 0;
	cout << Fib(N) << endl;
	printf("%.4lf", (clock() - start2) / CLOCKS_PER_SEC);
	cout << " секунд.";


	system("pause");
	return 0;
}