template<typename T>
void fft(vector<complex<T>> &a, int inv = 1)
{
    for (int i = 1, j = 0; i < a.size() - 1; i++) {
        int s = a.size();
        do {
            j ^= s >>= 1;
        } while (~j & s);
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    for (int d = 0; (1 << d) < a.size(); d++) {
        int hl = 1 << d, l = hl << 1;
        complex<T> u0 = polar(T(1), acos(-1) / hl * inv);
        for (int i = 0; i < a.size(); i += l) {
            complex<T> u = 1;
            for (int j = 0; j < hl; j++) {
                a[i + j] += a[i + j + hl] *= u;
                a[i + j + hl] = a[i + j] - a[i + j + hl] * T(2);
                u *= u0;
            }
        }
    }
}

typedef vector<complex<double>> polynomial;

polynomial convolution(polynomial a, polynomial b)
{
    int n = max(a.size(), b.size());
    while ((-n & n) ^ n) {
        n += -n & n;
    }
    n <<= 1;
    a.resize(n);
    b.resize(n);
    fft(a);
    fft(b);
    polynomial c(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i] / double(n);
    }
    fft(c, -1);
    return c;
}
