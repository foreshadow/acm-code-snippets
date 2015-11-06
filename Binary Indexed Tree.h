#include <vector>

class BinaryIndexedTree
{
public:
    BinaryIndexedTree(const int &n) { a.resize(n + 1, 0); }
    BinaryIndexedTree(int *begin, int *end) : a(begin, end) {}
    static int lowbit(const int x) { return -x & x; }
    int sum(int n) const { int s = 0; while (n > 0) { s += a[n]; n -= lowbit(n); } return s; }
    int sum(int l, int r) const { return sum(r) - sum(l - 1); }
    void add(unsigned int pos, const int k) { while (pos < a.size()) { a[pos] += k; pos += lowbit(pos); } }
protected:
    vector<int> a;
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
