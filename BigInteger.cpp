template<unsigned base>
class BigInteger
{
public:
    unsigned len() const
    { return a.size(); }

    unsigned &operator [](unsigned pos) // iterator fails if reallocation happens
    { expand(pos + 1); return a[pos]; }

    BigInteger &operator +=(BigInteger &b)
    { expand(b.len()); for (unsigned i = 0; i < len(); i++) { a[i] += b[i]; } carry(); return *this; }

    BigInteger &operator *=(unsigned x) //       (v) overflow?
    { for (unsigned i = 0; i < len(); i++) { a[i] *= x; } carry(); return *this; }

    bool operator <(const BigInteger &b)
    { return len() != b.len() ? len() < b.len() : lexicographical_compare(a.rend() - len(), a.rend(), b.a.rend() - len(), b.a.rend()); }

    unsigned mod(unsigned m)
    { long long x = 0; for (int i = len() - 1; i >= 0; i--) { x = (x * base + a[i]) % m; } return x; }

    void carry()
    { for (unsigned i = 0; i < len(); i++) { if (int t = a[i] / base) { (*this)[i + 1] += t; a[i] -= base * t; } } }

private:
    void expand(unsigned n)
    { if (n > a.size()) { a.resize(n); } }

protected:
    vector<unsigned> a;
};
