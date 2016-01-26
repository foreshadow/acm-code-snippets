inline namespace Infinity
{
inline namespace Geometry
{
typedef long double Real;

class Point
{
public:
    Point(Real x = 0, Real y = 0) : x(x), y(y) {}
    Point(const pair<int, int> &p) : x(p.first), y(p.second) {}
    Real x;
    Real y;
};

class Line
{
public:
    Line(Real a, Real b, Real c) : a(a), b(b), c(c) {}
    Line(Point p1, Point p2)
    {
        assert(p1.x != p2.x || p1.y != p2.y);
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = p1.y * (p2.x - p1.x) - p1.x * (p2.y - p1.y);
    }
    Real a;
    Real b;
    Real c;
};

class Circle
{
public:
    Circle(Point center, Real radius) : o(center), r(radius) {}
    Point o;
    Real r;
};

const Real pi = acosl(-1);
// use eps when comparing Reals
const Real eps = 1e-15l;

Real sq(Real a)
{
    return a * a;
}

Real dist(Point a, Point b)
{
    return sqrtl(sq(a.x - b.x) + sq(a.y - b.y));
}

bool parallel(Line l1, Line l2)
{
    return l1.a * l2.b - l1.b * l2.a == 0;
}

Point intersection(Line l1, Line l2)
{
    assert(parallel(l1, l2) == false);
    return Point((l1.b * l2.c - l2.b * l1.c) / (l1.a * l2.b - l2.a * l1.b),
                 (l1.a * l2.c - l2.a * l1.c) / (l2.a * l1.b - l1.a * l2.b));
}

Point footPoint(Point pt, Line ln)
{
    Line pl(ln.b, -ln.a, pt.y * ln.a - pt.x * ln.b);
    return intersection(ln, pl);
}

Real dist(Point pt, Line ln)
{
    return fabsl(ln.a * pt.x + ln.b * pt.y + ln.c) / sqrtl(sq(ln.a) + sq(ln.b));
}

Real arcArea(Real ang, Real r)
{
    return (ang - sinl(ang)) * r * r / 2;
}

Real circlesJointArea(Circle c1, Circle c2)
{
    if (c1.r < c2.r)
        swap(c1, c2);
    Real d = dist(c1.o, c2.o);
    if (d + c2.r <= c1.r)
        return pi * sq(c2.r);
    if (d >= c1.r + c2.r)
        return 0;
    Real ang1 = acosl((d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d * c1.r));
    Real ang2 = acosl((d * d + c2.r * c2.r - c1.r * c1.r) / (2 * d * c2.r));
    return arcArea(2 * ang1, c1.r) + arcArea(2 * ang2, c2.r);
}

} // namespace Geometry
} // namespace Infinity
