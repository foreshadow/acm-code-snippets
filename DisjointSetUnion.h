class DisjointSetUnion
{
public:
    DisjointSetUnion(int n) : a(n + 1)
    { iota(a.begin(), a.end(), 0); }

    int find(int x)
    { return a[x] != x ? a[x] = find(a[x]) : x; }
    
    void join(int x, int y)
    { a[find(y)] = find(x); }

    bool same(int x, int y)
    { return find(x) == find(y); }

protected:
    vector<int> a;
};


// size ver.
class DisjointSetUnion
{
public:
    DisjointSetUnion(int n) : a(n + 1), s(n + 1)
    { for (int i = 0; i <= n; i++) a[i] = i, s[i] = 1; }

    int size(int x)
    { return s[find(x)]; }

    int find(int x)
    { return a[x] != x ? a[x] = find(a[x]) : x; }

    void join(int x, int y)
    { s[find(x)] += s[find(y)]; a[find(y)] = find(x); }

    bool same(int x, int y)
    { return find(x) == find(y); }

protected:
    vector<int> a;
    vector<int> s;
};