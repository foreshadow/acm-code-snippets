class Joseph // recursive
{
public:
    Joseph(int n, int k) : n(n), k(k) {} // n people exit every k
    idx(int i) { return ext(n, k, i); } // index of the i-th person
private:
    int ext(int n, int k, int i) { return (i == 1 ? (n + k - 1) % n : (ext(n - 1, k, i - 1) + k) % n); }
protected:
    int n;
    int k;
};

// latest version below
// may be similar with the class above
class Joseph
{
public:
    Joseph(unsigned n, unsigned k) : n(n), k(k) {}
    unsigned solve() { return f(n); } // index of the last one, 0-based
private:
    unsigned f(unsigned x) { return x == 1 ? 0 : (f(x - 1) + k) % x; }
protected:
    unsigned n, k;
};
