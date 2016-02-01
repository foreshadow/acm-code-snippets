class SquareMatrix : public vector<vector<long long>>
{
    static const int mod = 1000000007;
public:
    SquareMatrix(int n) : vector<vector<long long>>(n, vector<long long>(n, 0)) {}
    static SquareMatrix identity(int size)
    {
        SquareMatrix a(size);
        for (unsigned i = 0; i < a.size(); i++)
            a[i][i] = 1;
        return a;
    }
    SquareMatrix operator *(const SquareMatrix &m) const
    {
        assert(this->size() == m.size());
        SquareMatrix a(this->size());
        for (unsigned i = 0; i < this->size(); i++)
            for (unsigned j = 0; j < this->size(); j++)
                for (unsigned k = 0; k < this->size(); k++)
                    a[i][j] = (a[i][j] + (*this)[i][k] * m[k][j] % mod) % mod;
        return a;
    }
    SquareMatrix operator ^(int b) const
    {
        SquareMatrix s = identity(this->size());
        for (SquareMatrix a = *this; b > 0; b >>= 1, a = a * a)
            if (b & 1)
                s = s * a;
        return s;
    }
};
