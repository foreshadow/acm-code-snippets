class StringHash // Infinity's
{
    static const int base = 2333;
public:
    StringHash() : h(0), p(1) {}
    StringHash(string s) : StringHash() { for (char c : s) this->append(c); }
    void append(char c) { h = h * base + c; p *= base; }
    void prepend(char c) { h += c * p; p *= base; }
    bool operator ==(StringHash h1) { return this->h == h1.h; }
protected:
    unsigned h;
    unsigned p;
};