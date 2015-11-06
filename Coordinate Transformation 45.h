template<typename T>
class CoordinateTransformation45
{
    typedef pair<T, T> ptt;
public:
    CoordinateTransformation45(int maxn) : n(maxn) {}
    ptt convert(const ptt &p) { return ptt(p.first + p.second, p.second - p.first + n); }
    ptt convert(const T x, const T y) { return convert(ptt(x, y)); }
protected:
    int n;
};