int eulerPhi(int n)
{
    int m = int(sqrt(n + 0.5));
    int ans = n;
    for (int i = 2; i <= m; i++)
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        ans = ans / n * (n - 1);
    return ans;
}

vector<int> phiList(unsigned n)
{
    static vector<int> p(n + 1);
    p[1] = 1;
    for (int i = 2; i <= n; i++)
        if (p[i] == 0)
            for (int j = i; j <= n; j += i)
            {
                if (p[j] == 0)
                    p[j] = j;
                p[j] = p[j] / i * (i - 1);
            }
    return p;
}
