class BinaryIndexedTree
{
public:
    BinaryIndexedTree(const int n) { a.resize(n+1, 0); }
    BinaryIndexedTree(int *begin, int *end) : a(begin, end) {}
    static int lowbit(const int x) { return -x & x; }
    int sum(int n) const { int s = 0; while (n > 0) { s += a[n]; n -= lowbit(n); } return s; }
    int sum(int l, int r) const { return sum(r) - sum(l-1); }
    void add(unsigned int pos, const int k) { while (pos < a.size()) { a[pos] += k; pos += lowbit(pos); } }
protected:
    vector<int> a;
};
