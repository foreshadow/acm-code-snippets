template<typename T>
class RootedTree
{
public:
    class Node
    {
    public:
        Node() : data(), parent(), children()
        {}

        void build(Node *root)
        {
            this->parent = root;
            children.resize(remove(children.begin(), children.end(), root) - children.begin());
            for (unsigned i = 0; i < children.size(); i++)
                children[i]->build(this);
        }

        T data;
        Node *parent;
        std::vector<Node *> children;
    };

    RootedTree(std::vector<T> vertex, std::vector<std::pair<int, int>> edge, int root) :
        nodes(vertex.size()), root()
    {
        for (unsigned i = 0; i < vertex.size(); i++)
            nodes[i].data = vertex[i];
        for (unsigned i = 0; i < edge.size(); i++)
        {
            this->nodes[edge[i].first].children.push_back(&this->nodes[edge[i].second]);
            this->nodes[edge[i].second].children.push_back(&this->nodes[edge[i].first]);
        }
        this->nodes[root].build(nullptr);
        this->root = &nodes[root];
    }

    std::vector<Node> nodes;
    Node *root;
};
