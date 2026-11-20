import re
from collections import Counter


# Приводит строку к «нормальному» виду для сравнений(приводит к нижнему регистру, оставляет только буквы и цифры(убирает пробелы, знаки препинания)
def normalize(text: str) -> str:
    return re.sub(r"[^a-zа-яё0-9]", "", text.lower())


# Проверяет, является ли строка палиндромом
def is_palindrome(text: str) -> bool:
    cleaned = normalize(text)
    return cleaned == cleaned[::-1]


# Проверяет, являются ли две строки анаграммами
def is_anagram(a: str, b: str) -> bool:
    # Если после нормализации строки разной длины, они точно не могут быть анаграммами
    a_norm, b_norm = normalize(a), normalize(b)
    if len(a_norm) != len(b_norm):
        return False

    # Сравниваем частотные словари символов
    return Counter(a_norm) == Counter(b_norm)


# Считает количество слов в строке
def count_words(text: str) -> int:
    # \w+ — одна или более букв/цифр/подчёркиваний подряд, re.UNICODE (по умолчанию в Python 3) учитывает кириллицу.
    return len(re.findall(r"\w+", text))


# ---------- Демонстрация работы модуля ----------
if __name__ == "__main__":
    print("Палиндром:")
    print(
        "  'А роза упала на лапу Азора' ->", is_palindrome("А роза упала на лапу Азора")
    )
    print("  'racecar'                   ->", is_palindrome("racecar"))
    print("  'hello'                     ->", is_palindrome("hello"))

    print("\nАнаграмма:")
    print("  'Listen' / 'Silent' ->", is_anagram("Listen", "Silent"))
    print("  'Кот' / 'Ток'       ->", is_anagram("Кот", "Ток"))
    print("  'hello' / 'world'   ->", is_anagram("hello", "world"))

    print("\nПодсчёт слов:")
    print("  'Hello, world!'     ->", count_words("Hello, world!"))
    print("  '  Привет   мир  '  ->", count_words("  Привет   мир  "))
    print("  ''                  ->", count_words(""))
