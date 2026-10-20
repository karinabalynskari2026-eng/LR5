// Лабораторна робота № 5.4
// Варіант 1

#include <iostream>
#include <cmath>

using namespace std;

// 5) Ітераційний спосіб (для контролю)
double S0(const int K, const int N)
{
    double s = 0;
    for (int i = K; i <= N; i++)
        s += (1. * i * i) / (1. * K * K + 1. * N * N);
    return s;
}

// 1) Рекурсивний спуск, параметр i спадає
double S1(const int K, const int N, const int i, double t)
{
    t = t + (1. * i * i) / (1. * K * K + 1. * N * N);
    if (i <= K)
        return t;
    else
        return S1(K, N, i - 1, t);
}

// 2) Рекурсивний спуск, параметр i зростає
double S2(const int K, const int N, const int i, double t)
{
    t = t + (1. * i * i) / (1. * K * K + 1. * N * N);
    if (i >= N)
        return t;
    else
        return S2(K, N, i + 1, t);
}

// 3) Рекурсивний підйом, параметр i спадає
double S3(const int K, const int N, const int i)
{
    if (i < K)
        return 0;
    else
        return (1. * i * i) / (1. * K * K + 1. * N * N) + S3(K, N, i - 1);
}

// 4) Рекурсивний підйом, параметр i зростає
double S4(const int K, const int N, const int i)
{
    if (i > N)
        return 0;
    else
        return (1. * i * i) / (1. * K * K + 1. * N * N) + S4(K, N, i + 1);
}

int main()
{
    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;

    cout << "(rec down --) S1 = " << S1(K, N, N, 0) << endl;
    cout << "(rec down ++) S2 = " << S2(K, N, K, 0) << endl;
    cout << "(rec up --)   S3 = " << S3(K, N, N)    << endl;
    cout << "(rec up ++)   S4 = " << S4(K, N, K)    << endl;
    cout << "(iter)        S0 = " << S0(K, N)       << endl;

    return 0;
}