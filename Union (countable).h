struct Union
{
public:
    Union(int n) { for (int i = 0; i <= n; i++) anc.push_back(i), cnt.push_back(1); }
    int find(int x) { /* be careful of stack overflow */ if (anc[x] == x) return x; anc[x] = find(anc[x]); return anc[x]; }
    void connect(int x, int y) { if (isConnected(x, y)) return; int t = count(x); anc[find(x)] = find(y); cnt[find(y)] += t; }
    bool isConnected(int x, int y) { return find(x) == find(y); }
    int count(int x) { return cnt[find(x)]; }
protected:
    vector<int> anc;
    vector<int> cnt;
};