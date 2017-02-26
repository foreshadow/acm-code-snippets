class Prime // Infinity's
{
public:
    Prime(int n) : b(n, false), p()
    { for (int i = 2; i < n; i++) { if (b[i] == false) {
        p.push_back(i); for (int j = i + i; j < n; j += i) { b[j] = true; } } } }

    vector<pair<long long, int>> fact(long long n) // O(sqrt(n))
    {
        vector<pair<long long, int>> fact;
        for (int i = 0; 1ll * p[i] * p[i] <= n; i++) {
            int k = 0; while (n % p[i] == 0) { n /= p[i]; ++k; }
            if (k) { fact.emplace_back(p[i], k); }
        }
        if (n > 1) { fact.emplace_back(n, 1); } return fact;
    }

    long long phi(long long n)
    {
        long long phi = 1; vector<pair<long long, int>> fct = fact(n);
        for (auto p : fct) { phi *= (p.first - 1) * qpow(p.first, p.second - 1); }
        return phi;
    }

protected:
    vector<int> b, p;
};

// make a list of phi[i]
class EulerPhi
{
public:
    EulerPhi(int n) : arr(new int[n+1]) // O(nlglgn)
    {
        clr(arr);
        for (int i = 2 ; i <= n ; i ++ )
            if (!arr[i])
                for (int j = i; j <= n; j += i)
                {
                    if (!arr[j])
                        arr[j] = j ;
                    arr[j] = arr[j]/i*(i-1);
                }
    }
    int operator [](int n) { return arr[n]; }
protected:
    int *arr;
};
