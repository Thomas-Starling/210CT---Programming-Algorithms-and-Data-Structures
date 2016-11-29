#include <iostream>
#include <stack>

class BinTreeNode{
public:
    BinTreeNode(int value){
        this->value=value;
        this->left=NULL;
        this->right=NULL;
    }
    int value;
    BinTreeNode* left;
    BinTreeNode* right;
};

BinTreeNode* tree_insert(BinTreeNode* tree, int item){
    if(tree==NULL)
        tree=new BinTreeNode(item);
    else
        if(item < tree->value)
            if(tree->left==NULL)
                tree->left=new BinTreeNode(item);
            else
                tree_insert(tree->left,item);
            else
                if(tree->right==NULL)
                    tree->right=new BinTreeNode(item);
                else
                    tree_insert(tree->right,item);
    return tree;

}

void postorder(BinTreeNode* tree){
    if(tree->left!=NULL)
        postorder(tree->left);
    if(tree->right!=NULL)
        postorder(tree->right);
    std::cout << tree->value << std::endl;

}

//Iterative Approach
void in_order(BinTreeNode* tree)    //O(n)
{
    std::stack<BinTreeNode*> nodes; //Create a stack for the tree
    BinTreeNode *current = tree;    //Keep track of what the current node is

    while(!nodes.empty() || current != NULL)    //Loop while the stack is not empty or the current node is not NULL
    {
        if(current != NULL) //If the current node is not NULL
        {
            nodes.push(current);    //Push the current node into the stack
            current = current->left;    //Put the node to the left of the current into the current
        }
        else
        {
            if(!nodes.empty())  //If the stack is not empty
            {
                current = nodes.top();  //Point to the top of the stack
                nodes.pop();    //Pop the top out of the stack
                std::cout << current->value << std::endl;   //Print the value of current node
                current = current->right;   //Point to the right of the tree
            }
        }
    }
}

int main(int argc, char *argv[])
{
    BinTreeNode* t=tree_insert(0,6);
    tree_insert(t,10);
    tree_insert(t,5);
    tree_insert(t,2);
    tree_insert(t,3);
    tree_insert(t,4);
    tree_insert(t,11);
    in_order(t);
    return 0;
}
