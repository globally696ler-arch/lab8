#include "math_utils.h" // Подключаем заголовок с объявлениями наших функций
#include <iostream>

int gcd(int a, int b) // вычисления НОД по алгоритму Евклида
{
    while (b != 0) // пока b != 0, заменяем пару (a, b) на (b, a % b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) // функция вычисления НОК
{
    return (a * b) / gcd(a, b);
}

bool isPerfect(int n) // функция проверки, является ли число совершенным
{
    if (n < 2)
        return false; // числа меньше 2 не могут быть совершенными

    int sum = 0;                // сумма собственных делителей
    for (int i = 1; i < n; ++i) // перебор делителей от 1 до числа-1
    {
        if (n % i == 0)
            sum += i;
    }
    return sum == n; // число совершенно, если сумма делителей равна самому числу
}
int main()
{
    std::cout << gcd(48, 18) << std::endl;
    std::cout << lcm(4, 6) << std::endl;
    std::cout << isPerfect(28) << std::endl;

    return 0;
}