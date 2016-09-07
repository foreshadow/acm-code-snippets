template<typename T>
class Real
{
public:
    Real(T value = T()) : value(value)
    {}
//    operator T() const
//    { return value; }
    Real operator -() const
    { return -value; }
    Real operator +(Real r) const
    { return value + r.value; }
    Real operator -(Real r) const
    { return value - r.value; }
    Real operator *(Real r) const
    { return value * r.value; }
//    Real operator /(Real r) const
//    { return value / r.value; }
    Real &operator +=(Real r)
    { return *this = *this + r; }
    Real &operator -=(Real r)
    { return *this = *this - r; }
    Real &operator *=(Real r)
    { return *this = *this * r; }
//    Real &operator /=(Real r)
//    { return *this = *this / r; }
    bool operator <(Real r) const
    { return value < r.value; }
    bool operator >(Real r) const
    { return r < *this; }
    bool operator <=(Real r) const
    { return !(r < *this); }
    bool operator >=(Real r) const
    { return !(*this < r); }
    bool operator ==(Real r) const
    { return !(*this < r) && !(r < *this); }
    bool operator !=(Real r) const
    { return *this < r || r < *this; }

protected:
    T value;
};

template<>
class Real<float>
{
    static constexpr const float eps = 1e-5F;

public:
    Real(float value = float()) : value(value)
    {}
//    operator float() const
//    { return value; }
    Real operator -() const
    { return -value; }
    Real operator +(Real r) const
    { return value + r.value; }
    Real operator -(Real r) const
    { return value - r.value; }
    Real operator *(Real r) const
    { return value * r.value; }
    Real operator /(Real r) const
    { return value / r.value; }
    Real &operator +=(Real r)
    { return *this = *this + r; }
    Real &operator -=(Real r)
    { return *this = *this - r; }
    Real &operator *=(Real r)
    { return *this = *this * r; }
    Real &operator /=(Real r)
    { return *this = *this / r; }
    bool operator <(Real r) const
    { return value + eps < r.value; }
    bool operator >(Real r) const
    { return r < *this; }
    bool operator <=(Real r) const
    { return !(r < *this); }
    bool operator >=(Real r) const
    { return !(*this < r); }
    bool operator ==(Real r) const
    { return !(*this < r) && !(r < *this); }
    bool operator !=(Real r) const
    { return *this < r || r < *this; }

protected:
    float value;
};

template<>
class Real<double>
{
    static constexpr const double eps = double(1e-10L);

public:
    Real(double value = double()) : value(value)
    {}
//    operator double() const
//    { return value; }
    Real operator -() const
    { return -value; }
    Real operator +(Real r) const
    { return value + r.value; }
    Real operator -(Real r) const
    { return value - r.value; }
    Real operator *(Real r) const
    { return value * r.value; }
    Real operator /(Real r) const
    { return value / r.value; }
    Real &operator +=(Real r)
    { return *this = *this + r; }
    Real &operator -=(Real r)
    { return *this = *this - r; }
    Real &operator *=(Real r)
    { return *this = *this * r; }
    Real &operator /=(Real r)
    { return *this = *this / r; }
    bool operator <(Real r) const
    { return value + eps < r.value; }
    bool operator >(Real r) const
    { return r < *this; }
    bool operator <=(Real r) const
    { return !(r < *this); }
    bool operator >=(Real r) const
    { return !(*this < r); }
    bool operator ==(Real r) const
    { return !(*this < r) && !(r < *this); }
    bool operator !=(Real r) const
    { return *this < r || r < *this; }

protected:
    double value;
};

template<>
class Real<long double>
{
    static constexpr const long double eps = 1e-15L;

public:
    Real(long double value = double()) : value(value)
    {}
//    operator long double() const
//    { return value; }
    Real operator -() const
    { return -value; }
    Real operator +(Real r) const
    { return value + r.value; }
    Real operator -(Real r) const
    { return value - r.value; }
    Real operator *(Real r) const
    { return value * r.value; }
    Real operator /(Real r) const
    { return value / r.value; }
    Real &operator +=(Real r)
    { return *this = *this + r; }
    Real &operator -=(Real r)
    { return *this = *this - r; }
    Real &operator *=(Real r)
    { return *this = *this * r; }
    Real &operator /=(Real r)
    { return *this = *this / r; }
    bool operator <(Real r) const
    { return value + eps < r.value; }
    bool operator >(Real r) const
    { return r < *this; }
    bool operator <=(Real r) const
    { return !(r < *this); }
    bool operator >=(Real r) const
    { return !(*this < r); }
    bool operator ==(Real r) const
    { return !(*this < r) && !(r < *this); }
    bool operator !=(Real r) const
    { return *this < r || r < *this; }

protected:
    long double value;
};
