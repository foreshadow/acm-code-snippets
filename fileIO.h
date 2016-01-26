// file IO
inline void fileInput(const char *name) { freopen(string(name).append(".in").data(), "r", stdin); }
inline void fileOutput(const char *name) { freopen(string(name).append(".out").data(), "w", stdout); }

void fileIO(const char *name)
{
    fileInput(name);
#ifdef ONLINE_JUDGE
    fileOutput(name);
#endif
}
