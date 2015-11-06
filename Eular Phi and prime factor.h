// get prime factor of n and phi[n]
class Euler
{
public:
    static vector<pii> fact(int n) // O(sqrt(n))
    {
        vector<pii> fact;
        for (int i = 0; prime[i]*prime[i] <= n; i++)
        {
            pii p(prime[i], 0);
            while (n % prime[i] == 0)
            {
                n /= prime[i];
                p.second++;
            }
            if (p.second != 0)
                fact.push_back(p);
        }
        if (n > 1)
            fact.push_back(pii(n, 1));
        return fact;
    }
    static string show_fact(int n, string split = " ")
    {
        stringstream ss;
        vector<pii> fct = fact(n);
        for (vector<pii>::iterator j = fct.begin(); j != fct.end(); j++)
            for (int k = 0; k < j->second; k++)
                ss << j->first << split;
        string s = ss.str();
        s.erase(s.end()-split.length(), s.end());
        return s;
    }
    static long long phi(int n)
    {
        long long phi = 1;
        vector<pii> fct = fact(n);
        FORITER(i, fct)
            phi *= (i->first-1) * pow(i->first, i->second-1); 
            // can also use qpow accelerator
        return phi;
    }
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
