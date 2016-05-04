class Date
{
public:
    Date(int y, int m, int d) : y(y), m(m), d(d)
    {}

    int year() const
    { return this->y; }

    int month() const
    { return this->m; }

    int day() const
    { return this->d; }

    std::string toString() const
    {
        stringstream ss;
        ss << this->y << '-' << this->m << '-' << this->d;
        string s;
        ss >> s;
        return s;
    }

    Date nextDay(int delta = 1) const
    {
        time_t tt;
        time(&tt);
        tm *t = localtime(&tt);
        t->tm_mday = this->d;
        t->tm_mon = this->m - 1;
        t->tm_year = this->y - 1900;
        tt = mktime(t) + delta * 24 * 60 * 60;
        tm *a = gmtime(&tt);
        return Date(a->tm_year + 1900, a->tm_mon + 1, a->tm_mday);
    }

protected:
    int y;
    int m;
    int d;
};