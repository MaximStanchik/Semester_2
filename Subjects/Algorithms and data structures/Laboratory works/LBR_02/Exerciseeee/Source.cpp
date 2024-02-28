#include<iostream>
using namespace std;

//quantity-кол-во(англ) шагов.

int main() {
    setlocale(LC_ALL, "rus");
    int N, quantity = 0;
    cout << "Введите число N:" << endl;
    cin >> N;
    int Nmaximum = N;
    int Ndesired = N / 2;
    int Nminimum = 1;
    for (int i = 0; i < log2(N); i++) {
        int a;
        cout << "1-мало" << endl;
        cout << "2-много" << endl;
        cout << "3-угадал" << endl;
        cout << "Значение X:" << Ndesired << endl;
        cin >> a;
        switch (a) {
        case 1:
            if (quantity == int(log2(N)) - 1) {
                Ndesired =Ndesired +1;
                break;
            }
            Nminimum = Ndesired + 1;
            Ndesired = ((Nmaximum + Nminimum) / 2);

            break;
        case 2:
            if (quantity == int(log2(N)) - 1) {
                Ndesired =Ndesired -1;
                break;
            }
            Nmaximum = Ndesired - 1;
            Ndesired = (Nminimum + Nmaximum) / 2;
            break;
        case 3:break;
        default:i - 1;

            break;
        }
        if (a == 3)
            break;
        quantity=quantity +1;
    }
    cout << "Ваше число угадано. Вот оно:" << endl;
    cout << Ndesired << endl;
    cout << "Максимальное число сделаных шагов: " << ceil(log2(N));
    return 0;
}