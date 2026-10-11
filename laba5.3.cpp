
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x)
{
    if (abs(x) >= 1)
    {
        return (sin(x) + 1) / (sin(x) + cos(x));
    }
    else
    {
        double a = x;
        double s = a;

        for (int i = 1; i <= 8; i++)
        {
            double R = pow(x, 2) / ((2.0 * i) * (2.0 * i + 1));
            a *= R;
            s += a;
        }

        return s;
    }
}

int main()
{
    double tp, tk, t, dt, y;
    int n;

    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = "; cin >> n;

    if (n <= 0 || tp >= tk)
    {
        cout << "Incorrect input" << endl;
        return 1;
    }

    dt = (tk - tp) / n;

    cout << fixed << setprecision(6);

    cout << "---------------------------------" << endl;
    cout << "|" << setw(12) << "t" << "|" << setw(18) << "y" << "|" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 0; i <= n; i++)
    {
        t = tp + i * dt;

        y = f(pow(t, 2)) + 2 * f(2 * t + 1);

        cout << "|" << setw(12) << t
            << "|" << setw(18) << y << "|" << endl;
    }

    cout << "---------------------------------" << endl;

    return 0;
}
