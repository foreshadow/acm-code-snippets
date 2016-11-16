class TreeDiameter
{
    struct Edge { int to, next, weight; };
    
public:
    TreeDiameter(unsigned size) : edge(), head(size, -1), maxn(size), smaxn(size), maxid(size), smaxid(size) {}

    void addEdge(int u, int v, int w)
    { edge.push_back({v, head[u], w}); head[u] = edge.size() - 1; edge.push_back({u, head[v], w}); head[v] = edge.size() - 1; }

    unsigned diameter(unsigned root)
    { dfs1(root, -1); dfs2(root, -1); return *max_element(maxn.begin(), maxn.end()); }

private:
    void dfs1(int u, int p)
    {
        maxn[u] = smaxn[u] = 0;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to; if (v == p) { continue; } dfs1(v, u);
            if (smaxn[u] < maxn[v] + edge[i].weight) {
                smaxn[u] = maxn[v] + edge[i].weight; smaxid[u] = v;
                if (smaxn[u] > maxn[u]) { swap(smaxn[u], maxn[u]); swap(smaxid[u], maxid[u]); }
            }
        }
    }

    void dfs2(int u, int p)
    {
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to; if (v == p) { continue; }
            if (v == maxid[u]) {
                if (edge[i].weight + smaxn[u] > smaxn[v]) {
                    smaxn[v] = edge[i].weight + smaxn[u]; smaxid[v] = u;
                    if (smaxn[v] > maxn[v]) { swap(smaxn[v], maxn[v]); swap(smaxid[v], maxid[v]); }
                }
            } else {
                if (edge[i].weight + maxn[u] > smaxn[v]) {
                    smaxn[v] = edge[i].weight + maxn[u]; smaxid[v] = u;
                    if (smaxn[v] > maxn[v]) { swap(smaxn[v], maxn[v]); swap(maxid[v], smaxid[v]); }
                }
            }
            dfs2(v, u);
        }
    }

protected:
    vector<Edge> edge;
    vector<int> head, maxn, smaxn, maxid, smaxid;
};
