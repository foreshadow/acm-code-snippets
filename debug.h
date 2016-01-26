// debug
#ifndef ONLINE_JUDGE
#define DEBUG(a) (cout << "Line " << __LINE__  << ": " #a " = " << (a) << endl, a)
#define PRINT(a) cout << #a << endl
#else
#define DEBUG(a) (a)
#define PRINT(a)
#endif
#define DB DEBUG
#define PR PRINT