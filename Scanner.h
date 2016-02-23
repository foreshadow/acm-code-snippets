inline namespace Infinity
{
inline namespace IO
{
class Scanner
{
    istream &is;
public:
    Scanner(istream &is) : is(is) { is.sync_with_stdio(false); is.tie(nullptr); }
    template<class T = int> T next() { T n; is >> n; return n; }
    template<class T> Scanner &operator >>(T &n) { is >> n; return *this; }
} in(cin);
class Printer
{
    ostream &os;
public:
    Printer(ostream &os) : os(os) { os.sync_with_stdio(false); }
    void println() { print('\n'); }
    template<class T> void print(const T a) { os << a; }
    template<class T> void println(const T a) { print(a); println(); }
    template<typename T, typename... Types> void print(const T &a, const Types &...args) { print(a); print(args...); }
    template<typename... types> void println(const types &...args) { print(args...); println(); }
    template<class T> Printer &operator <<(const T &n) { os << n; return *this; }
} out(cout);
}
}