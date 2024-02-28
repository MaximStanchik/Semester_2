#include<iostream>
#include<ctime>

using namespace std;

//исползуем для быстрой сорттироваки
void toquickSort(int* array, int lowvalue, int highvalue)
{
	int i = lowvalue;//это самое первое первое значение
	int j = highvalue;//последнее значение
	int pivot = array[(i + j) / 2];//центральный элемент массива
	int temp;

	while (i <= j)
	{
		while (array[i] < pivot)
			i++; //добавление к девой части
		while (array[j] > pivot)
			j--;//добавление к правой части
		if (i <= j) //элементы i и j меняются местами если выполняется условие
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > lowvalue) //если последнее значение больше первого 
		toquickSort(array, lowvalue, j);
	if (i < highvalue)//если последнее значение больше первого 
		toquickSort(array, i, highvalue);
}


int main()
{
	setlocale(LC_CTYPE, "russian");
	srand(time(NULL));
	int N;
	clock_t start, end; //clock_t сообщает реальное время, прошедшее с момента инициализации CRT при запуске процесса
	double cpu_time_used;
	cout << "Пожалуйста,введите размер массива: ";
	cin >> N;
	//тут мы копируем массив А в массивы B, C, D, Е.
	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];
	int* D = new int[N];
	int* E = new int[N];

	cout << "Исходный массив A: " << endl;
	for (int i = 0; i < N; i++) {
		A[i] = rand(); //тут с помощью rand создаем случайные числа
		cout << A[i] << " ";
	}

	cout << endl << endl;
	//тут копируем в другие массивы массив А[]
	for (int i = 0; i < N; i++) {
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}

	start = clock(); //тут мы начинаем считать сколько времени уйдет на выполнение кода

	for (int i = 0; i < N; i++) { //пока массив не будет состоять из 5 чисел программа будет выполняться
		for (int j = 0; j < N - 1; j++) {
			if (B[j] > B[j + 1]) { //если левый элемент больше правого, то:
				int b = B[j]; //левый и правый элемент меняются местами
				B[j] = B[j + 1];
				B[j + 1] = b;
			}
		}
	}
	cout << "Отсортированный массив B методом пузырьковой сортировки: " << endl;
	for (int i = 0; i < N; i++) {//выводим отсортированные элементы массива N раз по порядку
		cout << B[i] << " ";
	}
	cout << endl;

	end = clock();//тут заканчивается вычисление
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; //CLOCKS_PER_SEC--макрос, заменяющийся на значение, представляющее число тиков в секунду, которое возвращает функция clock.

	cout << "Время,потраченное на выполнение сортировки: " << cpu_time_used << " секунд" << endl;

	cout << endl;

	start = clock();

	int l, c;
	l = N / 2;//тут делим массив на 2
	while (l != 0) {
		for (int i = 0; i < N - l; i++) {
			int j = i;
			while (j >= 0 && C[j] > C[j + l]) {
				c = C[j];
				C[j] = C[j + l];
				C[j + l] = c;//элементы меняются местами
				j--;
			}
		}
		l = l / 2; //и пока мы можем делить на 2 мы массив делим
	}
	cout << "Отсортированный массив C сортировкой вставкой (или методом Шелла): " << endl;
	for (int i = 0; i < N; i++) { //выводим отсортированные элементы массива N раз по порядку
		cout << C[i] << " ";
	}
	cout << endl;

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	cout << "Время,потраченное на выполнение сортировки: " << cpu_time_used << " секунд" << endl;

	cout << endl;

	start = clock();

	int d;
	int min;//сначала нужно найти элемент в массиве с минимальным значением
	for (int i = 0; i < N; i++) {
		min = i;
		for (int j = i + 1; j < N; j++) {
			if (D[j] < D[min]) {//далее сравниваются 1 и 2  элементы массива, потом 2 и3 и т.д.
				min = j;//минимальное значение=номер элемента массива
			}
		}
		if (i != min)
		{
			d = D[i]; //тут происходит замена элементов массива
			D[i] = D[min];
			D[min] = d;
		}
	}
	cout << "Отсортированный массив D сортировкой выбора: " << endl;
	for (int i = 0; i < N; i++) {//тут выводим по порядку отсорттированные элементы массива
		cout << D[i] << " ";
	}
	cout << endl;

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	cout << "Время,потраченное на выполнение сортировки: " << cpu_time_used << " секунд" << endl;

	cout << endl;

	start = clock(); //начинаем отсчет времени для высчитывания скольько времени выполняется программа

	toquickSort(E, 0, N - 1); //используем функцию quickSort для быстрой сортировки
	cout << "Отсортированный массив E быстрой сортировкой:" << endl;
	for (int i = 0; i < N; i++) {//тут выводятся в консоль упорядоченные элементы массива
		cout << E[i] << " ";
	}
	cout << endl;

	end = clock();//тут уже подсчитали
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	cout << "Время,потраченное на выполнение сортировки: " << cpu_time_used << " секунд" << endl;
	
	
	//используем delete для каждого new и чтобы возвратить память, выделенную оператором new обратно в кучу чтобы избежать утечки памяти (куча--это хранилище памяти,рассположенное в ОЗУ, которое допускает выделение динамической памяти)
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;
	
}