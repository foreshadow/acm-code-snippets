// object oriented
// be careful of memory usage

class SegmentTreeNode
{
public:
    SegmentTreeNode(int l, int r, int min = maxint, int max = -maxint) :
        left(NULL), right(NULL), minimum(min), maximum(max), interval_l(l), interval_r(r) {}
    int minimum_of(int begin, int end)
    {
        if (begin <= interval_l && interval_r <= end) return minimum;
        if (interval_r < begin || end < interval_l) return maxint;
        return min(this->left->minimum_of(begin, end), this->right->minimum_of(begin, end));
    }
    int maximum_of(int begin, int end)
    {
        if (begin <= interval_l && interval_r <= end) return maximum;
        if (interval_r < begin || end < interval_l) return -maxint;
        return max(this->left->maximum_of(begin, end), this->right->maximum_of(begin, end));
    }
    static SegmentTreeNode *make_tree(int a[], int begin, int end)
    {
        if (begin == end) return new SegmentTreeNode(begin, end, a[begin], a[end]);
        SegmentTreeNode *node = new SegmentTreeNode(begin, end);
        node->left = make_tree(a, begin, (begin + end) / 2);
        node->right = make_tree(a, (begin + end) / 2 + 1, end);
        node->minimum = min(node->left->minimum, node->right->minimum);
        node->maximum = max(node->left->maximum, node->right->maximum);
        return node;
    }
protected:
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    int minimum;
    int maximum;
    int interval_l;
    int interval_r;
private:
    static const int maxint = 2147483647;
};
