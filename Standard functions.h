// simplifying functions
inline int ctoi(const char c) { return c - '0'; }
inline char itoc(const int n) { return n + '0'; }
template<typename T> inline bool in(T x, T l, T r) { return l <= x && x <= r; }
// double
inline int dtoi(const double d) { return round(d); }
// stl functions
template<typename T1, typename T2> inline pair<T1, T2> mp(const T1 &a, const T2 &b) { return make_pair(a, b); }
template<class T> inline void srt(T &a) { sort(a.begin(), a.end()); }
template<class T1, class T2> inline void srt(T1 &a, T2 comp) { sort(a.begin(), a.end(), comp); }
template<class T1, typename T2> inline int lbs(const T1 &a, const T2 k) { return lower_bound(a.begin(), a.end(), k) - a.begin(); }
template<class T1, typename T2> inline int ubs(const T1 &a, const T2 k) { return upper_bound(a.begin(), a.end(), k) - a.begin(); }
template<class T1, class T2> int count(T1 &a, T2 k) { return ubs(a, k) - lbs(a, k); }
// returning the index of the first element matched, -1 otherwise
template<class T1, class T2> int find(T1 &a, T2 k) { return count(a, k) ? lbs(a, k) : -1; }
template<typename T> inline void clr(T &a) { memset(a, 0, sizeof a); }
template<typename T> T gcd(T a, T b) { while (b) { T t = a % b; a = b; b = t; } return a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
long long qpow(int a, int b, int c) { return b ? qpow(a * a % c, b >> 1, c) * (b & 1 ? a : 1) % c : 1; }
// find (x, y) s.t. a x + b y = gcd(a, b) = d
template<typename T> T exGcd(T a, T b, T &x, T &y)
{ T d = a; if (b) { d = exGcd(b, a % b, y, x); y -= a / b * x; } else { x = 1; y = 0; } return d; }
// returning count of nk in range [l, r]
template<typename T> T mps(T l, T r, T k) { return ((r - (r % k + k) % k) - (l + (k - l % k) % k)) / k + 1; }
template<typename T> T sgn(T a) { return a == 0 ? 0 : a > 0 ? 1 : -1; }
// end