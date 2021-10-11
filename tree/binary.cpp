#include <iostream>
#include <string>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *root;
    TreeNode() : data(0), left(nullptr), right(nullptr), root(nullptr){};
    TreeNode(int a) : data(a), left(nullptr), right(nullptr), root(nullptr){};
};
class BinaryTree
{
    TreeNode *head = new TreeNode();
    TreeNode *current = nullptr;
    TreeNode *sibling = nullptr;

public:
    void print_inOrder(TreeNode *current)
    {

        if (current)
        {
            print_inOrder(current->left);
            cout << current->data;
            print_inOrder(current->right);
        }
        else
        {
            cout << "empty tree" << endl;
        }
    }
};
main()
{
    BinaryTree *A = new BinaryTree;
}