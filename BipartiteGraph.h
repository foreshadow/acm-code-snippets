class BipartiteGraph
{
public:
    BipartiteGraph(unsigned l, unsigned r) : n(l + r), l(l), adj(n)
    {}

    void connect(int u, int v)
    { adj[u].push_back(v); adj[v].push_back(u); }

    int maximumMatching() // hungarian algorithm: bfs version
    {
        vector<int> match(n, -1);
        vector<int> check(n, -1);
        vector<int> prev(n);
        int ans = 0;
        for (int i = 0; i < l; ++i) {
            if (match[i] == -1) {
                queue<int> q;
                q.push(i);
                prev[i] = -1;
                while (q.size()) {
                    int u = q.front();
                    for (int v : adj[u]) {
                        if (check[v] != i) {
                            check[v] = i;
                            q.push(match[v]);
                            if (match[v] >= 0) {
                                prev[match[v]] = u;
                            } else {
                                int x = u, y = v;
                                while (x != -1) {
                                    int t = match[x];
                                    match[x] = y;
                                    match[y] = x;
                                    x = prev[x];
                                    y = t;
                                }
                                goto next;
                            }
                        }
                    }
                    q.pop();
                }
            next:
                if (match[i] != -1) ++ans;
            }
        }
        return ans;
    }

protected:
    int n, l;
    vector<vector<int>> adj;
};
