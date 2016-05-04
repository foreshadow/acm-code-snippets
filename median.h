template<typename T> typename T::value_type median(T first, T last)
{
    assert(first <= last);
    assert(std::is_sorted(first, last));
    if (first + 1 == last)
        return *first;
    if ((last - first) % 2)
        return (median(first + 1, last) + median(first, last - 1)) / 2;
    else
        return *(first + (last - first) / 2);
}