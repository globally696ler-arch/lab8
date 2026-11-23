#include <iostream>
#include <string>
#include <limits>
#include "recursive_utils.h" // Подключаем ваш новый модуль!

using namespace std;

// Вспомогательная функция для очистки потока ввода
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    int choice;

    do
    {
        cout << "\n=========== ГЛАВНОЕ МЕНЮ ===========\n";
        cout << "1. Сумма цифр числа (рекурсия)\n";
        cout << "2. Переворот строки (рекурсия)\n";
        cout << "3. Проверка на палиндром\n";
        cout << "4. Бинарный поиск в массиве\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        if (cin.fail())
        {
            clearInput();
            cout << "Ошибка ввода! Введите число.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "Введите число: ";
            cin >> n;
            cout << "Сумма цифр = " << sumDigits(n) << "\n";
            break;
        }
        case 2:
        {
            string s;
            cout << "Введите строку: ";
            cin >> s;
            cout << "Реверс: " << reverseString(s) << "\n";
            break;
        }
        case 3:
        {
            string s;
            cout << "Введите строку: ";
            cin >> s;
            cout << (isPalindrome(s) ? "Палиндром" : "Не палиндром") << "\n";
            break;
        }
        case 4:
        {
            // Массив должен быть отсортирован! (как в вашем комментарии)
            int arr[] = {1, 2, 3, 4, 5};
            int target;
            cout << "Массив: {1, 2, 3, 4, 5}\n";
            cout << "Введите искомое число: ";
            cin >> target;

            int idx = binarySearch(arr, target, 0, 4);
            if (idx != -1)
                cout << "Элемент найден на индексе: " << idx << "\n";
            else
                cout << "Элемент не найден\n";
            break;
        }
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный пункт меню.\n";
        }
    } while (choice != 0);

    return 0;
}