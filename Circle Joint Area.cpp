typedef long double Real;

const Real pi = acosl(-1);

Real dist(Real x1, Real y1, Real x2, Real y2)
{ return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }

Real arcArea(Real ang, Real r)
{ return (ang - sinl(ang)) * r * r / 2; }

Real circlesJointArea(Real x1, Real y1, Real r1, Real x2, Real y2, Real r2)
{
    if (r1 < r2) { swap(x1, x2); swap(y1, y2); swap(r1, r2); }
    Real d = dist(x1, y1, x2, y2);
    if (d + r2 <= r1) return r2 * r2 * pi;
    if (d >= r1 + r2) return 0;
    Real ang1 = acosl((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
    Real ang2 = acosl((d * d + r2 * r2 - r1 * r1) / (2 * d * r2));
    return arcArea(ang1 * 2, r1) + arcArea(ang2 * 2, r2);
}
