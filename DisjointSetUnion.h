class DisjointSetUnion
{
public:
    DisjointSetUnion(int n) : a(n + 1), s(n + 1, 1)
    { for (int i = 0; i <= n; i++) a[i] = i; } // iota(a.begin(), a.end(), 0);

    int size(int x)
    { return s[find(x)]; }

    void join(int x, int y)
    { if (!same(x, y)) { s[find(x)] += s[find(y)]; a[find(y)] = find(x); } }

    bool same(int x, int y)
    { return find(x) == find(y); }
    
private:
    int find(int x)
    { return a[x] != x ? a[x] = find(a[x]) : x; }
    
protected:
    vector<int> a;
    vector<int> s;
};
