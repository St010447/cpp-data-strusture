#include <iostream>
#include <string>
#include <exception>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : data(0), left(nullptr), right(nullptr), parent(nullptr){};
    TreeNode(int a) : data(a), left(nullptr), right(nullptr), parent(nullptr){};
};
class BinaryTree
{

public:
    TreeNode *head = new TreeNode();
    void print_inOrder(TreeNode *current)
    {

        if (current)
        {
            print_inOrder(current->left);
            cout << current->data << " ";
            print_inOrder(current->right);
        }
    }
    void append_node(int input, TreeNode *temp)
    {
        TreeNode *current = nullptr;
        current = temp;

        if (current == 0 || current->data == 0 || current->data == input)
        {
            current->data = input;
        }
        else if (current->data < input)
        {
            if (temp->right)
            {
                append_node(input, temp->right);
            }
            else
            {
                TreeNode *new_node = new TreeNode();
                temp->right = new_node;
                append_node(input, temp->right);
            }
        }
        else if (current->data > input)
        {
            if (temp->left)
            {
                append_node(input, temp->left);
            }
            else
            {
                TreeNode *new_node = new TreeNode();
                temp->left = new_node;
                append_node(input, temp->left);
            }
        }
    }
};
int main()
{
    BinaryTree *A = new BinaryTree();
    A->append_node(10, A->head);
    A->append_node(50, A->head);
    A->append_node(5, A->head);
    A->append_node(30, A->head);
    A->append_node(15, A->head);
    A->append_node(10, A->head);

    A->print_inOrder(A->head);
}
