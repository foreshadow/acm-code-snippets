// from ftiasch
#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1 << 21;

struct Complex
{
    Complex(double x = 0., double y = 0.) : x(x), y(y) {}

    double x, y;
};

Complex operator + (const Complex& a, const Complex& b)
{
    return Complex(a.x + b.x, a.y + b.y);
}

Complex operator - (const Complex& a, const Complex& b)
{
    return Complex(a.x - b.x, a.y - b.y);
}

Complex operator * (const Complex& a, const Complex& b)
{
    return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

Complex a[N], b[N];

const double pi = acos(-1.);

void sincos(double p, double& y, double& x)
{
    y = sin(p);
    x = cos(p);
}

void FFT(Complex P[], int n, int oper)
{
    for (int i = 1, j = 0; i < n - 1; i++) {
        for (int s = n; j ^= s >>= 1, ~j & s;);
        if (i < j) {
            std::swap(P[i], P[j]);
        }
    }
    Complex unit_p0;
    for (int d = 0; (1 << d) < n; d++) {
        int m = 1 << d, m2 = m * 2;
        double p0 = pi / m * oper;
        sincos(p0, unit_p0.y, unit_p0.x);
        for (int i = 0; i < n; i += m2) {
            Complex unit = 1;
            for (int j = 0; j < m; j++) {
                Complex &P1 = P[i + j + m], &P2 = P[i + j];
                Complex t = unit * P1;
                P1 = P2 - t;
                P2 = P2 + t;
                unit = unit * unit_p0;
            }
        }
    }
}
