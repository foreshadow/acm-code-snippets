class KnuthMorrisPratt
{
public:
    static vector<int> kmpv(const string &t, const string &p)
    {
        vector<int> f = getFail(p), r;
        for (unsigned i = 0, j = 0; i < t.size(); i++)
        {
            while (j && p[j] != t[i]) j = f[j];
            if (p[j] == t[i]) j++;
            if (j == p.size()) { r.push_back(i - j + 1); j = f[j]; }
        }
        return r;
    }

    static int kmpc(const string &s, const string &t)
    { return kmpv(s, t).size(); }

private:
    static vector<int> getFail(const string &p)
    {
        vector<int> fail(p.size() + 1);
        for (unsigned i = 1; i < p.size(); i++)
        {
            unsigned j = fail[i];
            while (j && p[i] != p[j]) j = fail[j];
            fail[i + 1] = p[i] == p[j] ? j + 1 : 0;
        }
        return fail;
    }
};

// generic ver.
class KnuthMorrisPratt
{
public:
    template<class T1, class T2>
    static vector<int> kmpv(const T1 &t, const T2 &p)
    {
        vector<int> f = getFail(p);
        vector<int> r;
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

    template<class T1, class T2>
    static int kmpc(const T1 &s, const T2 &t)
    { return kmpv(s, t).size(); }

private:
    template<unsigned n> static unsigned size(const char (&)[n])
    { return n - 1; }

    template<class T> static unsigned size(const T &a)
    { return distance(begin(a), end(a)); }

    template<class T> static vector<int> getFail(const T &p)
    {
        vector<int> fail(size(p) + 1);
        for (unsigned i = 1; i < size(p); i++)
        {
            unsigned j = fail[i];
            while (j && p[i] != p[j])
                j = fail[j];
            fail[i + 1] = p[i] == p[j] ? j + 1 : 0;
        }
        return fail;
    }
};
