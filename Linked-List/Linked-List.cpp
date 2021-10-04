#include <iostream>
#include <string>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next; //C++ null=0
    ListNode() : data(0), next(0){};
    ListNode(int a) : data(a), next(0){};
};
class LinkedList
{
public:
    ListNode *head = new ListNode();
    ListNode *current = new ListNode();
    void append(int input)
    {
        ListNode *new_node = new ListNode();
        current = head;
        new_node->data = input;
        for (; current->next != 0; current = current->next)
            cout << current->next;
        current->next = new_node;
    }
    void print_data()
    {
        if (head->next == 0)
        {
            cout << "list is empty" << endl;
        }
        else
        {
            current = head;
            while (current->next != 0)
            {
                current = current->next;
                cout << current->data << "->";
            }
            cout << 'Null';
        }
    }
};

main()
{
    LinkedList *A = new LinkedList();
    A->append(20);
    A->print_data();
}
