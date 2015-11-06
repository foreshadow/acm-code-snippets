template<unsigned long long n>
class ModLongLong
{
    typedef long long ll;
    typedef ModLongLong mll;
    static void exGcd(ll a, ll b, ll &x, ll &y) { if (b) { exGcd(b, a % b, y, x);  y -= a / b * x; } else { x = 1; y = 0; } }
public:
    ModLongLong(const ll &a) : data((a + n) % n) {}
    ll toLongLong() const { return data; }
    mll friend operator +(const mll &a, const mll &b) { return ModLongLong((a.data + b.data) % n); }
    mll friend operator -(const mll &a, const mll &b) { return ModLongLong((a.data - b.data + n) % n); }
    mll friend operator *(const mll &a, const mll &b) { return ModLongLong((a.data * b.data) % n); }
    mll friend operator /(const mll &a, const mll &b) { ll x = 0, y = 0; exGcd(b.data, n, x, y); x = (x + n) % n; return ModLongLong((a.data * x) % n); }
    mll operator +=(const mll &b) { *this = *this + b; return *this; }
    mll operator -=(const mll &b) { *this = *this - b; return *this; }
    mll operator *=(const mll &b) { *this = *this * b; return *this; }
    mll operator /=(const mll &b) { *this = *this / b; return *this; }
protected:
    ll data;
};

const ll mod = 1000000007ll;

typedef ModLongLong<mod> mll;
