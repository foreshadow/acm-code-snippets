const int maxn = 100000000;
bool b[maxn] = {false};
int p[maxn];
int n = 0;

void getprime()
{
    for (int i = 2; i < maxn; i++)
    {
        if (!b[i])
            p[n++] = i;
        for (int j = 0; j < n && i * p[j] < maxn; j++)
            b[i * p[j]] = true;
    }
}