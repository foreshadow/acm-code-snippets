# acm-code-snippets
They are snippets used in algorithm contest.  
Most of them used ```class``` definition (but not fully object-oriented) rather 
than C programming language's statement in order to facilitate using them in 
contest and avoid naming conflict and too large variant scope.  
The majority of the code is based on GNU C++ standard library, which usually 
requires
```cpp
#include <bits/stdc++.h>
using namespace std;
```
Some of them may use C++ 11 features.

If you want to include them in your project, you may need to do some
modification. For example, add
```cpp
#ifndef SOME_HEADER_H
#define SOME_HEADER_H
// content
#endif // SOME_HEADER_H
```
and deal with namespace problems.
