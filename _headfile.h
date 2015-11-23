// includes
#include <algorithm>
//#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
//#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// macro of control statement
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
#define FOR2(i, n, j, m) FOR(i, n) FOR(j, m)
#define FORITER(i, a) for (__typeof a.begin() i = a.begin(); i != a.end(); i++)

// debug
#ifndef ONLINE_JUDGE
#define DEBUG(a) (cout << "Line " << __LINE__  << ": " #a " = " << (a) << endl, a)
#define PRINT(a) cout << #a << endl
#else
#define DEBUG(a) (a)
#define PRINT(a)
#endif

// namespace
using namespace std;

// type definitions
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

// constants
const int maxint = 2147483647;
int mod = 1000000007;

// simplifying functions
inline int ctoi(const char c) { return c - '0'; }
inline char itoc(const int n) { return n + '0'; }
template<typename T> inline bool in(T x, T l, T r) { return l <= x && x <= r; }

// stl functions
template<typename T1, typename T2> inline pair<T1, T2> mp(const T1 &fst, const T2 &scd) { return make_pair(fst, scd); }
template<class T> inline void srt(T &a) { sort(a.begin(), a.end()); }
template<class T1, class T2> inline void srt(T1 &a, bool (&comp)(const T2 &, const T2 &)) { sort(a.begin(), a.end(), comp); }
template<class T1, typename T2> inline int lbs(const T1 &a, const T2 k) { return lower_bound(a.begin(), a.end(), k) - a.begin(); }
template<class T1, typename T2> inline int ubs(const T1 &a, const T2 k) { return upper_bound(a.begin(), a.end(), k) - a.begin(); }

// anti stack overflow
void expandStack(int size = 67108864) // 64 megabytes
{
#ifdef __GNUC__ // be careful of memory limit exceeding
    char *p = (char*) malloc(size) + size;
#ifdef __i386__
    __asm__("movl %0, %%esp\n" :: "r"(p));
#else
    __asm__("movq %0, %%rsp\n" :: "r"(p));
#endif
#else
#pragma comment(linker, "/STACK:1024000000,1024000000") // < 1G
#endif
}

// infinity's IO functions
namespace InfinitysIO
{
const char SP = ' ';
const char CR = '\n';
inline void write(const int n) { printf("%d", n); }
inline void write(const uint n) { printf("%u", n); }
inline void write(const ll n) { cout << n; }
inline void write(const ull n) { cout << n; }
inline void write(const double a) { printf("%f", a); }
inline void writef(const double a, const int n) { printf("%.*f", n, a); }
inline void write(const char c) { printf("%c", c); }
inline void write(const char s[] = "") { printf("%s", s); }
inline void write(const string s) { cout << s; }
inline void write(const pii p) { write(p.first); write(SP); write(p.second); }
inline void writes(const int *a, const int l, const int r) { for (int i = l; i <= r; i++) printf("%d ", a[i]); }
template<uint n> inline void write(const int (&a)[n]) { for (uint i = 0; i < n; i++) printf("%d ", a[i]); }
template<class T> inline void write(const T a) { for (__typeof a.begin() i = a.begin(); i != a.end(); i++) printf("%d ", *i); }
inline void writesp() { write(SP); }
inline void writeln() { write(CR); }
template<typename T> inline void writeln(const T &a) { write(a); write(CR); }
inline void writefln(const double a, int n) { printf("%.*f", n, a); write(CR); }
inline void writesln(const int *a, const int l, const int r) { for (int i = l; i <= r; i++) printf("%d ", a[i]); writeln(CR); }
template<class T> inline void writelns(const T a) { for (__typeof a.begin() i = a.begin(); i != a.end(); i++) writeln(*i); }
#if __cplusplus >= 201103L
template<typename T, typename... types> inline void write(const T &a, const types &...args) { write(a); write(args...); }
template<typename... types> inline void writeln(const types &...args) { write(args...); write(CR); }
#endif
inline int read(int &n) { return scanf("%d", &n); }
// supports CodeForces and HDUOJ, be careful in ZJUOJ.
#ifndef ONLINE_JUDGE
inline int read(ll &n) { return scanf("%lld", &n); }
#else
inline int read(ll &n) { return scanf("%I64d", &n); }
#endif
#if __cplusplus >= 201103L
template<typename T, typename... types> inline int read(T &n, types &...args) { read(n); return read(args...); }
#endif
// ignoring EOF
inline char getcc() { char c; do c = getchar(); while (c == ' ' || c == '\n'); return c; }
inline int getint() { int n; read(n); return n; }
inline ll getll() { ll n; read(n); return n; }
inline double getdouble() { double n; scanf("%lf", &n); return n; }
// array and STL container
template<uint n> inline void reads(int (&a)[n]) { for (uint i = 0; i < n; i++) a[i] = getint(); }
inline void reads(int *a, int l, int r) { for (int i = l; i <= r; i++) a[i] = getint(); }
inline void reads(vector<int> &v, int n) { v.clear(); for (int i = 0; i < n; i++) v.push_back(getint()); }
// pay attention to time consuming of copying the vector
inline vi getints(int n) { vi v; FOR(i, n) v.push_back(getint()); return v; }
inline vpii getpairs(int n) { vpii v; FOR(i, n) { int a = getint(); int b = getint(); v.push_back(pii(a, b)); } return v; }
// std::string
#ifdef __GNUC__
inline void read(string &str, uint size) { char s[size]; scanf("%s", s); str = string(s); }
#else
inline void read(string &str, uint) { cin >> str; }
#endif
inline string getstr(uint size = 1024) { string s; read(s, size + 1); return s; }
} using namespace InfinitysIO;

// cstring
template<typename T> inline void clr(T &a) { memset(a, 0, sizeof a); }
// math
#ifdef _STL_ALGO_H
template<typename T> T gcd(T a, T b) { return __gcd(a, b); }
#else
template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
#endif
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
// find (x, y) s.t. a x + b y = gcd(a, b) = d
template<typename T> T exGcd(T a, T b, T &x, T &y)
{ T d = a; if (b) { d = exGcd(b, a % b, y, x); y -= a / b * x; } else { x = 1; y = 0; } return d; }

// end