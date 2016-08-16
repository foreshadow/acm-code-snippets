long long qpow(long long a, long long b, long long c) // a^b % c (a, c < INT_MAX)
{
    long long p = 1;
    while (b)
    {
        if (b & 1)
            p = p * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return p;
}
