#include <iostream>

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

    void append_right(int input)
    {
        current = current->right;
        if (current->data != 0)
        {
            append_node(input);
        }
        else
        {
            current->data = input;
        }
    }
    void append_left(int input)
    {
        current = current->left;
        if (current->data != 0)
        {
            append_node(input);
        }
        else
        {
            current->data = input;
        }
    }
    void append_node(int input)
    {
        // switch ()
        // {

        // }
    }
};
main()
{
}