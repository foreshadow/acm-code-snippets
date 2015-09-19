class TreeNode
{
public:
    void connect(TreeNode *tn) { this->sons.push_back(tn); tn->sons.push_back(this); }
    void find_parent(TreeNode *setParent = NULL) 
    { 
        if (setParent != NULL) 
        { 
            parent = setParent; 
            FORITER(i, sons) 
                if (*i == parent) 
                { 
                    sons.erase(i); 
                    break; 
                } 
        } 
        FORITER(i, sons) 
            (*i)->find_parent(this); 
    }
    void clear_parent() { FORITER(i, sons) (*i)->clear_parent(); sons.push_back(parent); parent = NULL; }
    TreeNode *parent;
    list<TreeNode *> sons;
};

