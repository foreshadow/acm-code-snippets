
template<typename T>
class Polynomial : protected std::vector<T>
{
public:
    Polynomial(unsigned n) : std::vector<T>(n)
    {}

    Polynomial(const initializer_list<T> &l) : std::vector<T>(l)
    {}

    static Polynomial pow(T base, unsigned n)
    {
        Polynomial p(n);
        T a = 1;
        for (unsigned i = 0; i < n; i++)
            p[i] = a, a *= base;
        return p;
    }

    static Polynomial generate(unsigned n, unsigned k = 1)
    {
        Polynomial p(n * k + 1);
        for (unsigned i = 0; i <= n * k; i += n)
            p[i] = 1;
        return p;
    }

    Polynomial conv(const Polynomial &g) const
    {
        Polynomial c(this->size() + g.size() - 1);
        for (unsigned i = 0; i < this->size(); i++)
            for (unsigned j = 0; j < g.size(); j++)
                c[i + j] += this->at(i) * g.at(j);
        return c;
    }

    Polynomial invo(unsigned n) const
    {
        Polynomial p = *this;
        for (unsigned i = 1; i < n; i++)
            p = p.conv(*this);
        return p;
    }

    T &operator [](unsigned pos)
    {
        return this->vector<T>::operator [](pos);
    }

    Polynomial operator *(const Polynomial &g) const
    {
        return this->conv(g);
    }

    Polynomial operator ^(unsigned n) const
    {
        return this->invo(n);
    }

#ifdef _GLIBCXX_STRING
    std::string toString() const
    {
        std::string s;
        s.push_back('[');
        for (typename std::vector<T>::const_iterator i = this->cbegin(); i != this->cend(); i++)
        {
            if (i != this->cbegin())
                s.push_back(',');
            s.append(to_string(*i));
        }
        s.push_back(']');
        return s;
    }
#endif
};