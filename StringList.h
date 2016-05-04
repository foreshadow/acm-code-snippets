class StringList : public vector<string>
{
public:
    static StringList getstrings(unsigned n)
    {
        StringList list;
        list.reserve(n);
        for (unsigned i = 0; i < n; i++)
            list.push_back(getstr());
        return list;
    }

    string join(const string &s = string())
    {
        string t = this->front();
        for (auto i = this->begin() + 1; i != this->end(); i++)
            t.append(s).append(*i);
        return t;
    }
};
