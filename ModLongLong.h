template<unsigned long long n>
class ModLongLong // operator %(int, int) is faster
{
    typedef long long ll;
    typedef ModLongLong mll;
    static void exGcd(ll a, ll b, ll &x, ll &y)
    { if (b) { exGcd(b, a % b, y, x);  y -= a / b * x; } else { x = 1; y = 0; } }

public:
    ModLongLong(ll a) : data((a % n + n) % n) {}
    ll toLongLong() const { return data; }
    mll operator +(const mll &b) const { return this->data + b.data; }
    mll operator -(const mll &b) const { return this->data - b.data; }
    mll operator *(const mll &b) const { return this->data * b.data; }
    mll operator /(const mll &b) const
    { ll x = 0, y = 0; exGcd(b.data, n, x, y); x = (x + n) % n; return this->data * x; }
    mll pow(ll b) const
    { mll p = 1; for (mll a = *this; b; a *= a, b >>= 1) if (b & 1) p *= a; return p; }
    mll operator +=(const mll &b) { return *this = *this + b; }
    mll operator -=(const mll &b) { return *this = *this - b; }
    mll operator *=(const mll &b) { return *this = *this * b; }
    mll operator /=(const mll &b) { return *this = *this / b; }
    mll pow_assign(ll b) { return *this = this->pow(b); }

protected:
    ll data;
};

const ll mod = 1000000007ll;

typedef ModLongLong<mod> mll;
