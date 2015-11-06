class SegmentTree
{
public:
    SegmentTree(const int n) : n(n), minimum(new int[4 * n]), maximum(new int[4 * n]) {}
    inline int size() { return n; }
    void make_tree(const int a[], const int i = 1, const int l = 0, int r = -1)
    {
        if (r == -1) r += n;
        if (l == r) { minimum[i] = a[l]; maximum[i] = a[r]; return; }
        make_tree(a, left(i), l, (l + r) / 2);
        make_tree(a, right(i), (l + r) / 2 + 1, r);
        minimum[i] = std::min(minimum[left(i)], minimum[right(i)]);
        maximum[i] = std::max(maximum[left(i)], maximum[right(i)]);
    }
    int min(const int begin, const int end, const int i = 1, const int l = 0, int r = -1) const
    {
        if (r == -1) r += n;
        if (begin <= l && r <= end) return minimum[i];
        if (r < begin || end < l) return maxint;
        return std::min(min(begin, end, left(i), l, (l + r) / 2), min(begin, end, right(i), (l + r) / 2 + 1, r));
    }
    int max(const int begin, const int end, const int i = 1, const int l = 0, int r = -1) const
    {
        if (r == -1) r += n;
        if (begin <= l && r <= end) return maximum[i];
        if (r < begin || end < l) return -maxint;
        return std::max(max(begin, end, left(i), l, (l + r) / 2), max(begin, end, right(i), (l + r) / 2 + 1, r));
    }
    void add(const int pos, const int inc, const int i = 1, const int l = 0, int r = -1)
    {
        if (r == -1) r += n;
        if (l == r) { minimum[i] += inc; maximum[i] += inc; return; }
        if (pos < l || r < pos) return;
        add(pos, inc, left(i), l, (l + r) / 2);
        add(pos, inc, right(i), (l + r) / 2 + 1, r);
        minimum[i] = std::min(minimum[left(i)], minimum[right(i)]);
        maximum[i] = std::max(maximum[left(i)], maximum[right(i)]);
    } // not tested
private:
    static const int maxint = 2147483647;
    static int left(int i) { return 2 * i; }
    static int right(int i) { return 2 * i + 1; }
protected:
    const int n;
    int *minimum;
    int *maximum;
};

