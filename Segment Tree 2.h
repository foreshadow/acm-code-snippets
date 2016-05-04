inline namespace Infinity
{
inline namespace DataStructure
{
class SegmentTreeNodeBase
{
protected:
    SegmentTreeNodeBase(unsigned a, unsigned b) :
        lint(a), rint(b)
    { }

    bool leaf() const
    { return lint == rint; }

    bool inside(unsigned a, unsigned b) const
    { return a <= lint && rint <= b; }

    bool outside(unsigned a, unsigned b) const
    { return b < lint || rint < a; }

    bool partial(unsigned a, unsigned b) const
    { return !inside(a, b) && !outside(a, b); }

    unsigned lint;
    unsigned rint;
};

class SegmentTreeNode : public SegmentTreeNodeBase
{
    typedef long long Integer;
    static const Integer INTEGER_MAX = LLONG_MAX;
    static const Integer INTEGER_MIN = LLONG_MIN;
public:
    SegmentTreeNode(unsigned a, unsigned b) :
        SegmentTreeNodeBase(a, b), left(nullptr), right(nullptr), mind(Integer()), maxd(Integer())
    {
        if (a < b)
        {
            left = new SegmentTreeNode(a, (a + b) / 2);
            right = new SegmentTreeNode((a + b) / 2 + 1, b);
        }
    }

    template<typename DataContainer>
    SegmentTreeNode(unsigned a, unsigned b, const DataContainer &c) :
        SegmentTreeNode(a, b)
    { if (leaf()) mind = maxd = c[a]; else update(); }

    bool add(unsigned p, Integer d)
    {
        if (outside(p, p)) return false;
        if (leaf()) { mind += d; maxd += d; }
        else if (left->add(p, d) + right->add(p, d) > 0) update();
        else return false;
        return true;
    }

    Integer min(unsigned a, unsigned b) const
    {
        if (outside(a, b)) return INTEGER_MAX;
        if (inside(a, b)) return mind;
        return std::min(left->min(a, b), right->min(a, b));
    }

    Integer max(unsigned a, unsigned b) const
    {
        if (outside(a, b)) return INTEGER_MIN;
        if (inside(a, b)) return maxd;
        return std::max(left->max(a, b), right->max(a, b));
    }

private:
    void update()
    {
        mind = std::min(left->mind, right->mind);
        maxd = std::max(left->maxd, right->maxd);
    }

protected:
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    Integer mind;
    Integer maxd;
};

class SegmentTree : public SegmentTreeNode
{
public:
    SegmentTree(unsigned n) :
        SegmentTreeNode(0, n)
    { }
    template<typename DataContainer>
    SegmentTree(unsigned n, const DataContainer &data) :
        SegmentTreeNode(0, n, data)
    { }
};
}
}
