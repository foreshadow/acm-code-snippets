template<typename T>
class Vector;

template<typename T>
class Segment;

template<typename T>
class Point
{
public:
    T x, y;
    Point(T x = T(), T y = T()) : x(x), y(y)
    {}
    Point operator +(const Vector<T> &v) const
    { return Point(x + v.x, y + v.y); }
    Vector<T> operator -(const Point &p) const
    { return Vector<T>(x - p.x, y - p.y); }
    bool operator <(const Point &p) const
    { return x < p.x || (x == p.x && y < p.y); }
    bool operator ==(const Point &p) const
    { return !(*this < p) && !(p < *this); }
    bool operator !=(const Point &p) const
    { return *this < p || p < *this; }
    bool in(Segment<T> s) const
    { Vector<T> v1(*this, s.p1), v2(*this, s.p2);
        return v1.cross(v2) == 0 && v1.dot(v2) < 0;}
};

template<typename T>
class Vector
{
public:
    T x, y;
    Vector(T x = T(), T y = T()) : x(x), y(y)
    {}
    Vector(const Point<T> &p1, const Point<T> &p2 = Point<T>()) : Vector(p2 - p1)
    {}
    Vector operator -() const
    { return Vector(-x, -y); }
    Vector operator +(const Vector &v) const
    { return Vector(x + v.x, y + v.y); }
    Vector operator -(const Vector &v) const
    { return Vector(x - v.x, y - v.y); }
    Vector operator *(T a) const
    { return Vector(x * a, y * a); }
    Vector operator /(T a) const
    { return Vector(x / a, y / a); }
    Vector &operator +=(const Vector& v)
    { return *this = *this + v; }
    Vector &operator -=(const Vector& v)
    { return *this = *this - v; }
    Vector &operator *=(T a)
    { return *this = *this * a; }
    Vector &operator /=(T a)
    { return *this = *this / a; }
    T dot(const Vector &v) const
    { return x * v.x + y * v.y; }
    T cross(const Vector &v) const
    { return x * v.y - y * v.x; }
    T length() const
    { return sqrt(x * x + y * y); }
    T length2() const
    { return x * x + y * y; }
    Vector unit() const
    { T l = length(); if (l == T()) return Vector(); return Vector(x / l, y / l); }
    T angleBetween(const Vector &v) const
    { return acos(dot(v) / length() / v.length()); }
    Vector rotate(T a) const
    { return Vector(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a)); }
};

template<typename T>
class Line
{
public:
    Point<T> p;
    Vector<T> d;
    Line(const Point<T> &p, const Vector<T> &d) : p(p), d(d)
    {}
    Line(const Point<T> &p1, const Point<T> &p2) : p(p1), d(p2 - p1)
    {}
    bool intersect(const Line &l, Point<T> &i) const
    {
        if (d.cross(l.d) == T()) return false;
        i = p + d * (l.d.cross(p - l.p) / d.cross(l.d));
        return true;
    }
};

template<typename T>
class Segment
{
public:
    Point<T> p1, p2;
    Segment(const Point<T> &p1, const Point<T> &p2) : p1(p1), p2(p2)
    {}
    // returns: 0 for don't intersect; 1 for proper intersect; 2 for T intersect; 3 for adjacent; 4 for coline
    int intersect(const Segment &l, Point<T> &i) const
    {
        T c1 = Vector<T>(p1, p2).cross(Vector<T>(p1, l.p1));
        T c2 = Vector<T>(p1, p2).cross(Vector<T>(p1, l.p2));
        T c3 = Vector<T>(l.p1, l.p2).cross(Vector<T>(l.p1, p1));
        T c4 = Vector<T>(l.p1, l.p2).cross(Vector<T>(l.p1, p2));
        T d1 = c1 * c2, d2 = c3 * c4;
        if (d1 > 0 && d2 > 0) return 0;
        if (Vector<T>(p1, p2).cross(Vector<T>(l.p1, l.p2)) == T()) return 4;
        i = p1 + Vector<T>(p1, p2) * (Vector<T>(l.p1, l.p2).cross(p1 - l.p1) / Vector<T>(p1, p2).cross(Vector<T>(l.p1, l.p2)));
        if (d1 == 0 && d2 == 0) return 3;
        if (d1 == 0 || d2 == 0) return 2;
        return 1;
    }
};
