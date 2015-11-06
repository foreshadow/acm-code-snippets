class Knuth_Morris_Pratt
{
public:
    static int kmpc(const string &s, const string &t)
    {
        vector<int> next = getNext(t);
        int n = s.size();
        int m = t.size();
        int count = 0;
        for (int index = 0; index < n; index++)
        {
            int pos = 0;
            int itr = index;
            while (pos < m && itr < n)
            {
                if(s[itr] == t[pos])
                {
                    itr++;
                    pos++;
                }
                else
                {
                    if(pos == 0)
                        itr++;
                    else
                        pos = next[pos - 1] + 1;
                }
            }
            if (pos == m && (itr - index) == m)
                count++;
        }
        return count;
    }
private:
    static vector<int> getNext(const string &str)
    {
        int n = str.size();
        vector<int> next(n);
        next[0] = -1;
        for(int i = 1; i < n; i++)
        {
            int j = next[i - 1];
            while (str[i] != str[j + 1] && j >= 0)
                j = next[j];
            if (str[i] == str[j + 1])
                next[i] = j + 1;
            else
                next[i] = 0;
        }
        return next;
    }
};