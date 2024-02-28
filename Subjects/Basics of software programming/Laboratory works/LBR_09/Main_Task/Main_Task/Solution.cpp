#include <iostream>
#include <windows.h>
using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
    char name[NAME_SIZE];
    char city[CITY_SIZE];
    Address* next;
    Address* prev;
};


// счетчик вызовов функции


void insert(Address* e, Address** phead, Address** plast);
Address* setElement(int counter);
void outputList(Address** phead, Address** plast);
void delet(char name[NAME_SIZE], Address** phead, Address** plast);
void find(char name[NAME_SIZE], Address** phead);
void writeToFile(Address** phead);
void readFromFile(Address** phead, Address** plast);
void findMin(Address** phead);
void findcit(char name[NAME_SIZE], Address** phead);
void replaceElement(Address** phead, int counter);
void saveToFile(Address* head);
static int counter = 0; void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
    Address* p = *plast;
    if (*plast == NULL)
    {
        e->next = NULL;
        e->prev = NULL;
        *plast = e;
        *phead = e;
        return;
    }
    else
    {
        p->next = e;
        e->next = NULL;
        e->prev = p;
        *plast = e;
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Rus");
    Address* head = NULL;
    Address* last = NULL;
    short choose = 0;
    while (choose != 8)
    {
        char s[80];  int c;
        cout << "Выберите действие:\n1 — ввод элемента;\n2 — вывод списка;\n3 — удаление элемента;\n4 — поиск элемента;\n5 — сохранить в файл;\n6 — вывод из файла;"
            "\n7 — замена одной строки на другую; \n8 — выход из программы.\n";
        cin.sync();
        gets_s(s);
        cout << endl;
        c = atoi(s);

        switch (c)
        {
        case 1:
            insert(setElement(counter), &head, &last);
            counter = counter + 1;
            break;
        case 2:
            outputList(&head, &last);
            break;
        case 3:
            char dname[NAME_SIZE];
            cout << "Введите имя: ";
            cin.getline(dname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            delet(dname, &head, &last);
            break;
        case 4:
            char fname[NAME_SIZE];
            cout << "Введите имя: ";
            cin.getline(fname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            find(fname, &head);
            break;
        case 5:
            saveToFile(head);
            break;
        case 6:
            readFromFile(&head, &last);
            break;
        case 7:
            replaceElement(&head, counter);
            gets_s(s);
            break;
        case 8:
            exit(0);
        }
    }
}
Address* setElement(int counter=0)      // Создание элемента и ввод его значений с клавиатуры 
{
    counter = counter + 1;
    Address* temp = new  Address();
    if (!temp)
    {
        cerr << "Ошибка выделения памяти.\n";
        return NULL;
    }
    cout << "Номер строки: " << counter << endl;
    cout << "Введите имя: ";
    cin.getline(temp->name, NAME_SIZE - 1, '\n');
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    cout << "Введите город: ";
    cin.getline(temp->city, CITY_SIZE - 1, '\n');
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}


void replaceElement(Address** phead, int counter) // Функция замены элементов по номеру
{
    int num;
    cout << "Введите номер элемента, который нужно заменить: ";
    cin >> num;
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    Address* current = *phead;
    int currentCounter = 1;
    while (current != NULL && currentCounter != num) // ищем элемент с заданным номером
    {
        current = current->next;
        currentCounter++;
    }
    if (current == NULL) // если элемент не найден, выводим сообщение об ошибке
    {
        cout << "Элемент с номером " << num << " не найден.\n";
        return;
    }
    Address* newElement = setElement(counter); // создаем новый элемент
    if (current->prev != NULL) // если текущий элемент не является первым
    {
        current->prev->next = newElement; // связываем предыдущий элемент с новым
        newElement->prev = current->prev;
    }
    else // если текущий элемент является первым
    {
        *phead = newElement; // новый элемент становится первым
    }
    newElement->next = current->next; // связываем новый элемент со следующим
    if (current->next != NULL)
    {
        current->next->prev = newElement;
    }
    delete current; // удаляем старый элемент
}

void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
    Address* t = *phead;
    int counter = 1;
    while (t)
    {
        cout << "Номер строки: " << counter << endl;
        cout << t->name << ' ' << t->city << endl;
        t = t->next;
        counter++;
    }
    cout << "" << endl;
}

void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени 
{
    struct Address* t = *phead;
    while (t)
    {
        if (!strcmp(name, t->name))  break;
        t = t->next;
    }
    if (!t)
        cerr << "Имя не найдено.\n" << endl;
    else
    {
        if (*phead == t)
        {
            *phead = t->next;
            if (*phead)
                (*phead)->prev = NULL;
            else
                *plast = NULL;
        }
        else
        {
            t->prev->next = t->next;
            if (t != *plast)
                t->next->prev = t->prev;
            else
                *plast = t->prev;
        }
        delete t;
        cout << "Элемент удален.\n" << endl;
    }
}

void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
    Address* t = *phead;
    while (t)
    {
        if (!strcmp(name, t->name)) break;
        t = t->next;
    }
    if (!t)
        cerr << "Имя не найдено.\n" << endl;
    else
        cout << t->name << ' ' << t->city << endl;
}




void findcit(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
    Address* t = *phead;
    while (t)
    {
        if (!strcmp(name, t->city)) break;
        t = t->next;
    }
    if (!t)
        cerr << "Имя не найдено.\n" << endl;
    else
        cout << t->name << ' ' << t->city << endl;
}


void saveToFile(Address* head)     // Сохранение в файл
{
    FILE* fp;
    errno_t err = fopen_s(&fp, "mlist.txt", "wb");
    if (err)
    {
        cerr << "Файл не открывается" << endl;
        exit(1);
    }
    int count = 0;
    Address* temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    fwrite(&count, sizeof(int), 1, fp);  // записываем количество элементов в начало файла
    while (head)
    {
        fwrite(head, sizeof(struct Address), 1, fp);
        head = head->next;
    }
    fclose(fp);
}
void readFromFile(Address** phead, Address** plast)          //Считывание из файла
{
        FILE* fp;
        errno_t err = fopen_s(&fp, "mlist.txt", "rb");
        if (err)
        {
            cerr << "Файл не открывается" << endl;
            exit(1);
        }
        int count = 0;
        fread(&count, sizeof(int), 1, fp);  // считываем количество элементов из начала файла
        cout << "Данные из файла:" << endl;
        for (int i = 0; i < count; i++)
        {
            Address* t = new Address();
            if (!t)
            {
                cerr << "Ошибка выделения памяти" << endl;
                return;
            }
            if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
            cout << "Имя: " << t->name << endl;
            cout << "Город: " << t->city << endl;
            cout << endl;
            delete t;
        }
        fclose(fp);
    }