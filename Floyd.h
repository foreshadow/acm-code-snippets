class Floyd
{
    enum { UNREACHABLE = 2147483647 };
public:
    Floyd(unsigned n) : d(n, vector<int>(n, UNREACHABLE))
    {}

    void addEdge(unsigned u, unsigned v, int w) // directed
    { d[u][v] = w; }

    void solve()
    {
        for (unsigned k = 0; k < d.size(); k++)
            for (unsigned i = 0; i < d.size(); i++)
                for (unsigned j = 0; j < d.size(); j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    int dist(unsigned u, unsigned v)
    { return d[u][v]; }

protected:
    vector<vector<int>> d;
};
