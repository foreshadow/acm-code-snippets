// Infinity on Jul 24, 2017

#include <bits/stdc++.h>

using namespace std;

inline namespace Infinity
{
#define define_pair(classname, x, y) struct classname { int x; int y; \
    classname(int x = 0, int y = 0) : x(x), y(y) {} };
#define define_triple(classname, x, y, z) struct classname { int x; int y; int z; \
    classname(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {} };
#define less_than(classname) bool operator <(ConstRef<classname> lhs, ConstRef<classname> rhs)
#define bool_lambda(type) [](const type &lhs, const type &rhs)

inline namespace Constant
{
constexpr const int eof         = EOF;
constexpr const int maxint      = INT_MAX;
constexpr const long long maxll = LLONG_MAX;
constexpr const double eps      = DBL_EPSILON;
} // namespace Infinity::Constant

inline namespace TypeDefine
{
using uint  = unsigned int;
using ll    = long long int;
using llong = long long int;
using ull   = unsigned long long int;
using ld    = long double;
template<typename T> using ConstRef = const T &;
template<typename T = int> using Pair = pair<T, T>;
template<typename T = int> using PairList = vector<Pair<T>>;
template<typename T = vector<int>> using Iter = typename T::iterator;
} // namespace Infinity::TypeDefine

inline namespace Miscelleneous
{
inline constexpr int ctoi(const char c)
{ return c - '0'; }

inline constexpr char itoc(const int n)
{ return n + '0'; }

inline int dtoi(const double d)
{ return round(d); }

template<typename T, typename P> inline T ceil(T a, P b)
{ return ::ceil(double(a) / b); }

template<typename T, typename P> inline T floor(T a, P b)
{ return ::floor(double(a) / b); }

template<typename T> inline constexpr bool in(T x, T l, T r)
{ return l <= x && x <= r; }

template<typename T> inline constexpr T tristate(int val, T nag, T zero, T pos)
{ return val > 0 ? pos : val < 0 ? nag : zero; }

template<class T> inline int size(const T &a)
{ return a.size(); }

template<class T> inline void sort(T &a)
{ sort(a.begin(), a.end()); }

template<class T1, class T2> inline void sort(T1 &a, T2 comp)
{ sort(a.begin(), a.end(), comp); }

template<class T1, typename T2> inline int lbound(const T1 &a, const T2 k)
{ return lower_bound(a.begin(), a.end(), k) - a.begin(); }

template<class T1, typename T2> inline int ubound(const T1 &a, const T2 k)
{ return upper_bound(a.begin(), a.end(), k) - a.begin(); }

template<class T1, class T2> inline int count(T1 &a, T2 k)
{ return ubound(a, k) - lbound(a, k); }

template<class T> inline void unique_erase(T &a)
{ a.erase(unique(a.begin(), a.end()), a.end()); }

template<typename T> inline void clear(T &a)
{ memset(a, 0, sizeof a); }

template<typename T> T gcd(T a, T b)
{ while (b) { T t = a % b; a = b; b = t; } return a; }

template<typename T> T lcm(T a, T b)
{ return a / gcd(a, b) * b; }

long long qpow(long long a, long long b, long long c)
{ return b ? qpow(a * a % c, b >> 1, c) * (b & 1 ? a : 1) % c : 1; }

// find (x, y) s.t. a x + b y = gcd(a, b) = d
template<typename T> T exGcd(T a, T b, T &x, T &y)
{ T d = a; if (b) { d = exGcd(b, a % b, y, x); y -= a / b * x; } else { x = 1; y = 0; } return d; }

// returns number of nk's in [l, r]
template<typename T> inline constexpr T mps(T l, T r, T k)
{ return ((r - (r % k + k) % k) - (l + (k - l % k) % k)) / k + 1; }

template<typename T> inline constexpr T sgn(T a)
{ return a ? a > 0 ? 1 : -1 : 0; }

template<typename T> inline constexpr T sq(T a)
{ return a * a; }

template<typename T> inline constexpr bool odd(T a)
{ return bool(a % 2); }

template<typename T> inline constexpr bool even(T a)
{ return !bool(a % 2); }

// simple mod
template<typename T1, typename T2> inline constexpr T1 smod(T1 x, T2 m)
{ return x > m ? x - m : x + m < m ? x + m : x; }

// lengthes of recurring period of replacement `a'
vector<int> repetend(vector<int> a)
{ vector<int> p(a.size(), -1);
  for (unsigned i = 0; i < a.size(); i++) if (p[i] == -1) {
    int c = 1; for (unsigned j = a[i]; j != i; j = a[j]) ++c;
    p[i] = c; for (unsigned j = a[i]; j != i; j = a[j]) p[j] = c;
  } return p; }

template<typename T> inline constexpr T lmiddle(T first, T last)
{ return first + (last - first) / 2; }

template<typename T> inline constexpr T rmiddle(T first, T last)
{ return last - (last - first) / 2; }

// returns the largest value in [l, r) s.t. check(x)
template<typename T, typename F> T dichotomy(T l, T r, F check, T prec = 1)
{ while (r - l > prec) { T m = lmiddle(l, r); (check(m) ? l : r) = m; } return l; }

// returns the smallest value in (l, r] s.t. check(x)
template<typename T, typename F> T dichotomy2(T l, T r, F check, T prec = 1)
{ while (r - l > prec) { T m = rmiddle(l, r); (check(m) ? r : l) = m; } return r; }
} // namespace Infinity::Miscelleneous

inline namespace BattleLab
{
template<typename T>
vector<int> argsort(const vector<T> &a)
{ vector<pair<T, int>> b; for (unsigned i = 0; i < a.size(); i++) { b.emplace_back(a[i], i); }
  stable_sort(b.begin(), b.end()); vector<int> c; for (pair<T, int> p : b) { c.push_back(p.second); }
  return c; }

template<typename T>
vector<T> rearrange(const vector<T> &a, const vector<int>& b)
{ vector<T> c; for (int i : b) { c.push_back(a[i]); } return c; }

// Array begins

struct
{
    int i, n;
    bool first() const { return i == 0; }
    bool last() const { return i == n - 1; }
} loop;

#if __cplusplus >= 201402L
#define STL_ALGO_OO(func) \
    template<typename... types> auto func(types ...args) \
    { return std::func(this->begin(), this->end(), args...); }
#define INFINITY_ALGO_OO(func) \
    template<typename... types> auto func(types ...args) \
    { return ::func(*this, args...); }
#define INFINITY_ALGO_OO_OVERRIDE(func, return_type) \
    template<typename... types> return_type func(types ...args) \
    { return ::func(*this, args...); }
#define PAST_PARTICIPLE(stem, pp) \
    template<typename... types> Array<T> &pp(types ...args) \
    { stem(args...); return *this; }
#endif

template<typename T>
class Array : public std::vector<T>
{
public:
    using std::vector<T>::vector;

    Array() = default;

    Array(const vector<T> &a) : vector<T>(a)
    {}

    int length() const
    { return this->size(); }

    template<typename... types> Array<T> &append(types ...args)
    { this->emplace_back(args...); return *this; }

    T sum() const
    { T s = T(); for (T val : *this) { s += val; } return s; }

    template<typename P> P sum(P val) const
    { for (T x : *this) { val += x; } return val; }

    Array<T> &add(T increment = 1)
    { for (T &val : *this) { val += increment; } return *this; }

    Array<T> &unique()
    { this->erase(std::unique(this->begin(), this->end()), this->end()); return *this; }

    template<typename F> void foreach(F func)
    { loop.n = length(); for (loop.i = 0; loop.i < loop.n; loop.i++) { func(this->at(loop.i)); } }

    template<typename F> Array<pair<int, int>> segments(F func)
    { Array<pair<int, int>> a; int i = 0; while (i < length()) { int j = i + 1;
      while (j < length() && func(this->at(j - 1), this->at(j))) { j++; }
      a.emplace_back(i, j); i = j; } return a; }

#if __cplusplus >= 201402L
    STL_ALGO_OO(sort)           PAST_PARTICIPLE(sort, sorted)
    STL_ALGO_OO(stable_sort)    PAST_PARTICIPLE(stable_sort, stable_sorted)
    STL_ALGO_OO(reverse)        PAST_PARTICIPLE(reverse, reversed)
    STL_ALGO_OO(lower_bound)    STL_ALGO_OO(next_permutation)
    STL_ALGO_OO(upper_bound)    STL_ALGO_OO(prev_permutation)
    STL_ALGO_OO(count)          STL_ALGO_OO(count_if)
    STL_ALGO_OO(find)           STL_ALGO_OO(find_if)
    STL_ALGO_OO(fill)           /*STL_ALGO_OO(for_each)*/
    STL_ALGO_OO(iota)           STL_ALGO_OO(partial_sum)
    INFINITY_ALGO_OO(lbound)    INFINITY_ALGO_OO(ubound)
    INFINITY_ALGO_OO_OVERRIDE(argsort, Array<int>)
#endif
};

Array<int> getints(unsigned size)
{ Array<int> a(size); for (int &x : a) { scanf("%d", &x); } return a; }

using ints = Array<int>;
using doubles = Array<double>;
using llongs = Array<long long>;

#undef STL_ALGO_OO
#undef INFINITY_ALGO_OO
#undef INFINITY_ALGO_OO_OVERRIDE
#undef PAST_PARTICIPLE

// Array ends

// String begins

class String : public std::string
{
public:
    using std::string::string;

    Array<String> split(char delimiter = ' ') const
    { Array<String> a(1); for (char c : *this) {
        if (c != delimiter) { a.back().push_back(c); } else { a.emplace_back(); }
      } return a; }

    int toInt(int base = 10) const
    { return stoi(*this, 0, base); }
};

using StringList = Array<String>;

// String ends

class Division
{
public:
    Division(int n, int k) : lb(n / k), ub(lb + 1), b(n % k) {}
    int operator[](int i) { return i < b ? ub : lb; }
protected:
    int lb, ub, b;
};

template<typename T> class AdjacencyList : public vector<vector<T>>
{
public:
    AdjacencyList(unsigned size = 0) : vector<vector<T>>(size) {}
    void addDirected(T u, T v) { (*this)[u].push_back(v); }
    void addUndirected(T u, T v) { addDirected(u, v); addDirected(v, u); }
};

class Range
{
    class RangeIterator
    {
    public:
        RangeIterator(int i = 0, int step = 1) : i(i), step(step) {}
        // works fine with c++11 range-based for loop ... only
        bool operator !=(const RangeIterator &it) const { return i < it.i; }
        int operator *() const { return i; }
        RangeIterator operator ++() { return {i += step, step}; }
    protected:
        int i, step;
    };
public:
    Range(int to) : from(0), to(to), step(1) {}
    Range(int from, int to, int step = 1) : from(from), to(to), step(step) {}
    RangeIterator begin() const { return {from, step}; }
    RangeIterator end() const { return {to, step}; }
protected:
    int from, to, step;
};

typedef Range range;
} // namespace Infinity::BattleLab

inline namespace IO
{
const char LF = '\n';
const char SP = ' ';

int dbl_prec = 10;
int ldbl_prec = 18;

inline void print(const int n)
{ printf("%d", n); }

inline void print(const unsigned n)
{ printf("%u", n); }

//#ifndef __i386__
inline void print(const long long n)
{ printf("%lld", n); }

inline void print(const unsigned long long n)
{ printf("%lld", n); }
//#endif

//inline void print(const int64_t n)
//{ printf("%" PRId64, n); }

//inline void print(const uint64_t n)
//{ printf("%" PRIu64, n); }

inline void print(const double a)
{ printf("%.*f", dbl_prec, a); }

inline void print(const long double a)
{ printf("%.*Lf", ldbl_prec, a); }

inline void print(const char c)
{ printf("%c", c); }

inline void print(const char s[])
{ printf("%s", s); }

inline void print(const string &s)
{ printf("%s", s.data()); }

template<typename T> inline void printSP(const T a)
{ print(a); print(SP); }

template<typename T, typename U> inline void print(const pair<T, U> &p)
{ printSP(p.first); print(p.second); }

template<class T> inline void print(const T a)
{ for (auto i = a.begin(); i != a.end(); i++) { if (i != a.begin()) print(SP); print(*i); } }

template<typename T> inline void print(initializer_list<T> list)
{ for (auto i = list.begin(); i != list.end(); i++) { if (i != list.begin()) print(SP); print(*i); } }

template<typename T> inline void printr(T begin, T end)
{ for (print(*begin++); begin != end; ++begin) print(SP), print(*begin); }

inline void println()
{ print(LF); }

inline void printSP()
{ print(SP); }

template<typename T> inline void println(const T &a)
{ print(a); print(LF); }

template<typename T> inline void println(initializer_list<T> list)
{ for (auto i = list.begin(); i != list.end(); i++) { if (i != list.begin()) print(SP); print(*i); } print(LF); }

template<class T> inline void printlns(const T &a)
{ for (auto n : a) println(n); }

template<typename T, typename... types> inline void print(const T &a, const types &...args)
{ print(a); print(args...); }

template<typename... types> inline void println(const types &...args)
{ print(args...); print(LF); }

template<typename... types> inline void printSP(const types &...args)
{ print(args...); print(SP); }

inline void printlnYN(bool b)
{ println(b ? "YES" : "NO"); }

inline void printlnyn(bool b)
{ println(b ? "Yes" : "No"); }

string caseN(int n, bool sharp = true, bool space = true)
{ return string("Case ") + (sharp ? "#" : "") + to_string(n) + ":" + (space ? " " : ""); }

inline int read(int &n)
{ return scanf("%d", &n); }

inline int read(int64_t &n)
{ return scanf("%" SCNd64, &n); }

template<typename T, typename ... types> inline int read(T &n, types &...args)
{ return read(n) == eof ? eof : read(args...) + 1; }

inline char getcc()
{ char c; do c = getchar(); while (isspace(c)); return c; }

inline int getint()
{ int n; read(n); return n; }

inline int64_t getll()
{ int64_t n; read(n); return n; }

inline double getdbl()
{ double n; scanf("%lf", &n); return n; }

inline pair<int, int> getpair()
{ pair<int, int> p; scanf("%d%d", &p.first, &p.second); return p; }

//inline vector<int> getints(int n)
//{ vector<int> v(n); for (int &i : v) i = getint(); return v; }

inline vector<pair<int, int> > getpairs(int n)
{ vector<pair<int, int> > v(n); for (pair<int, int> &p : v) { p = getpair(); } return v; }

inline void read(string &str, unsigned size)
{ char s[++size]; scanf("%s", s); str.assign(s); }

inline string getstr(unsigned size = 0x100000)
{ string s; read(s, size); return s; }

inline string getln(unsigned size = 0x100000)
{ char s[++size]; scanf("%[^\n]", s); getchar(); return s; }
} // namespace Infinity::IO
} // namespace Infinity
