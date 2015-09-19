template<typename T>
class Mapper
{
public:
    Mapper() : m(), n(0) {}
    void clear() { m.clear(); }
    int operator [](const T idx) { if (m.count(idx) == 0) m[idx] = ++n; return m[idx]; }
protected:
    map<T, int> m;
    int n;
};