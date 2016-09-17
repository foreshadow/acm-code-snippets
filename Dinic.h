class Dinic
{
    const int infinity = 1000000000;

    struct Edge { int u, v, cap, flow; };

public:
    Dinic(int n) : n(n), adj(n), d(n), cur(n)
    {}

    void addEdge(int from, int to, int capacity)
    {
        adj[from].push_back(edges.size());
        edges.push_back(Edge{from, to, capacity, 0});
        adj[to].push_back(edges.size());
        edges.push_back(Edge{to, from, 0, 0});
    }

    int maxFlow(int s, int t)
    {
        int flow = 0;
        while (bfs(s, t)) {
            cur.assign(cur.size(), 0);
            flow += dfs(s, t, infinity);
        }
        return flow;
    }

private:
    bool bfs(int s, int t)
    {
        vector<char> vis(n);
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        d[s] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (unsigned i = 0; i < adj[x].size(); i++) {
                Edge &e = edges[adj[x][i]];
                if (!vis[e.v] && e.cap > e.flow) {
                    vis[e.v] = 1;
                    d[e.v] = d[x] + 1;
                    q.push(e.v);
                }
            }
        }
        return vis[t];
    }

    int dfs(int s, int t, int a)
    {
        if (s == t || a == 0) {
            return a;
        }
        int flow = 0;
        for (int &i = cur[s]; i < int(adj[s].size()); i++) {
            Edge &e = edges[adj[s][i]];
            if (d[s] + 1 == d[e.v]) {
                int f = dfs(e.v, t, min(a, e.cap - e.flow));
                if (f > 0) {
                    e.flow += f;
                    edges[adj[s][i] ^ 1].flow -= f;
                    flow += f;
                    a -= f;
                    if (a == 0) {
                        break;
                    }
                }
            }
        }
        return flow;
    }

protected:
    int n;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> d, cur;
};
