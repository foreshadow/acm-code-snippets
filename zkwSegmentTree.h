template<typename value_type>
class SegmentTree // zkw's, implemented by infinity
{
    typedef unsigned int size_type;
    typedef std::vector<value_type> container_type;

    value_type binary_op(value_type lhs, value_type rhs)
    { return lhs + rhs; } // associativity required

public:
    SegmentTree(size_type n, value_type val = value_type()) :
        m(1 << (32 - __builtin_clz(n + 2))),
        t(container_type(1 << (32 - __builtin_clz(n + 2) + 1), val))
    {
        for (size_type i = this->m - 1; i; i--)
            this->t[i] = binary_op(this->t[i << 1], this->t[i << 1 | 1]);
    }

    template<typename RAIt>
    void assign(RAIt l, RAIt r) // rebuild
    {
        copy(l, r, this->t.begin() + this->m);
        for (size_type i = this->m - 1; i; i--)
            this->t[i] = binary_op(this->t[i << 1], this->t[i << 1 | 1]);
    }

    value_type get(size_type pos) const
    { return this->t[this->m + pos]; }

    void set(size_type pos, value_type x)
    {
        this->t[this->m + pos] = x;
        for (size_type i = (this->m + pos) >> 1; i; i >>= 1)
            this->t[i] = binary_op(this->t[i << 1], this->t[i << 1 | 1]);
    }

    value_type query(size_type l, size_type r) // query [l, r]
    {
//        if (l < 1 || r > t.size() - 2) // [1, 2n-2]
//            throw std::out_of_range("Segment tree query: out of range");
        value_type a = value_type();
        for (l += this->m - 1, r += this->m + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
        {
            if (~l & 1) a = binary_op(a, this->t[l ^ 1]);
            if (r & 1) a = binary_op(a, this->t[r ^ 1]);
        }
        return a;
    }

protected:
    size_type m;
    container_type t;
};
