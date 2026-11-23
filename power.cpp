#include <iostream>
#include <cmath>   // std::pow
#include <chrono>  // для замера времени
#include <iomanip> // форматирование вывода

// РЕКУРСИВНАЯ версия, быстрое возведение в степень
double powerRecursive(double base, long long exp)
{
    // любое число в степени 0 равно 1
    if (exp == 0)
        return 1.0;

    // Рекурсивный случай 1: нечётная степень
    // Сводим к чётной: a^n = a · a^(n-1)
    if (exp & 1LL) // exp & 1 == 1, если exp нечётное
        return base * powerRecursive(base, exp - 1);

    // Рекурсивный случай 2: чётная степень
    // a^n = (a^(n/2))^2 — считаем половину и возводим её в квадрат
    double half = powerRecursive(base, exp / 2);
    return half * half;
}

// ИТЕРАТИВНАЯ версия того же алгоритма.
// Работает за O(log n) умножений и O(1) памяти (рекурсия тратит стек на глубину ~log n).

double powerIterative(double base, long long exp)
{
    double result = 1.0; // накопитель произведения
    while (exp > 0)
    {
        if (exp & 1LL)      // если текущий бит степени = 1
            result *= base; // «забираем» очередной множитель
        base *= base;       // возводим основание в квадрат
        exp >>= 1;          // переходим к следующему биту
    }
    return result;
}

// ВСТРОЕННАЯ функция std::pow(double, double)
double powerStd(double base, double exp)
{
    return std::pow(base, exp);
}

// Бенчмарк: сколько времени занимает N вызовов каждой функции.
// result объявляем volatile, чтобы компилятор не выбросил вызовы как «бесполезные» (результат ведь нигде не используется)
template <typename Fn>
double benchmark(Fn fn, int iterations, double base, long long exp)
{
    volatile double sink = 0.0; // «приёмник» результата
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i)
        sink = fn(base, exp); // вызов измеряемой функции

    auto end = std::chrono::high_resolution_clock::now();
    (void)sink; // подавляем предупреждение о неиспользуемом sink

    std::chrono::duration<double, std::milli> ms = end - start;
    return ms.count(); // время в миллисекундах
}

int main()
{
    // Проверка корректности на нескольких значениях
    std::cout << std::fixed << std::setprecision(6);

    struct Case
    {
        double base;
        long long exp;
    };
    const Case cases[] = {
        {2.0, 10}, {1.5, 20}, {3.0, 15}, {0.9, 100}, {2.0, 63}};

    std::cout << "Проверка результатов:\n";
    std::cout << "  base    exp   recursive      iterative      std::pow\n";
    for (auto c : cases)
    {
        std::cout << "  " << std::setw(5) << c.base
                  << std::setw(7) << c.exp
                  << std::setw(13) << powerRecursive(c.base, c.exp)
                  << std::setw(15) << powerIterative(c.base, c.exp)
                  << std::setw(15) << powerStd(c.base, (double)c.exp)
                  << "\n";
    }

    // Бенчмарк
    const int N = 5'000'000;
    const double base = 1.0000001; // специально «медленно растущее»
    const long long exp = 1000;    // показатель степени

    double tRec = benchmark(powerRecursive, N, base, exp);
    double tItr = benchmark(powerIterative, N, base, exp);
    double tStd = benchmark(powerStd, N, base, exp);

    std::cout << "\nБенчмарк (" << N << " вызовов, base=" << base
              << ", exp=" << exp << "):\n";
    std::cout << "  recursive : " << tRec << " ms\n";
    std::cout << "  iterative : " << tItr << " ms\n";
    std::cout << "  std::pow  : " << tStd << " ms\n";

    return 0;
}