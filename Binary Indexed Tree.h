#include <vector>

#if __cplusplus >= 201103L
template<typename T = int>
#else
template<typename T>
// or:
//typedef int T;
#endif
class BinaryIndexedTree
{
public:
    BinaryIndexedTree(const T &n) { a.resize(n + 1, 0); }
    BinaryIndexedTree(T *begin, T *end) : a(begin, end) {}
    static T lowbit(const T x) { return -x & x; }
    T sum(T n) const { T s = 0; while (n > 0) { s += a[n]; n -= lowbit(n); } return s; }
    T sum(T l, T r) const { return sum(r) - sum(l - 1); }
    void add(unsigned int pos, const T k) { while (pos < a.size()) { a[pos] += k; pos += lowbit(pos); } }
protected:
    vector<T> a;
};

template<typename T>
class vector2d
{
public:
    vector2d(uint x, uint y, T value = T()) : a(x, vector<T>(y, value)) {}
    vector<vector<T> > data() { return a; }
    vector<T> &operator [](uint x) { return a[x]; }
    uint size() const { return a.size(); }
    void resize(uint n, T x = T()) { a.resize(n, x); }
protected:
    vector<vector<T> > a;
};

class BinaryIndexedTree2D
{
public:
    BinaryIndexedTree2D(uint n, uint m) : a(n + 1, m + 1) {}
    static int lowbit(const int x) { return -x & x; }
    void add(uint x, uint y, int k) { for (uint i = x; i < a.size(); i += lowbit(i)) for (uint j = y; j < a[i].size(); j += lowbit(j)) a[i][j] += k; }
    int sum(uint x, uint y) { int s = 0; for (int i = x; i > 0; i -= lowbit(i)) for(int j = y; j > 0; j -= lowbit(j)) s += a[i][j]; return s; }
    int sum(uint x1, uint y1, uint x2, uint y2) { return sum(x2, y2) - sum(x1 - 1, y1 - 1); }
protected:
    vector2d<int> a;
};

typedef BinaryIndexedTree FenwickTree