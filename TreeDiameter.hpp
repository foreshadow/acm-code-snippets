int diameter(const AdjacencyList &adj, int r)
{
    function<pair<int, int>(int, int)> dfs = [&](int u, int p) {
        vector<pair<int, int>> vp;
        for (int v : adj[u]) {
            if (v != p) {
                vp.push_back(dfs(v, u));
            }
        }
        auto it = max_element(vp.begin(), vp.end());
        if (it != vp.end()) {
            ++(it->first);
            return *it;
        } else {
            return pair<int, int>{0, u};
        }
    };

    return dfs(dfs(r, -1).second, -1).first;
}
