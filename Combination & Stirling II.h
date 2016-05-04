// Combinatorics

const int mod = 1000000007;

class Combination
{
public:
    Combination(int n, int m = mod) : n(n), m(m), a(new int *[n + 1])
    {
        for (int i = 0; i <= n; i++) a[i] = new int[n + 1];
        for (int i = 0; i <= n; i++) { a[0][i] = 0; a[i][0] = 1; }
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % m;
    }
    int c(int n, int m) { return a[n][m]; }
protected:
    int n;
    int m;
    int **a;
};

class StirlingII
{
    typedef long long ll;
public:
    StirlingII(int n, int m = mod) : n(n), m(m), a(new int *[n + 1])
    {
        for (int i = 0; i <= n; i++) a[i] = new int[n + 1];
        for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) a[i][j] = 0;
        for (int i = 0; i <= n; i++) a[i][1] = a[i][i] = 1;
    }
    int s(int i, int j)
    {
        if (i < j) return 0;
        if (!i || !j) return 0;
        if (a[i][j]) return a[i][j];
        a[i][j] = (s(i - 1, j - 1) + ll(j) * s(i - 1, j)) % m;
        return a[i][j];
    }
protected:
    int n;
    int m;
    int **a;
};