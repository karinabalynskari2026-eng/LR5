// Лабораторна робота № 5.5
// Варіант 1

#include <iostream>

using namespace std;

// Повертає суму цифр числа n.
// depth - глибина рекурсії (кількість рекурсивних викликів, що не є умовою зупинки)
int f(const long long n, int &depth)
{
    if (n == 0)
        return 0;                       // умова закінчення рекурсії
    else
    {
        depth++;                        // ще один рівень рекурсії
        return n % 10 + f(n / 10, depth);
    }
}

int main()
{
    long long n;
    cout << "n = "; cin >> n;

    int depth = 0;
    int sum = f(n, depth);

    cout << "Сума цифр = " << sum << endl;
    cout << "Глибина рекурсії = " << depth << endl;

    return 0;
}