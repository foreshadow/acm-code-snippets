template<typename T>
class Discretization
{
public:
    Discretization(vector<T> &v) : data(v) { sort(data.begin(), data.end()); data.erase(unique(data.begin(), data.end()), data.end()); }
    Discretization(T *l, T *r) : data(l, r) { sort(data.begin(), data.end()); data.erase(unique(data.begin(), data.end()), data.end()); }
    T &operator [](const int n) const { return data[n]; }
    int indexOf(const T &t) const { return lower_bound(data.begin(), data.end(), t) - data.begin(); }
protected:
    vector<T> data;
};
