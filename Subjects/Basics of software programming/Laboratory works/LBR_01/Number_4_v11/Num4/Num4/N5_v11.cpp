//#include <iostream>
//#include <iomanip>
//#include <cstdlib>
//#include <climits>
//#include <ctime>
//using namespace std;
//
//int main()
//{
//    srand((int)time(0));
//    int n, m, min = INT_MAX,  imin = 0, jmin = 0, x, v, b, o;
//    //первая матрица
//    cout << "n="; cin >> n;
//    cout << "m="; cin >> m;
//
//    int** a = new int* [n];
//    for (int i = 0; i < n; i++)
//        a[i] = new int[m];
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            a[i][j] = rand() % 91 + 10;
//            if (a[i][j] < min) { min = a[i][j]; imin = i; jmin = j; }
//            
//            cout << setw(3) << a[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//   /* cout << "min[" << imin << "][" << jmin << "]=" << min << "\n";*/
//    
//
//    for (int i = 0; i < n; i++)
//        delete[]a[i];
//    delete[]a;
//
//
//    //вторая матрица
//
//    cout << "x="; cin >> x;
//    cout << "v="; cin >> v;
//
//    int** X = new int* [x];
//    for (int i = 0; i < x; i++)
//        X[i] = new int[v];
//
//    for (int i = 0; i < x; i++)
//    {
//        for (int j = 0; j < v; j++)
//        {
//            X[i][j] = rand() % 91 + 10;
//            if (X[i][j] < min) { min = X[i][j]; imin = i; jmin = j; }
//
//            cout << setw(3) << X[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    for (int i = 0; i < n; i++)
//        delete[]X[i];
//    delete[]X;
//
//    //третья матрица
//
//    
//    cout << "b="; cin >> b;
//    cout << "o="; cin >> o;
//
//    int** B = new int* [b];
//    for (int i = 0; i < b; i++)
//        B[i] = new int[o];
//
//    for (int i = 0; i < b; i++)
//    {
//        for (int j = 0; j < o; j++)
//        {
//            B[i][j] = rand() % 91 + 10;
//            if (B[i][j] < min) { min = B[i][j]; imin = i; jmin = j; }
//
//            cout << setw(3) << B[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//  
//    system("pause");
//    return 0;
//}


//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    srand((int)time(0));
//    int a_rows, a_cols, a, b_rows, b_cos, b, c_rows, c_cos, c;
//    int n, m, amount_of_elements, quantity, min = INT_MAX, imin = 0, jmin = 0;
// 
//    //первая матрица
//        cout << "Пожалуйста, введите количество строк" << endl;
//        cout << "a_rows"; cin >> a_rows;//n
//        cout << "Пожалуйста, введите количество столбцов" << endl;
//        cout << "a_cols"; cin >> a_cols;//m
//        amount_of_elements = a_cols * a_rows;//количество всех элементов в матрице
//        int** a = new int* [a_rows];
//        for (int i = 0; i < a_rows; i++)
//            a[i] = new int[m];
//
//        for (int i = 0; i < a_rows; i++)
//        {
//            for (int j = 0; j < a_cols; j++)
//            {
//                a[i][j] = rand() % 90;
//                cout << setw(3) << a[i][j] << " ";
//                if (a[i][j] < min) { min = a[i][j];}
//            }
//            cout << "\n";
//        }
//        /*fmin(9, a_rows, a_cols, a, b_rows, b_cos, b, c_rows, c_cos, c);
//        cout <<"Минимальное значение матрицы равно " << min << "\n";*/
//        
//
//        for (int i = 0; i < a_rows; i++)
//            delete[]a[i];
//        delete[]a;
//   
//    cout << "Благодарим за пользование нашим приложением" << endl;
//    system("pause");
//    return 0;
//}


//void fmin(int i, ...) { //это функция с переменным кол-вом параметров
//    for (int g = 0; g < i / 3;g++) {
//        int min = 999;
//        int* ptr = &i + 2;//
//        cout << min << endl;
//        for (; i > 0; i--) {//
//            if (*ptr < min) {//
//                min = *ptr;//
//            }
//            ptr = ptr + 2;//
//            cout << min << endl;
//        }
//    }
//   
//}












