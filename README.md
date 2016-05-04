# acm-code-library
They are snippets used in algorithm contest.
Most of them used ```class``` definition rather than C programming language's
statement in order to facilitate using them in contest and avoid naming conflict
and too large variant scope.
The majority of the code is based on GNU C++ standard library, which usually
requires
```cpp
#include <bits/stdc++.h>
```
before, and sometimes
```cpp
using namespace std;
```
is needed.  
If you want to include them in your project, you may need to do some
modification to them. For example, add
```cpp
#ifndef SOME_HEADER_H
#define SOME_HEADER_H
// content
#endif // SOME_HEADER_H
```
and deal with namespace problems.
