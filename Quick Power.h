ll qpow(ll a, ll b, ll c) // a^b % c (a, b, c < INT_MAX)
{
    ll p = 1;
    while (b)
    {
        if (b & 1)
            p = (p * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return p;
}
