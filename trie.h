class Trie
{
    struct Node
    {
        unsigned p[64];
        int n, k;
        
        unsigned &next(char c)
        { return islower(c) ? p[c - 'a'] : isupper(c) ? p[c - 'A' + 26] : p[c - '0' + 52]; }
    };

public:
    Trie() : nodes(1)
    { nodes.reserve(1000000); }

    void insert(const string &str)
    {
        unsigned id = 0;
        for (unsigned i = 0; i < str.size(); i++) {
            if (nodes[id].next(str[i]) == 0) {
                nodes[id].next(str[i]) = nodes.size();
                nodes.emplace_back();
            }
            ++nodes[id = nodes[id].next(str[i])].n;
        }
        ++nodes[id].k;
    }

    long long solve()
    { return dfs(0, 0); }

private:
    long long dfs(unsigned id, int depth)
    {
        long long r = 1ll * nodes[id].n * (nodes[id].n - 1)
                    + 1ll * nodes[id].k * (nodes[id].k - 1) / 2;
        for (unsigned s : nodes[id].p) {
            if (s) {
                r += dfs(s, depth + 1);
            }
        }
        return r;
    }

protected:
    vector<Node> nodes;
};
