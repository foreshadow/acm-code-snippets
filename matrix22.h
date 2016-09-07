template<typename value_type>
class Matrix22 // 2 x 2 version
{
public:
    Matrix22(value_type a11 = value_type(), value_type a12 = value_type(),
           value_type a21 = value_type(), value_type a22 = value_type()) :
        a11(a11), a12(a12), a21(a21), a22(a22)
    {}

    static Matrix22 identity() // a.k.a. unit
    { return Matrix22(1, 0, 0, 1); }

    Matrix22 operator *(const Matrix22 &m) const
    {
        return Matrix22(this->a11 * m.a11 + this->a12 * m.a21,
                      this->a11 * m.a12 + this->a12 * m.a22,
                      this->a21 * m.a11 + this->a22 * m.a21,
                      this->a21 * m.a12 + this->a22 * m.a22);
    }

    Matrix22 operator *=(const Matrix22 &m)
    { return *this = *this * m; }

    Matrix22 pow(unsigned long long b) const
    {
        Matrix22 p = Matrix22::identity();
        for (Matrix22 a = *this; b; a *= a, b >>= 1)
            if (b & 1ll)
                p *= a;
        return p;
    }

    value_type a11;
    value_type a12;
    value_type a21;
    value_type a22;
};
