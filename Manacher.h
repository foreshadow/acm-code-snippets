inline namespace Infinity
{
inline namespace Algorithm
{
inline namespace StringAlgo
{
class Manacher
{
public:
    Manacher(const std::string &s) : 
        d(expand(s)), r(d.size())
    {
        int p = 0;
        int mx = 0;
        for (int i = 1; i < d.length() - 1; i++)
        {
            if (mx > i)
                r[i] = min(r[2 * p - i], mx - i);
            else
                r[i] = 1;
            while (d[i + r[i]] == d[i - r[i]])
                r[i]++;
            if (i + r[i] > mx)
            {
                p = i;
                mx = i + r[i];
            }
        }
    }

    std::string &data()
    { return d; }

    int &operator [](unsigned n)
    { return r[n]; }

private:
    static std::string expand(const std::string &str)
    {
        std::string s("$#");
        s.reserve(str.size() * 2 + 1);
        for (char c : str)
        {
            s.push_back(c);
            s.push_back('#');
        }
        s.push_back('@');
        return s;
    }

protected:
    std::string d;
    std::vector<int> r;
};
} // namespace Infinity::Algorithm::StringAlgo
} // namespace Infinity::Algorithm
} // namespace Infinity