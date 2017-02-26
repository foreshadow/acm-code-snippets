class Dijkstra
{
    using Int   = int;                  // type of weight
    using Pair  = pair<unsigned, Int>;    // simplification
    
public:
    Dijkstra(unsigned n) : n(n + 1), adj(n + 1)
    {}

    void addEdge(unsigned u, unsigned v, Int w = 1)
    { adj[u].emplace_back(v, w); }
    
    void addUndirectedEdge(unsigned u, unsigned v, Int w = 1)
    { addEdge(u, v, w); addEdge(v, u, w); }
    
    vector<Int> shortestPath(unsigned s)
    {
        vector<Int> d(n, UNREACHABLE);
        priority_queue<Pair, vector<Pair>, greater<Pair>> q;
        q.emplace(s, d[s] = 0);
        while (!q.empty()) {
            Pair p = q.top();
            q.pop();
            unsigned v = p.first;
            if (d[v] >= p.second) {
                for (unsigned i = 0; i < adj[v].size(); i++) {
                    Pair e = adj[v][i];
                    if (d[e.first] > d[v] + e.second) {
                        d[e.first] = d[v] + e.second;
                        q.emplace(d[e.first], e.first);
                    }
                }
            }
        }
        return d;
    }
    
    // different from what defined in <math.h>, update this if you use long long
    static const Int UNREACHABLE = 1000000007; 

protected:
    unsigned n;
    vector<vector<Pair>> adj;
};
