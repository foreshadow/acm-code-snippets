inline namespace Infinity
{
inline namespace Container
{
template<typename T>
class Array : public std::vector<T>
{
public:
    Array() : std::vector<T>()
    {}

    Array(unsigned n) : std::vector<T>(n)
    {}

    Array(const std::vector<T> &v) : std::vector<T>(v)
    {}

    void append(const T &x)
    { this->push_back(x); }

    void sort()
    { std::sort(this->begin(), this->end()); }

    template<typename Comp> void sort(const Comp &f)
    { std::sort(this->begin(), this->end(), f); }

    T min() const
    { return *std::min_element(this->begin(), this->end()); }

    T max() const
    { return *std::max_element(this->begin(), this->end()); }
    
    T sum() const
    { return std::accumulate(this->begin(), this->end(), T()); }
};
}
}
