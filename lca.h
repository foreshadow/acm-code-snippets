class Tree
{
    struct Node { unsigned depth = -1; vector<unsigned> children, parent; };
public:
    Tree() : root(-1) {}

    void addEdge(unsigned u, unsigned v)
    {
        if (u > v) swap(u, v);
        if (nodes.size() <= v) nodes.resize(v + 1);
        nodes[u].children.push_back(v);
        nodes[v].children.push_back(u);
    }

    void initialize(unsigned root)
    {
        this->root = root;
        init_dfs(root, root, 0);
        int log_depth = 1;
        for (unsigned n = nodes.size(); n > 0; n /= 2) log_depth += 1;
        for (int j = 1; j < log_depth; j++) {
            for (int i = 0; i < nodes.size(); i++) {
                int k = nodes[i].parent.size();
                if (k > 0) nodes[i].parent.push_back(nodes[nodes[i].parent[k - 1]].parent[k - 1]);
            }
        }
    }

    unsigned depth(unsigned u) const { return nodes[u].depth; }

    unsigned kth_parent(unsigned u, unsigned k) const
    {
        while (k > 0) {
            unsigned lowbit = -k & k, step = __builtin_ctz(lowbit);
            u = nodes[u].parent[step]; k -= lowbit;
        }
        return u;
    }

    unsigned lca(unsigned u, unsigned v) const
    {
        if (nodes[u].depth > nodes[v].depth) swap(u, v);
        if (nodes[u].depth != nodes[v].depth) v = kth_parent(v, nodes[v].depth - nodes[u].depth);
        for (int i = nodes[u].parent.size() - 1; i >= 0; i--) {
            if (nodes[u].parent[i] != nodes[v].parent[i]) {
                u = nodes[u].parent[i]; v = nodes[v].parent[i];
            }
        }
        return u == v ? u : nodes[u].parent[0];
    }

    unsigned distance(unsigned u, unsigned v) const
    { return nodes[u].depth + nodes[v].depth - nodes[lca(u, v)].depth * 2; }

private:
    void init_dfs(unsigned u, unsigned p, unsigned depth)
    {
        nodes[u].depth = depth;
        nodes[u].parent.push_back(p);
        for (unsigned v : nodes[u].children) {
            if (v != p) {
                init_dfs(v, u, depth + 1);
            }
        }
    }

protected:
    unsigned root;
    vector<Node> nodes;
};
