class SparseTable
{
public:
    template<typename T> SparseTable(T first, T last) :
        d(last - first + 1)
    {
        int i = 1;
        while (first != last) d[i++].push_back(*first++);
        for (int j = 1; (1 << j) < i; ++j) for (int k = 1; k + (1 << (j - 1)) < i; ++k)
            d[k].push_back(min(d[k][j - 1], d[k + (1 << (j - 1))][j - 1]));
    }

    int rmq(int l, int r)
    {
        ++l, ++r;
//        int k = 31 - __builtin_clz(r - l + 1);
        int k = 0;
        while (1 << (k + 1) <= r - l + 1) k++;
        return min(d[l][k], d[r - (1 << k) + 1][k]);
    }

protected:
    vector<vector<int> > d;
};
