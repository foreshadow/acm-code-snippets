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