template<typename T> using Point = std::pair<T, T>;

template<typename T>
T area2(const Point<T> &p, const Point<T> &q, const Point<T> &r)
{
    return p.first * q.second - p.second * q.first
         + q.first * r.second - q.second * r.first
         + r.first * p.second - r.second * p.first;
}

template<typename T>
bool toRight(const Point<T> &p, const Point<T> &q, const Point<T> &r)
{
    return area2(p, q, r) < 0;
}

template<typename T>
bool lowestTheLeftmost(const Point<T> &a, const Point<T> &b)
{
    return a.second < b.second || (a.second == b.second && a.first < b.first);
}

template<typename T>
bool compareByAzimuth(const Point<T> &a, const Point<T> &b)
{
    return atan2(a.second, a.first) < atan2(b.second, b.first);
}

template<typename T>
T convexHull(T first, T last) // Graham scan
{
    typedef typename T::value_type::first_type val;
    if (first == last)
        return last;
    std::iter_swap(first, std::min_element(first, last, lowestTheLeftmost<val>));
    Point<val> origin = *first;
    for (T i = first; i != last; i++)
    {
        i->first -= origin.first;
        i->second -= origin.second;
    }
    std::sort(++first, last, compareByAzimuth<val>);
    T s = first--;
    if (s == last)
        return s;
    for (T t = next(s); t != last; std::iter_swap(++s, t++))
        while (toRight(*prev(s), *s, *t))
            --s;
    for (T i = first; i != last; i++)
    {
        i->first += origin.first;
        i->second += origin.second;
    }
    return ++s;
}

double cross(const pair<double, double> &p1, const pair<double, double> &p2)
{
    return p1.first * p2.second - p2.first * p1.second;
}

double dot(const pair<double, double> &p1, const pair<double, double> &p2)
{
    return p1.first * p2.first + p1.second * p2.second;
}



p.erase(convexHull(p.begin(), p.end()), p.end());
p.push_back(p.front());
for (int i = 0; i < p.size() - 2; i++) {
    pair<double, double> v1(p[i + 1].first - p[i].first, p[i + 1].second - p[i].second);
    pair<double, double> v2(p[i + 2].first - p[i].first, p[i + 2].second - p[i].second);
    if (abs(cross(v1, v2)) < 1e-9) {
        p.erase(p.begin() + i + 1);
    }
}