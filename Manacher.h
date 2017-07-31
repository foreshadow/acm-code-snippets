class Manacher
{
public:
    Manacher(const string &s) : d(expand(s)), r(d.size())
    {
        int p = 0, mx = 0;
        for (int i = 1; i < int(d.length()) - 1; i++) {
            r[i] = mx > i ? min(r[2 * p - i], mx - i) : 1;
            while (d[i + r[i]] == d[i - r[i]]) { r[i]++; }
            if (i + r[i] > mx) { p = i; mx = i + r[i]; }
        }
    }

    int &operator [](unsigned n)
    { return r[n]; }

private:
    static string expand(const string &str)
    {
        string s("$#");
        for (char c : str) {
            s.push_back(c); s.push_back('#');
        }
        s.push_back('@');
        return s;
    }

protected:
    string d;
    vector<int> r;
};
