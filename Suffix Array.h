template<typename T> // sa[1..n]:0..n-1; rank[0..n-1]:1..n; height[2..n]:0..n-1;
void manberMyers(T s, vector<int> &sa, vector<int> &rank, vector<int> &height)
{
    s.push_back(typename T::value_type());
    int n = s.size();
    int m = 256;
    vector<int> a(n), b(n), xy(n), c(n + m);
    sa.assign(n, 0);
    rank.assign(n, 0);
    height.assign(n, 0);
    int *x = a.data(), *y = b.data();
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (int i = n - k; i < n; i++) y[p++] = i;
        for (int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
        for (int i = 0; i < n; i++) xy[i] = x[y[i]];
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[xy[i]]++;
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--c[xy[i]]] = y[i];
        swap(x, y); p = 1; x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n) break;
        m = p;
    }
    int k = 0;
    for (int i = 1; i < n; i++) rank[sa[i]] = i;
    for (int i = 0; i < n - 1; height[rank[i++]] = k) {
        if (k) k--;
        int j = sa[rank[i] - 1];
        while (s[i + k] == s[j + k]) k++;
    }
}

class ManberMyers
{
public:
    vector<int> sa, rank, height;

    template<typename T> // sa[1..n]:0..n-1; rank[0..n-1]:1..n; height[2..n]:0..n-1;
    ManberMyers(T s) : sa(), rank(), height()
    {
        s.push_back(typename T::value_type());
        int n = s.size();
        int m = 256;
        vector<int> a(n), b(n), xy(n), c(n + m);
        sa.assign(n, 0);
        rank.assign(n, 0);
        height.assign(n, 0);
        int *x = a.data(), *y = b.data();
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
        for (int k = 1; k <= n; k <<= 1) {
            int p = 0;
            for (int i = n - k; i < n; i++) y[p++] = i;
            for (int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
            for (int i = 0; i < n; i++) xy[i] = x[y[i]];
            for (int i = 0; i < m; i++) c[i] = 0;
            for (int i = 0; i < n; i++) c[xy[i]]++;
            for (int i = 1; i < m; i++) c[i] += c[i - 1];
            for (int i = n - 1; i >= 0; i--) sa[--c[xy[i]]] = y[i];
            swap(x, y); p = 1; x[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
            if (p >= n) break;
            m = p;
        }
        int k = 0;
        for (int i = 1; i < n; i++) rank[sa[i]] = i;
        for (int i = 0; i < n - 1; height[rank[i++]] = k) {
            if (k) k--;
            int j = sa[rank[i] - 1];
            while (s[i + k] == s[j + k]) k++;
        }
    }
};

