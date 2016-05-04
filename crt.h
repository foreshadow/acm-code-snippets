
long long combination(long long n, long long m, long long k = mod)
{
    long long p = 1ll;
    long long q = 1ll;
    for (long long i = 1; i <= m; i++)
    {
        p = p * (n - i + 1) % k;
        q = q * i % k;
    }
    long long x, y;
    exGcd(q, k, x, y);
    x = (x % k + k) % k;
    long long ans = p * x % k;
    return ans;
}

long long lucas(long long n, long long m, long long k = mod)
{
    if (m == 0) return 1ll;
    return lucas(n / k, m / k, k) * combination(n % k, m % k, k) % k;
}

long long crt(const vector<long long> &r, const vector<long long> &p) // x % p = r
{
    long long m = 1;
    long long ans = 0;
    for (unsigned i = 0; i < p.size(); i++)
        m *= p[i];
    for (unsigned i = 0; i < p.size(); i++)
    {
        long long w = m / p[i];
        long long x, y;
        long long d = exGcd(p[i], w, x, y);
        y = (y % (p[i] / d) + p[i] / d) % (p[i] / d);
        ans = (ans + y * w * r[i]) % m;
    }
    return ans;
}