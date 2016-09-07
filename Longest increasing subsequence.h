// nlgn for random access iterator, returns length only
template<typename ForwardIterator>
unsigned longestIncreasingSubsequence(ForwardIterator begin, ForwardIterator end)
{
    vector<typename ForwardIterator::value_type> d;
    while (begin != end)
    {
        // upper_bound if non-decreasing
        auto k = lower_bound(d.begin(), d.end(), *begin);
        if (k == d.end())
            d.push_back(*begin++);
        else
            *k = *begin++;
    }
    return d.size();
}
