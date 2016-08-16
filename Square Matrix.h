template<typename value_type> 
class Matrix : public std::vector<std::vector<value_type>>
{
public:
    Matrix(int n) : 
        std::vector<std::vector<value_type>>(n, std::vector<value_type>(n, value_type())) 
    {}
    
    static Matrix identity(unsigned size)
    {
        Matrix a(size);
        for (unsigned i = 0; i < a.size(); i++)
            a[i][i] = 1;
        return a;
    }
    
    Matrix operator *(const Matrix &m) const
    {
        assert(this->size() == m.size());
        Matrix a(this->size());
        for (unsigned i = 0; i < this->size(); i++)
            for (unsigned j = 0; j < this->size(); j++)
                for (unsigned k = 0; k < this->size(); k++)
                    a[i][j] = (a[i][j] + (*this)[i][k] * m[k][j] % mod) % mod;
        return a;
    }
    
    Matrix operator *=(const Matrix &m)
    { return *this = *this * m; }
    
    Matrix pow(unsigned long long b) const
    {
        Matrix s = identity(this->size());
        for (Matrix a = *this; b; a *= a, b >>= 1)
            if (b & 1)
                s *= a;
        return s;
    }
};
