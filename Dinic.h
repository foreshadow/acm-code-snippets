#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Dinic
{
    const int INFINITE = 1000000000;

    class Edge
    {
    public:
        int u;
        int v;
        int cap;
        int flow;

        bool operator <(const Edge &e)
        {
            return this->u < e.u || (this->u == e.u && this->v < e.v);
        }
    };

public:
    Dinic(int n) : n(n), adj(n), d(n), cur(n)
    {}

    void addEdge(int from, int to, int cap)
    {
        edges.push_back(Edge{from, to, cap, 0});
        edges.push_back(Edge{to, from, 0, 0});
        adj[from].push_back(edges.size() - 2);
        adj[to].push_back(edges.size() - 1);
    }

    int maxFlow(int s, int t)
    {
        int flow = 0;
        while (bfs(s, t))
        {
            cur.assign(cur.size(), 0);
            flow += dfs(s, t, INFINITE);
        }
        return flow;
    }

private:
    bool bfs(int s, int t)
    {
        vector<char> vis;
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        d[s] = 0;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (unsigned i = 0; i < adj[x].size(); i++)
            {
                Edge &e = edges[adj[x][i]];
                if (!vis[e.v] && e.cap > e.flow)
                {
                    vis[e.v] = 1;
                    d[e.v] = d[x] + 1;
                    q.push(e.v);
                }
            }
        }
        return vis[t];
    }

    int dfs(int x, int t, int a)
    {
        if (x == t || a == 0)
            return a;
        int flow = 0;
        for (int &i = cur[x]; i < int(adj[x].size()); i++)
        {
            Edge &e = edges[adj[x][i]];
            if (d[x] + 1 == d[e.v])
            {
                int f = dfs(e.v, t, min(a, e.cap - e.flow));
                if (f > 0)
                {
                    e.flow += f;
                    edges[adj[x][i] ^ 1].flow -= f;
                    flow += f;
                    a -= f;
                    if (a == 0)
                        break;
                }
            }
        }
        return flow;
    }

protected:
    int n;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> d;
    vector<int> cur;
};
