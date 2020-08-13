class Tarjan
{
public:
    Tarjan(AdjacencyList &adj) :
        adj(adj), n(adj.size()), id(0),
        dfn(n), low(n), vis(n), wcc(n), color(n)
    {}

    // strongly connected components
    vector<int> &scc()
    {
        for (int i = 0; i < n; i++) {
            if (!wcc[i]) {
                dfs(i);
            }
        }
        return color;
    }

private:
    void dfs(int u)
    {
        dfn[u] = low[u] = ++id;
        wcc[u] = vis[u] = true;
        s.push(u);
        for (int v : adj[u]) {
            if (dfn[v] == 0){
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (vis[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            vis[u] = false ;
            color[u] = u;
            while (s.top() != u) {
                color[s.top()] = u;
                vis [s.top()] = false;
                s.pop();
            }
            s.pop();
        }
    }

protected:
    AdjacencyList &adj;
    int n, id;
    stack<int> s;
    vector<int> dfn, low, vis, wcc, color;
};
