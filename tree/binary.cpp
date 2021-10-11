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
class BinarySearchTree
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
    void print_preOrder(TreeNode *current)
    {

        if (current)
        {
            cout << current->data << " ";
            print_preOrder(current->left);
            print_preOrder(current->right);
        }
    }
    void print_postOrder(TreeNode *current)
    {

        if (current)
        {
            print_postOrder(current->left);
            print_postOrder(current->right);
            cout << current->data << " ";
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
                new_node->parent = temp;
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
                new_node->parent = temp;

                append_node(input, temp->left);
            }
        }
    }
    void delete_node(int input, TreeNode *temp)
    {
        TreeNode *current = nullptr;
        TreeNode *keepRef = nullptr;

        if (current->data == input)
        {
            keepRef = current;
            if (current == current->parent->right)
            {
                if (current->left)
                {

                    current->parent->right = current->left;
                    current->left->parent = current->parent;
                    current = current->left;
                    while (current->right)
                    {
                    }
                }
                else if (current->right)
                {
                    current->parent->right = current->right;
                    current->right->parent = current->parent;
                }
                delete keepRef;
            }
            if (current == current->parent->left)
            {
                if (current->left)
                {

                    current->parent->right = current->left;
                    current->left->parent = current->parent;
                }
                else if (current->right)
                {
                    current->parent->right = current->right;
                    current->right->parent = current->parent;
                }
                else
                {
                    current->parent->left = nullptr;
                }
                delete keepRef;
            }
        }
        else if (current->data < input)
        {
            delete_node(input, current->right);
        }
        else if (current->data > input)
        {
            delete_node(input, current->left);
        }
        else
        {
            cout << "doesn't exist " << input << endl;
        }
    }
};
int main()
{
    BinarySearchTree *A = new BinarySearchTree();
    A->append_node(10, A->head);
    A->append_node(50, A->head);
    A->append_node(5, A->head);
    A->append_node(30, A->head);
    A->append_node(15, A->head);
    A->append_node(10, A->head);

    cout << "in order is ";
    A->print_inOrder(A->head);
    cout << endl;
    cout << "pre order is ";

    A->print_preOrder(A->head);
    cout << endl;
    cout << "post order is ";
    A->print_postOrder(A->head);
    cout << endl;
}
