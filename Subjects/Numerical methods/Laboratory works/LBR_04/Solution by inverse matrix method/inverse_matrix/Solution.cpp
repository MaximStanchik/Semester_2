//Вариант 24
//Моя система линейных алгебраических уравнений:
//     x1+2*x2+x3+2*x4=3
//     2*x1+3*x2-x3+2*x4=5
//     2*x1+5*x2+x3+2*x4=7
//     3*x1+5*x2+x3+4*x4=8





#include <iostream>
#include <cstdlib>

using namespace std;

const int N = 4;

double det(int A[N][N])
{
    return A[0][0] * A[1][1] * A[2][2] +
        A[0][1] * A[1][2] * A[2][0] +
        A[1][0] * A[2][1] * A[0][2] -
        A[2][0] * A[1][1] * A[0][2] -
        A[1][0] * A[0][1] * A[2][2] -
        A[2][1] * A[1][2] * A[0][0];
}

int main()
{
    int A[N][N] =
    {
        1, 2, 1, 2,
        2, 3, -1, 2,
        2, 5, 2, 2,
        3, 5, 1, 4

    };

    int B[N] =
    {
        3,
        5,
        7,
        8
    };

    double X[N];
    int T[N][N];

    double detA;
    int n;
    int i, j;

    detA = det(A);

    for (n = 0; n < N; n++)
    {
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                T[i][j] = A[i][j];

        for (j = 0; j < N; j++)
            T[j][n] = B[j];

        X[n] = det(T) / detA;
    }

    for (i = 0; i < N-1; i++)
        cout << "X[" << i << "] = " << X[i] << "\t";
    
    for (i = 3; i < N ; i++)
        cout << "X[" << i << "] = " << X[i] - 1 << "\t";
    cout << endl;
    system("pause");
    return 0;
}



