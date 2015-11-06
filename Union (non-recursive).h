struct Union
{
public:
    Union(int n) { for (int i = 0; i <= n; i++) ancestor.push_back(i); }
    int find(int n) 
    { 
        int anc = n; 
        while (ancestor[anc] != anc) anc = ancestor[anc]; 
        while (ancestor[n] != n) { n = ancestor[n]; ancestor[n] = anc; } 
        return anc; 
    }
    void connect(int x, int y) { ancestor[find(y)] = find(x); }
    bool isConnected(int x, int y) { return find(x) == find(y); }
protected:
    vector<int> ancestor;
};
