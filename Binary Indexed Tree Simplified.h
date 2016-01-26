class BinaryIndexedTree
{
public:
    BinaryIndexedTree(const int &n) : a(n + 1) {}
    int sum(unsigned n) const { int s = 0; for (; n > 0; n -= -n & n) s += a[n]; return s; }
    int sum(unsigned l, unsigned r) const { return sum(r) - sum(l - 1); }
    void add(unsigned p, const int k) { if (p) for (; p < a.size(); p += -p & p) a[p] += k; }
protected:
    vector<int> a;
};
typedef BinaryIndexedTree FenwickTree;