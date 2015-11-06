#include <vector>

template<typename T>
class vector2d
{
public:
    vector2d(int x, int y, T value = T()) : mydata(x, vector<T>(y, value)) {}
    vector<vector<T> > data() { return mydata; }
    vector<T> &operator [](int x) { return mydata[x]; }
    int size() const { return mydata.size(); }
protected:
    vector<vector<T> > mydata;
};

template<typename T>
class vector3d
{
public:
    vector3d(int x, int y, int z, T value = T()) : mydata(x, vector2d<T>(y, z, value)) {}
    vector<vector2d<T> > data() { return mydata; }
    vector2d<T> &operator [](int x) { return mydata[x]; }
    int size() const { return mydata.size(); }
protected:
    vector<vector2d<T> > mydata;
};
