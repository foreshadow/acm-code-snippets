class Spfa
{
    struct Edge { int to; int w; int next; };
public:
    enum { TAIL = -1, UNREACHABLE = 2147483647 };
    Spfa(int n) : n(n), sp(-1), head(vector<int>(n + 1, TAIL)) {}
    int dist(int a, int b) { if (sp != a) bellmanFord(a); return dst[b]; }
    void addEdge(int a, int b, int w) { Edge edge{b, w, head[a]}; head[a] = e.size(); e.push_back(edge); }
private:
    bool bellmanFord(int st)
    {
        used.assign(n + 1, false); oq.assign(n + 1, 0); dst.assign(n + 1, UNREACHABLE); 
        sp = st; used[st] = true; dst[st] = 0; queue<int> q; q.push(st);
        while (!q.empty())
        {
            int top = q.front(); q.pop(); oq[top]++; used[top] = false;
            if (oq[top] > n) return false;
            for (int k = head[top]; k != TAIL; k = e[k].next) if (dst[e[k].to] > dst[top] + e[k].w)
            { dst[e[k].to] = dst[top] + e[k].w; if (!used[e[k].to]) { used[e[k].to] = true; q.push(e[k].to); } }
        }
        return true;
    }
protected:
    const int n; int sp; // last queried source
    vector<bool> used; vector<int> oq; vector<int> head; vector<int> dst; vector<Edge> e;
};