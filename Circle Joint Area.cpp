const long double pi = acosl(-1);

long double dist(long double x1, long double y1, long double x2, long double y2)
{ return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }

long double arcArea(long double ang, long double r)
{ return (ang - sinl(ang)) * r * r / 2; }

long double circlesJointArea(long double x1, long double y1, long double r1, long double x2, long double y2, long double r2)
{
    if (r1 < r2) { swap(x1, x2); swap(y1, y2); swap(r1, r2); }
    long double d = dist(x1, y1, x2, y2);
    if (d + r2 <= r1) return r2 * r2 * pi;
    if (d >= r1 + r2) return 0;
    long double ang1 = acosl((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
    long double ang2 = acosl((d * d + r2 * r2 - r1 * r1) / (2 * d * r2));
    return arcArea(ang1 * 2, r1) + arcArea(ang2 * 2, r2);
}
