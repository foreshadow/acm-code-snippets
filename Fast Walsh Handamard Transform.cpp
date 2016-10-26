struct bit_and_tag
{} and_tag;

struct bit_or_tag
{} or_tag;

struct bit_xor_tag
{} xor_tag;

template<typename T> void wht(T &lhs, T &rhs, bit_and_tag)
{ lhs += rhs; }

template<typename T> void wht(T &lhs, T &rhs, bit_or_tag)
{ rhs += lhs; }

template<typename T> void wht(T &lhs, T &rhs, bit_xor_tag)
{ lhs += rhs; rhs = lhs - rhs * 2; }

template<typename T> void iwht(T &lhs, T &rhs, bit_and_tag)
{ lhs -= rhs; }

template<typename T> void iwht(T &lhs, T &rhs, bit_or_tag)
{ rhs -= lhs; }

template<typename T> void iwht(T &lhs, T &rhs, bit_xor_tag)
{ lhs = (lhs + rhs) / 2; rhs = lhs - rhs; }

template<typename RAIt, typename Tag>
void fwht(RAIt first, RAIt last, Tag tag)
{
    if (distance(first, last) > 1) {
        RAIt middle = first + (last - first) / 2;
        fwht(first, middle, tag);
        fwht(middle, last, tag);
        while (middle < last) {
            wht(*first++, *middle++, tag);
        }
    }
}

template<typename RAIt, typename Tag>
void fiwht(RAIt first, RAIt last, Tag tag)
{
    if (distance(first, last) > 1) {
        RAIt middle = first + (last - first) / 2;
        fiwht(first, middle, xor_tag);
        fiwht(middle, last, xor_tag);
        while (middle < last) {
            iwht(*first++, *middle++, tag);
        }
    }
}

template<typename T, typename Tag>
void bit_convolution(T first, T last, T first2, T result, Tag tag)
{
    typedef typename iterator_traits<T>::value_type value_type;
    typedef typename iterator_traits<T>::difference_type difference_type;
    difference_type length = last - first;
    while ((-length & length) ^ length) {
        length += -length & length;
    }
    vector<value_type> buf1(length), buf2(length), buf3(length);
    copy(first, last, buf1.begin());
    copy(first2, first2 + (last - first), buf2.begin());
    fwht(buf1.begin(), buf1.end(), tag);
    fwht(buf2.begin(), buf2.end(), tag);
    transform(buf1.begin(), buf1.end(), buf2.begin(), buf3.begin(), multiplies<value_type>());
    fiwht(buf3.begin(), buf3.end(), tag);
    copy(buf3.begin(), buf3.begin() + (last - first), result);
}
