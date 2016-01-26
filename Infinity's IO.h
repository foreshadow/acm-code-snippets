// infinity's IO functions
namespace Infinity
{
const char CR = '\n';
inline void write(const int n) { printf("%d", n); }
inline void write(const unsigned n) { printf("%u", n); }
inline void write(const long long n) { cout << n; }
inline void write(const unsigned long long n) { cout << n; }
// be careful
inline void write(const double a) { printf("%d", dtoi(a)); }
inline void writef(const double a, const int n = 15) { printf("%.*f", n, a); }
inline void writef(const long double a, const int n = 18) { cout << setprecision(n) << fixed << a; }
inline void write(const char c) { printf("%c", c); }
inline void write(const char s[] = "") { printf("%s", s); }
inline void write(const string &s) { cout << s; }
inline void write(const pair<int, int> &p) { printf("%d %d", p.first, p.second); }
template<class T> inline void write(const T a) { for (__typeof a.begin() i = a.begin(); i != a.end(); i++) printf("%d ", *i); }
inline void writeln() { write(CR); }
template<typename T> inline void writeln(const T &a) { write(a); write(CR); }
inline void writefln(const double a, int n) { printf("%.*f", n, a); write(CR); }
inline void writefln(const long double a, int n = 18) { cout << setprecision(n) << fixed << a << endl; }
inline void writesln(const int *a, const int l, const int r) { for (int i = l; i <= r; i++) printf("%d ", a[i]); writeln(CR); }
template<class T> inline void writelns(const T a) { for (__typeof a.begin() i = a.begin(); i != a.end(); i++) writeln(*i); }
#if __cplusplus >= 201103L
template<typename T, typename... types> inline void write(const T &a, const types &...args) { write(a); write(args...); }
template<typename... types> inline void writeln(const types &...args) { write(args...); write(CR); }
#endif
inline void writelnYN(bool b) { writeln(b ? "YES" : "NO"); }
inline void writelnyn(bool b) { writeln(b ? "Yes" : "No"); }
inline int read(int &n) { return scanf("%d", &n); }
// supports CodeForces and HDUOJ, be careful in ZJUOJ
#ifndef ONLINE_JUDGE
inline int read(long long &n) { return scanf("%lld", &n); }
#else
inline int read(long long &n) { return scanf("%I64d", &n); }
#endif
#if __cplusplus >= 201103L
template<typename T, typename... types> inline int read(T &n, types &...args) { read(n); return read(args...); }
#endif
// ignoring EOF
inline char getcc() { char c; do c = getchar(); while (c == ' ' || c == '\n'); return c; }
inline int getint() { int n; read(n); return n; }
inline long long getll() { long long n; read(n); return n; }
inline double getdouble() { double n; scanf("%lf", &n); return n; }
// STL container
inline vector<int> getints(int n) { vector<int> v(n); for (int i = 0; i < n; i++) v[i] = getint(); return v; }
inline vector<pair<int, int>> getpairs(int n) { vector<pair<int, int>> v(n); for (int i = 0; i < n; i++) { int a = getint(), b = getint(); v[i] = pair<int, int>(a, b); } return v; }
// std::string
#ifdef __GNUC__
inline void read(string &str, const unsigned size) { char s[size]; scanf("%s", s); str = string(s); }
inline string getstr(const unsigned size = 1048576) { string s; read(s, size + 1); return s; }
inline string getln(const unsigned size = 1048576) { char s[size + 1]; scanf("%[^\n]", s); return string(s); }
#endif
} using namespace Infinity;