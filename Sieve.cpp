struct Sieve : public vector<int>
{
    Sieve(int n)
    {
        vector<char> b(n);
        for (int i = 2; i < n; i++) {
            if (!b[i]) {
                push_back(i);
                for (int j = i + i; j < n; j++) {
                    b[j] = true;
                }
            }
        }
    }
} prime(100000);
