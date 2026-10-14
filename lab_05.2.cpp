// Лабораторна робота № 5.2
// Варіант 1

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

void S(const double x, const double eps, int &n, double &s);
void A(const double x, const int n, double &a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    // ширини колонок: x = 7, ln(...) = 15, S = 10, n = 5
    // ширина рядка: 1 + (7+3) + (15+3) + (10+3) + (5+3) = 50
    const string line(50, '-');

    cout << fixed << endl;
    cout << line << endl;
    cout << "|" << " " << setw(7)  << "x"               << " |"
                << " " << setw(15) << "ln((x+1)/(x-1))" << " |"
                << " " << setw(10) << "S"               << " |"
                << " " << setw(5)  << "n"               << " |"
                << endl;
    cout << line << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);

        cout << "|" << " " << setw(7)  << setprecision(2) << x                       << " |"
                    << " " << setw(15) << setprecision(5) << log((x + 1) / (x - 1)) << " |"
                    << " " << setw(10) << setprecision(5) << s                       << " |"
                    << " " << setw(5)  << n                                          << " |"
                    << endl;
        x += dx;
    }
    cout << line << endl;

    return 0;
}

void S(const double x, const double eps, int &n, double &s)
{
    n = 0;
    double a = 1 / x;       // перший доданок (n = 0)
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    s *= 2;                 // множник 2 перед сумою
}

void A(const double x, const int n, double &a)
{
    double R = (2.0 * n - 1) / ((2.0 * n + 1) * x * x);
    a *= R;
}