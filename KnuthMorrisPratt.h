namespace KnuthMorrisPratt
{
template<unsigned n> constexpr unsigned size(const char (&)[n])
{ return n - 1; }

template<class T> unsigned size(const T &a)
{ return std::distance(std::begin(a), std::end(a)); }

template<class T> std::vector<int> getFail(const T &p)
{
    std::vector<int> fail(size(p) + 1);
    for (unsigned i = 1; i < size(p); i++)
    {
        unsigned j = fail[i];
        while (j && p[i] != p[j])
            j = fail[j];
        fail[i + 1] = p[i] == p[j] ? j + 1 : 0;
    }
    return fail;
}

template<class T1, class T2> std::vector<int> kmpv(const T1 &t, const T2 &p)
{
    std::vector<int> f = getFail(p);
    std::vector<int> r;
    for (unsigned i = 0, j = 0; i < size(t); i++)
    {
        while (j && p[j] != t[i])
            j = f[j];
        if (p[j] == t[i])
            j++;
        if (j == size(p))
        {
            r.push_back(i - j + 1);
            j = f[j];
        }
    }
    return r;
}

template<class T1, class T2> int kmpc(const T1 &s, const T2 &t)
{
    return kmpv(s, t).size();
}
} // namespace KnuthMorrisPratt
