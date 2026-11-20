#include <iostream>
#include <string>

int sumDigits(int n) // функция вычисления суммы цифр числа
{
    if (n < 10)
        return n;                      // если число однозначное, то сумма его цифр — это само число
    return n % 10 + sumDigits(n / 10); // последняя цифра n % 10 плюс сумма цифр оставшейся части n / 10
}
std::string reverseString(const std::string &s)
{
    if (s.length() <= 1)
        return s;                             // пустая строка или строка из одного символа уже является перевёрнутой
    return reverseString(s.substr(1)) + s[0]; // переворачиваем строку без первого символа, а затем в конец добавляем его
}

bool isPalindrome(const std::string &s) // проверка строки на палиндром
{
    if (s.length() <= 1)
        return true; // пустая строка или строка из одного символа — палиндром
    if (s[0] != s.back())
        return false; // если первый и последний символы не совпадают — это не палиндром
    return isPalindrome(s.substr(1, s.length() - 2));
}

int binarySearch(int arr[], int target, int low, int high) // Бинарный поиск
{
    if (low > high)
        return -1;              // границы пересеклись — элемент не найден
    int mid = (low + high) / 2; // Находим середину текущего диапазона
    if (arr[mid] == target)     // Если средний элемент равен искомому, то возвращаем его индекс
        return mid;
    if (arr[mid] < target)
        return binarySearch(arr, target, mid + 1, high); // Если средний элемент меньше искомого, ищем в правой половине массива
    return binarySearch(arr, target, low, mid - 1);      // Иначе средний элемент больше искомого, ищем в левой половине массива
}
int main()
{
    std::cout << sumDigits(12345) << "\n";
    std::cout << reverseString("Python") << "\n";
    std::cout << isPalindrome("racecar") << "\n";

    int arr[] = {1, 2, 3, 4, 5}; // Массив должен быть отсортирован для корректной работы binarySearc
    std::cout << binarySearch(arr, 3, 0, 4) << "\n";

    return 0;
}