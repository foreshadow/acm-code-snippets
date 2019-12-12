
/**
 * ZKWSegmentTree
 * All the query indices should be [first, last), starting from zero is ok.
 * Infinity rearranged from https://www.cnblogs.com/Judge/p/9514862.html
 */
template<typename T = int>
class ZKWSegmentTree
{
public:

    ZKWSegmentTree(int n)
    {
        initialize(n);
    }

    template<typename RAIt>
    void assign(RAIt first, RAIt last)
    {
        initialize(last - first);
        copy(first, last, &sum_[n + 1]), copy(first, last, &min_[n + 1]), copy(first, last, &max_[n + 1]);
        build();
    }

    void add(int x, int delta)
    {
        ++x;
        int t = 0;
        x += n, max_[x] += delta, min_[x] += delta, sum_[x] += delta;
        for (; x > 1; x >>= 1) {
            sum_[x] += delta;
            t = ::min(min_[x], min_[x ^ 1]), min_[x] -= t, min_[x ^ 1] -= t, min_[x >> 1] += t;
            t = ::max(max_[x], max_[x ^ 1]), max_[x] -= t, max_[x ^ 1] -= t, max_[x >> 1] += t;
        }
    }

    void add(int s, int t, int delta)
    {
        ++s;
        int A = 0, lc = 0, rc = 0, len = 1;
        for (s += n - 1, t += n + 1; s ^ t ^ 1; s >>= 1, t >>= 1, len <<= 1) {
            if ((s & 1) ^ 1) add_[s ^ 1] += delta, lc += len, min_[s ^ 1] += delta, max_[s ^ 1] += delta;
            if (t & 1) add_[t ^ 1] += delta, rc += len, min_[t ^ 1] += delta, max_[t ^ 1] += delta;
            sum_[s >> 1] += delta * lc, sum_[t >> 1] += delta * rc;
            A = ::min(min_[s], min_[s ^ 1]), min_[s] -= A, min_[s ^ 1] -= A, min_[s >> 1] += A,
            A = ::min(min_[t], min_[t ^ 1]), min_[t] -= A, min_[t ^ 1] -= A, min_[t >> 1] += A;
            A = ::max(max_[s], max_[s ^ 1]), max_[s] -= A, max_[s ^ 1] -= A, max_[s >> 1] += A,
            A = ::max(max_[t], max_[t ^ 1]), max_[t] -= A, max_[t ^ 1] -= A, max_[t >> 1] += A;
        }
        for (lc += rc; s > 1; s >>= 1) {
            sum_[s >> 1] += delta * lc;
            A = ::min(min_[s], min_[s ^ 1]), min_[s] -= A, min_[s ^ 1] -= A, min_[s >> 1] += A,
            A = ::max(max_[s], max_[s ^ 1]), max_[s] -= A, max_[s ^ 1] -= A, max_[s >> 1] += A;
        }
    }

    int sum(int s, int t)
    {
        ++s;
        int lc = 0, rc = 0, len = 1, ans = 0;
        for (s += n - 1, t += n + 1; s ^ t ^ 1; s >>= 1, t >>= 1, len <<= 1) {
            if ((s & 1) ^ 1) ans += sum_[s ^ 1] + len * add_[s ^ 1], lc += len;
            if (t & 1) ans += sum_[t ^ 1] + len * add_[t ^ 1], rc += len;
            if (add_[s >> 1]) ans += add_[s >> 1] * lc;
            if (add_[t >> 1]) ans += add_[t >> 1] * rc;
        }
        for (lc += rc, s >>= 1; s; s >>= 1) if (add_[s]) ans += add_[s] * lc;
        return ans;
    }

    int min(int s, int t)
    {
        ++s;
        int L = 0, R = 0, ans = 0;
        if (s == t) return query_node(s);
        for (s += n, t += n; s ^ t ^ 1; s >>= 1, t >>= 1) {
            L += min_[s], R += min_[t];
            if ((s & 1) ^ 1) L = ::min(L, min_[s ^ 1]);
            if (t & 1) R = ::min(R, min_[t ^ 1]);
        }
        for (ans = ::min(L, R), s >>= 1; s; s >>= 1) ans += min_[s];
        return ans;
    }

    int max(int s, int t)
    {
        ++s;
        int L = 0, R = 0, ans = 0;
        if (s == t) return query_node(s);
        for (s += n, t += n; s ^ t ^ 1; s >>= 1, t >>= 1) {
            L += max_[s], R += max_[t];
            if ((s & 1) ^ 1) L = ::max(L, max_[s ^ 1]);
            if (t & 1) R = ::max(R, max_[t ^ 1]);
        }
        for (ans = ::max(L, R), s >>= 1; s; s >>= 1) ans += max_[s];
        return ans;
    }

    int operator [](int x)
    {
        return query_node(++x);
    }

private:
    void initialize(int x)
    {
        for (n = x + 2; __builtin_popcount(n) > 1; n += -n & n);
        sum_.resize(n << 1), min_.resize(n << 1), max_.resize(n << 1), add_.resize(n << 1);
    }

    void build()
    {
        for (int i = n - 1; i; --i) {
            sum_[i] = sum_[i << 1] + sum_[i << 1 | 1];
            min_[i] = ::min(min_[i << 1], min_[i << 1 | 1]),
            min_[i << 1] -= min_[i], min_[i << 1 | 1] -= min_[i];
            max_[i] = ::max(max_[i << 1], max_[i << 1 | 1]),
            max_[i << 1] -= max_[i], max_[i << 1 | 1] -= max_[i];
        }
    }

    int query_node(int x)
    {
        int ans = 0;
        for (x += n; x; x >>= 1) ans += min_[x];
        return ans;
    }

protected:
    int n;
    vector<int> sum_, min_, max_, add_;
};
