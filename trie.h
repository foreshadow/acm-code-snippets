class Trie
{
    class TrieNode
    {
    public:
        map<char, TrieNode *> next;
        // string data or bool exist, int count, etc..
    };

public:
    Trie() : root(new TrieNode)
    {}

    void insert(const string &str)
    {
        TrieNode *node = root;
        for(int i = 0; str[i]; i++)
        {
            if (node->next[str[i]] == nullptr)
                node->next[str[i]] = new TrieNode;
            node = node->next[str[i]];
        }
        // do something with node
    }

    void solve(string s)
    {
        // your solution
    }
    
protected:
    TrieNode *root;
};
