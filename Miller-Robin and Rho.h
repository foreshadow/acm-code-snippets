class MathFoward
{
protected:
    static ll mul(ll a, ll b, ll p)
    {
        ll rn = 0, i;
        for(i = 1; i <= b; i <<= 1, a = (a + a) % p)
            if(b & i) rn = (rn + a) % p;
        return rn;
    }
    static ll ksm(ll a, ll b, ll p)
    {
        ll rn = 1;
        for(; b; a = mul(a, a, p), b >>= 1)
            if(b & 1) rn = mul(rn, a, p);
        return rn;
    }
};

class Miller_Robin : public MathFoward
{
public:
    static bool isPrime(ll n)
    {
        if (n == 2)
            return true;
        if (n < 2 || !(n & 1))
            return false;
        ll a, x, y, u = n - 1;
        int t = 0;
        while ((u & 1) == 0)
            t++, u >>= 1;
        for (int i = 0; i < 5; i++)
        {
            a = tester[i];
            if (n <= a)
                continue;
            x = ksm(a, u, n);
            for (int j = 1; j <= t; j++)
            {
                y = mul(x, x, n);
                if (y == 1 && x != 1 && x != n - 1)
                    return false;
                x = y;
            }
            if (x != 1) return false;
        }
        return true;
    }
private:
    static const int tester[5];
};
const int Miller_Robin::tester[] = {2, 3, 5, 7, 641};

class Rho : private Miller_Robin
{
public:
    static vector<int> fact(ll n)
    {
        list.clear();
        rho(n);
        srt(list);
        return list;
    }
private:
    static void rho(ll n)
    {
        if (isPrime(n))
        {
            list.push_back(n);
            return;
        }
        for(; ; )
        {
            int p = 1;
            for (ll x = 1, y = 1, z = rand() + 1; p == 1; )
            {
                y = (mul(y, y, n) + z) % n;
                p = gcd((x - y + n) % n, n);
                x = (mul(x, x, n) + z) % n;
                y = (mul(y, y, n) + z) % n;
            }
            if (p == n) continue;
            rho(p), rho(n / p);
        }
    }
    static vector<int> list;
};
vector<int> Rho::list;