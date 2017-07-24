class MultiplicationLCA
{
    static const int width = 32;

public:
    MultiplicationLCA(const vector<int> &parents) :
        f(parents), d(parents.size()), a(parents.size(), vector<int>(width)), c(parents.size())
    { for (unsigned i = 1; i < parents.size(); i++) { c[parents[i]].push_back(i); } dfs(0); }

    int lca(int x, int y) const
    {
        if (d[x] < d[y]) { swap(x, y); }
        for (int i = width - 1; i >= 0; i--) { if (d[y] <= d[a[x][i]]) { x = a[x][i]; } }
        if (x == y) { return x; }
        for (int i = width - 1; i >= 0; i--) { if (a[x][i] != a[y][i]) { x = a[x][i]; y = a[y][i]; } }
        return a[x][0];
    }

    int depth(int x) const
    { return d[x]; }

private:
    void dfs(int u)
    {
        a[u][0] = f[u];
        for (int i = 1; i < width; i++) { a[u][i] = a[a[u][i - 1]][i - 1]; }
        for (int v : c[u]) { d[v] = d[u] + 1; dfs(v); }
    }

protected:
    vector<int> f, d; vector<vector<int>> a, c;
};
