class Prime
{
public:
    Prime(int n)
    {
        set<int> c;
        for (int i = 2; i <= n; i++)
        {
            if (c.count(i) == 0)
            {
                d.push_back(i);
                for (int j = i + i; j <= n; j += i)
                    c.insert(j);
            }
        }
    }
    int &operator [](unsigned n)
    { return d[n]; }

protected:
    vector<int> d;
} prime(100000);