#include <iostream>

long long factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1); // факториал: число умноженное на себя -1
}
long long factorialIter(int n)
{
    long long result = 1; // числа быстро растут, используем long long
    for (int i = 1; i <= n; ++i)
    {
        result *= i; // факториал: умножение числа от одного до числа
    }
    return result;
}

int main() // вывод результатов для двух вариантов решения
{
    std::cout << factorial(5) << "\n";
    std::cout << factorialIter(5) << "\n";
    return 0;
}