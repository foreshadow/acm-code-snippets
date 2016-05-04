long long pow_mod(long long a, long long p, long long n)
{
    if (p == 0)
        return 1;
    long long ans = pow_mod(a, p / 2, n);
    ans = ans * ans % n;
    if (p % 2 == 1)
        ans = ans * a % n;
    return ans;
}