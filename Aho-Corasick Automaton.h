class AhoCorasickAutomaton
{
    static const int charset = 26; // ['a', 'z']

    struct Node
    {
        int count;
        Node *fail;
        Node *next[charset];
        Node() : count(), fail(), next()
        {}
    };

public:
    AhoCorasickAutomaton(const vector<string> &v) : root(new Node)
    { for (unsigned i = 0; i < v.size(); i++) insert(v[i]); build(); }

    int match(const string &s)
    {
        int cnt = 0;
        Node *p = root;
        for (unsigned i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            while (!p->next[index] && p != root) p = p->fail;
            p = p->next[index];
            p = p ? p : root;
            for (Node *t = p; t != root && t->count != -1; t = t->fail) {
                // match
                cnt += t->count;
                t->count = -1;
            }
        }
        return cnt;
    }

private:
    void insert(const string &s)
    {
        Node *p = root;
        for (unsigned i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            if (!p->next[index]) p->next[index] = new Node;
            p = p->next[index];
        }
        p->count++;
    }

    void build()
    {
        root->fail = 0;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *t = q.front(); q.pop();
            Node *p = 0;
            for (int i = 0; i < charset; i++) {
                if (t->next[i]) {
                    if (t == root) t->next[i]->fail = root;
                    else {
                        p = t->fail;
                        while (p) {
                            if (p->next[i]) {
                                t->next[i]->fail = p->next[i];
                                break;
                            }
                            p = p->fail;
                        }
                        if (!p) t->next[i]->fail = root;
                    }
                    q.push(t->next[i]);
                }
            }
        }
    }

protected:
    Node *root;
};
