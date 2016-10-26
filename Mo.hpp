class Mo
{
    struct Query
    {
        unsigned l, r, qid, gid;
        Query(unsigned l, unsigned r, unsigned qid, unsigned gid) :
            l(l), r(r), qid(qid), gid(gid)
        {}
        bool operator <(const Query &q) const
        { return gid != q.gid ? gid < q.gid : r < q.r; }
    };

public:
    Mo(unsigned size) : n(size), gsize(sqrt(n))
    {}

    template<typename Index, typename Value, typename Function1, typename Function2>
    void query(vector<pair<Index, Index>> &queries, vector<Value> &ans,
               Function1 insert, Function2 remove)
    {
        vector<Query> que;
        for (const auto &p : queries) {
            que.emplace_back(p.first, p.second, que.size(), p.first / gsize);
        }
        sort(que.begin(), que.end());
        unsigned l = 1;
        unsigned r = 0;
        Value ca = 0;
        ans.resize(queries.size());
        for (const Query &q : que) {
            while (l > q.l) {
                ca += insert(--l - 1); // -1 on partial_sum
            }
            while (l < q.l) {
                ca += remove(l++ - 1); // -1 on partial_sum
            }
            while (r < q.r) {
                ca += insert(++r);
            }
            while (r > q.r) {
                ca += remove(r--);
            }
            ans[q.qid] = ca;
        }
    }

protected:
    unsigned n;
    unsigned gsize;
};

// Codeforces 617E. XOR and Favorite Number

int main(int, char *[])
{
    int n = getint(), m = getint(), k = 0;
    vector<int> a = getints(n + 1), s(n + 1);
    vector<long long> f(1 << 20), ans(m);
    vector<pair<int, int>> q = getpairs(m);
    swap(k, a[0]);
    ++f[0];
    partial_sum(a.begin(), a.end(), s.begin(), [](int a, int b) {
        return a ^ b;
    });
    Mo(n).query(q, ans, [&](int i) {
        int r = f[s[i] ^ k];
        f[s[i]]++;
        return r;
    }, [&](int i) {
        f[s[i]]--;
        return -f[s[i] ^ k];
    });
    writelns(ans);
    return 0;
}
