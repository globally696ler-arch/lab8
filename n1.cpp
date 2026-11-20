#include <iostream>
#include <cmath>

bool isPrime(int n)
{
    if (n < 2)
        return false; // проверяем, что число больше двух
    for (int i = 2; i <= std::sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    } // исключаем числа делящиеся на что-то, кроме себя и единицы
    return true;
}

int main()
{
    for (int num = 1; num < 20; ++num)
    { // перебираем числа от 1 до 20
        if (isPrime(num))
        {
            std::cout << num << " ";
        }
    }
    std::cout << "\n";
    return 0;
}