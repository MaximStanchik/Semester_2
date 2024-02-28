#include <iostream>
#include "Varparm.h"

using namespace std;
using namespace Varparm;

int main()
{
    setlocale(LC_ALL, "RU");

	cout << "Вычислена первая функция (ivarparm) с общим количеством параметров 1: " << ivarparm(0) << endl;
	cout << "Вычислена первая функция (ivarparm) с общим количеством параметров 2: " << ivarparm(1, 3) << endl;
	cout << "Вычислена первая функция (ivarparm) с общим количеством параметров 3: " << ivarparm(2, 4, 5) << endl;
	cout << "Вычислена первая функция (ivarparm) с общим количеством параметров 7: " << ivarparm(6, 1, 2, 3, 4, 5, 6) << endl;

	cout << "Вычислена вторая функция (svarparm) с общим количеством параметров 1: " << svarparm(0) << endl;
	cout << "Вычислена вторая функция (svarparm) с общим количеством параметров 2: " << svarparm(1, 25) << endl;
	cout << "Вычислена вторая функция (svarparm) с общим количеством параметров 3: " << svarparm(3, 25, 115) << endl;
	cout << "Вычислена вторая функция (svarparm) с общим количеством параметров 7: " << svarparm(6, 25, 115, 50, 75, 12, 90) << endl;

	cout << "Вычислена третья функция (fvarparm) с общим количеством параметров 1: " << fvarparm(FLT_MAX) << endl;
	cout << "Вычислена третья функция (fvarparm) с общим количеством параметров 2: " << fvarparm(1, FLT_MAX) << endl;
	cout << "Вычислена третья функция (fvarparm) с общим количеством параметров 3: " << fvarparm (2, 2.0, FLT_MAX) << endl;
	cout << "Вычислена третья функция (fvarparm) с общим количеством параметров 7: " << fvarparm(6, 2.0, 3.0, 4.0, 5.0, 6.0, FLT_MAX) << endl;

	cout << "Вычислена четвертая функция (dvarparm) с общим количеством параметров 1: " << dvarparm(DBL_MAX) << endl;
	cout << "Вычислена четвертая функция (dvarparm) с общим количеством параметров 2: " << dvarparm(25.2, DBL_MAX) << endl;
	cout << "Вычислена четвертая функция (dvarparm) с общим количеством параметров 3: " << dvarparm(25.2, 5.2, DBL_MAX) << endl;
	cout << "Вычислена четвертая функция (dvarparm) с общим количеством параметров 7: " << dvarparm(25.2, 5.2, 10.0, 15.0, 25.0, 35.0, DBL_MAX) << endl;
}

    
