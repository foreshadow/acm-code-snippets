template<typename T>
class Vector;

template<typename T>
class Point
{
public:
    T x, y, z;
    Point(T x = T(), T y = T(), T z = T()) : x(x), y(y),z(z)
    {}
    Point operator +(const Vector<T> &v) const
    { return Point(x + v.x, y + v.y, z + v.z); }
    Vector<T> operator -(const Point &p) const
    { return Vector<T>(x - p.x, y - p.y, z - p.z); }
};

template<typename T>
class Vector
{
public:
    T x, y, z;
    Vector(T x = T(), T y = T(), T z = T()) : x(x), y(y),z(z)
    {}
    Vector(const Point<T> &p1, const Point<T> &p2 = Point<T>()) : Vector(p2 - p1)
    {}
    Vector operator -() const
    { return Vector(-x, -y, -z); }
    Vector operator +(const Vector &v) const
    { return Vector(x + v.x, y + v.y, z + v.z); }
    Vector operator -(const Vector &v) const
    { return Vector(x - v.x, y - v.y, z - v.z); }
    Vector &operator +=(const Vector& v)
    { return *this = *this + v; }
    Vector &operator -=(const Vector& v)
    { return *this = *this - v; }
    T dot(const Vector &v) const
    { return x * v.x + y * v.y + z * v.z; }
    Vector cross(const Vector &v) const
    { return Vector( y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x ); }
};
