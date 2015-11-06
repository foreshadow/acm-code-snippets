template<typename DataType>
class BinaryTreeNode
{
public:
    BinaryTreeNode(DataType data) :
        left(NULL), right(NULL), data(data) {}
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    DataType data;
};

typedef BinaryTreeNode<char> TreeNode;
TreeNode *make_tree(const char *preorder, const char *inorder, int length)
{
    if (length == 0) return NULL;
    int root = 0;
    while (root < length && inorder[root] != preorder[0]) root++;
    TreeNode *node = new TreeNode(preorder[0]);
    node->left = make_tree(preorder + 1, inorder, root);
    node->right = make_tree(preorder + root + 1, inorder + root + 1, length - root - 1);
    return node;
}

template<typename DataType>
void print_postordered_tree(BinaryTreeNode<DataType> *node, ostream &os = cout)
{
    if (node == NULL) return;
    print_postordered_tree(node->left, os);
    print_postordered_tree(node->right, os);
    os << node->data;
}
