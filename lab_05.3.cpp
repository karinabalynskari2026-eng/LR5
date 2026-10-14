// Лабораторна робота № 5.3
// Варіант 1

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

double z(const double x);

int main()
{
    double kp, kk;
    int n;

    cout << "kp = "; cin >> kp;
    cout << "kk = "; cin >> kk;
    cout << "n  = "; cin >> n;

    double dk = (kk - kp) / n;

    // ширина рядка: 1 + (1+8+2) + (1+12+2) = 27
    const string line(27, '-');

    cout << fixed << endl;
    cout << line << endl;
    cout << "|" << " " << setw(8)  << "k"    << " |"
                << " " << setw(12) << "result" << " |"
                << endl;
    cout << line << endl;

    for (int i = 0; i <= n; i++)
    {
        double k = kp + i * dk;     // так уникаємо накопичення похибки
        double res = z(2 * k + 1) - z(2 * k - 1) * z(2 * k - 1) + sqrt(z(k));

        cout << "|" << " " << setw(8)  << setprecision(3) << k   << " |"
                    << " " << setw(12) << setprecision(5) << res << " |"
                    << endl;
    }
    cout << line << endl;

    return 0;
}

double z(const double x)
{
    if (abs(x) >= 1)
        return (cos(x) + 1) / (sin(x) * sin(x) + exp(x));
    else
    {
        double S = 0;
        int j = 0;
        double a = 1;           // перший доданок (j = 0)
        S = a;
        do
        {
            j++;
            double R = -x / j;  // рекурентне співвідношення
            a *= R;
            S += a;
        } while (j < 7);
        return S / exp(x);      // множник 1/e^x
    }
}