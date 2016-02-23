//template<typename Integer = int>
class Fraction
{
    typedef int Integer;
public:
    Integer p;
    Integer q;
    Fraction(Integer p = 0, Integer q = 1) : p(p), q(q) {}
    Fraction operator -() const
    { return Fraction(-p, q); }
    Fraction reciprocal() const
    { assert(p != 0); return Fraction(q, p); }
    Fraction operator +(const Fraction &fr) const
    { return Fraction(p * fr.q + fr.p * q, q * fr.q); }
    Fraction operator -(const Fraction &fr) const
    { return *this + -fr; }
    Fraction operator *(const Fraction &fr) const
    { return Fraction(p * fr.p, q * fr.q); }
    Fraction operator /(const Fraction &fr) const
    { return *this * fr.reciprocal(); }
    Fraction &operator +=(const Fraction &fr)
    { return *this = *this + fr; }
    Fraction &operator -=(const Fraction &fr)
    { return *this = *this - fr; }
    Fraction &operator *=(const Fraction &fr)
    { return *this = *this * fr; }
    Fraction &operator /=(const Fraction &fr)
    { return *this = *this / fr; }
    bool operator <(const Fraction& fr) const
    { return p * fr.q < q * fr.p; }
    bool operator >(const Fraction& fr) const
    { return fr < *this; }
    bool operator <=(const Fraction& fr) const
    { return !(fr < *this); }
    bool operator >=(const Fraction& fr) const
    { return !(*this < fr); }
    bool operator ==(const Fraction& fr) const
    { return !(*this < fr) && !(fr < *this); }
    bool operator !=(const Fraction& fr) const
    { return *this < fr || fr < *this; }
    string toString() const
    { return to_string(p) + "/" + to_string(q); }
};