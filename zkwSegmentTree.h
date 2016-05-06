template<typename value_type>
class SegmentTree // zkw's, implemented by infinity
{
protected:
    typedef unsigned int size_type;
    typedef std::vector<value_type> container_type;    

    virtual value_type op(value_type lhs, value_type rhs) const = 0;

public:
    SegmentTree(size_type n, value_type default_value = value_type()) :
        m(1 << (32 - __builtin_clz(n + 2))),
        t(container_type(1 << (32 - __builtin_clz(n + 2) + 1), default_value)),
        d(default_value)
    {} // may need build() in derived class constructor

    void build()
    {
        for (size_type i = this->m - 1; i; i--)
            this->t[i] = this->op(this->t[i << 1], this->t[i << 1 | 1]);
    }

    template<typename RAIt>
    void assign(RAIt l, RAIt r)
    {
        copy(l, r, this->t.begin() + this->m);
        this->build(); // rebuild
    }

    value_type get(size_type pos) const
    { return this->t[this->m + pos]; }

    void set(size_type pos, value_type x)
    {
        this->t[this->m + pos] = x;
        for (size_type i = (this->m + pos) >> 1; i; i >>= 1)
            this->t[i] = this->op(this->t[i << 1], this->t[i << 1 | 1]);
    }

    value_type query(size_type l, size_type r) const // query [l, r]
    {
        if (l < 1 || r > t.size() - 2 || l > r) // [1, 2n-2] available
            throw std::out_of_range("Segment tree query: out of range");
        value_type a = this->d;
        for (l += this->m - 1, r += this->m + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
        {
            if (~l & 1) a = this->op(a, this->t[l ^ 1]);
            if (r & 1) a = this->op(a, this->t[r ^ 1]);
        }
        return a;
    }

protected:
    size_type m;
    container_type t;
    value_type d;
};

template<typename value_type>
class SegmentTreeMin : public SegmentTree<value_type>
{
public:
    SegmentTreeMin(typename SegmentTree<value_type>::size_type n) :
        SegmentTree<value_type>(n, std::numeric_limits<value_type>::max())
    { this->build(); }

    value_type op(value_type lhs, value_type rhs) const
    { return lhs < rhs ? lhs : rhs; }
};

template<typename value_type>
class SegmentTreeMax : public SegmentTree<value_type>
{
public:
    SegmentTreeMax(typename SegmentTree<value_type>::size_type n) :
        SegmentTree<value_type>(n, std::numeric_limits<value_type>::min())
    { this->build(); }

    value_type op(value_type lhs, value_type rhs) const
    { return lhs > rhs ? lhs : rhs; }
};
