namespace Infinity
{
namespace LinearAlgebra
{
class Vector
{
    typedef long double Real;
public:
    Real x;
    Real y;
    Vector(Real x, Real y) : x(x), y(y) {}
    Real length() const { return sqrtl(x * x + y * y); }
    Vector unit() const { return Vector(x / length(), y / length()); }
    Vector transpose() const { return Vector(y, x); }
    Vector left() const { return Vector(-y, x); }
    Vector right() const { return Vector(y, -x); }
    Vector operator -() const { return Vector(-x, -y); }
    Vector operator +(const Vector &v) const { return Vector(x + v.x, y + v.y); }
    Vector operator -(const Vector &v) const { return *this + -v; }
    Vector operator *(Real r) const { return Vector(x * r, y * r); }
    Vector operator /(Real r) const { assert(r != 0); return *this * (1 / r); }
    friend ostream &operator <<(ostream &os, const Vector& v) { return os << v.x << " " << v.y; }
};
} // namespace Infinity::LinearAlgebra
} // namespace Infinity