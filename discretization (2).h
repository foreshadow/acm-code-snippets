template<typename T>
void discretization(T first, T last)
{
    typedef typename iterator_traits<T>::value_type value_type;
    vector<value_type> b(first, last);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    while (first < last) {
        *first = lower_bound(b.begin(), b.end(), *first) - b.begin() + 1;
        ++first;
    }
}
