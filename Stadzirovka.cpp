#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

/*

Команда для сборки g++ -o Stadzirovka Stadzirovka.cpp
Команда для вызова программы ./Stadzirovka <подставить один или два аргумента, например ./Stadzirovka 50 100 или ./Stadzirovka 50>

Результаты тестов

Через char

Terminate called after throwing an instance of ‘std::length_error’
what (): cannot create std ::vector larger than max_size()
Aborted (core dumped)

Через long long

Sieve of Eratosthenes: Found 32428773 prime numbers in 40043 milliseconds


Через int

Start from: 1
Ends with: 622337203
Sieve of Eratosthenes: Found 32428773 prime numbers in 15095 milliseconds

Start from: 1
Ends with: 622337203
Sieve of Eratosthenes: Found 32428773 prime numbers in 14780 milliseconds

Start from: 1
Ends with: 622337203
Sieve of Eratosthenes: Found 32428773 prime numbers in 14752 milliseconds

Start from: 1
Ends with: 622337203
Sieve of Eratosthenes: Found 32428773 prime numbers in 15037 milliseconds

Start from: 1
Ends with: 622337203
Sieve of Eratosthenes: Found 32428773 prime numbers in 15004 milliseconds

Start from: 1
Ends with: 622337203
Sieve of Eratosthenes: Found 32428773 prime numbers in 14960 milliseconds

Через bool

Start from: 1
Ends with: 622337203
Sieve of Eratosthenes: Found 32428773 prime numbers in 38897 milliseconds

Программа выдает количество найденных простых чисел, времяв затраченное на поиск, а также начало и конец диапазона, заданные при вызове (для контроля выполнения программы).

*/



// Функция для поиска простых чисел методом Решета Эратосфена
void findPrimesBySieveOfEratosthenes(int start, int end) {
    auto start_time = std::chrono::steady_clock::now();
    std::vector<bool> isPrime(end + 1, true); // Используем тип bool для оптимизации памяти
    isPrime[0] = isPrime[1] = false; // 0 и 1 не являются простыми числами
    for (int p = 2; p * p <= end; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= end; i += p) {
                isPrime[i] = false; // Обозначаем составные числа
            }
        }
    }
    std::vector<int> primes;
    for (int i = start; i <= end; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    auto end_time = std::chrono::steady_clock::now();
    std::cout << "Sieve of Eratosthenes: Found " << primes.size() << " prime numbers in "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()
              << " milliseconds" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " <end_number> [start_number=1]" << std::endl;
        return 1;
    }

    long long start = 1; // Начало диапазона по умолчанию
    long long end = std::stoll(argv[1]); // Преобразование первого аргумента в конец диапазона

    if (argc == 3) {
        start = std::stoll(argv[2]); // Преобразование второго аргумента в начало диапазона
    }

    if (start > end) {
        std::swap(start, end); // Меняем местами, если start больше end
    }

    if (start < 1 || end < 1) {
        std::cerr << "Error: Numbers must be positive integers." << std::endl;
        return 1;
    }

    std::cout << "Start from: " << start << std::endl; // Добавленная строка "Start from"
    std::cout << "Ends with: " << end << std::endl; // Добавленная строка "Ends with"

    findPrimesBySieveOfEratosthenes(start, end); // Поиск простых чисел методом Решета Эратосфена

    return 0;
}
