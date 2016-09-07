// with -std=c++11 -O2 opened, function object would not be too slow
template<typename value_type>
class SegmentTree // zkw's, implemented by infinity
{
    typedef unsigned int size_type;
    typedef std::vector<value_type> container_type;
    typedef std::function<value_type(value_type, value_type)> binary_op;

public:
    SegmentTree(size_type n, value_type default_value = value_type(),
                binary_op op = std::plus<int>()) :
        m(1 << (32 - __builtin_clz(n + 2))),
        t(container_type(1 << (32 - __builtin_clz(n + 2) + 1), default_value)),
        d(default_value), op(op)
    { this->build(); }

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
        // do not support query with l > r
        if (l < 1 || r > t.size() - 2 || l > r) // [1, 2n-2] available
            throw std::out_of_range("Segment tree query: out of range");
        value_type a = this->d;
        for (l += this->m - 1, r += this->m + 1; l ^r ^ 1; l >>= 1, r >>= 1)
        {
            if (~l & 1) a = this->op(a, this->t[l ^ 1]);
            if (r & 1) a = this->op(a, this->t[r ^ 1]);
        }
        return a;
    }

protected:
    size_type m; // offset of the first value in t
    container_type t; // segment tree stored with heap structure
    value_type d; // default value
    binary_op op; // binary operation
};
