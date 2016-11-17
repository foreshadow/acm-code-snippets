template<unsigned n>
class Matrix : public vector<vector<long long>>
{
    static const int mod = 100000007;

public:
    Matrix(const vector<vector<long long>> &vv = vector<vector<long long>>()) :
        vector<vector<long long>>(vv)
    { resize(n); for (unsigned i = 0; i < n; i++) { (*this)[i].resize(n); } }

    static Matrix<n> unit()
    { Matrix<n> r; for (unsigned i = 0; i < n; i++) { r[i][i] = 1; } return r; }

    Matrix<n> operator *(const Matrix<n> &m) const
    { Matrix<n> r; for (unsigned i = 0; i < n; i++) {
      for (unsigned j = 0; j < n; j++) { for (unsigned k = 0; k < n; k++) {
      r[i][j] = (r[i][j] + (*this)[i][k] * m[k][j] % mod) % mod; } } } return r; }

    Matrix<n> operator *=(const Matrix<n> &m)
    { return *this = *this * m; }

    Matrix<n> pow(unsigned long long x) const
    { Matrix r = Matrix::unit(), a = *this; while (x) { if (x & 1) { r *= a; } a *= a; x >>= 1; } return r; }

    void print()
    { for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { cout << setw(4) << (*this)[i][j]; } cout << endl; } }
};

int main()
{
    Matrix<7> base({
        {1, 1, 1, 1, 1, 0, 1},
        {0, 1, 2, 3, 4, 0, 4},
        {0, 0, 1, 3, 6, 0, 6},
        {0, 0, 0, 1, 4, 0, 4},
        {0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 1, 1},
    });
    for (int t = getint(); t; t--) {
        int n = getint(), a = getint(), b = getint();
        Matrix<7> rec({{1, 2, 4, 8, 16, a, b}});
        printf("%lld\n", (rec * base.pow(n - 1))[0][5]);
    }
    vector<vector<long long>> vv{{1, 2}};
    return 0;
}
