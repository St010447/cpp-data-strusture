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
    ListNode *before_current = new ListNode();
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
                before_current = current;
                current = current->next;
                cout << current->data << "->";
            }
            cout << "Null" << endl;
        }
    }
    void append_tail(int input)
    {
        ListNode *new_node = new ListNode();

        current = head;
        new_node->data = input;

        for (; current->next != 0; before_current = current, current = current->next)
            ;
        cout << current->data << "before is " << before_current->data << endl;
        current->next = new_node;
    }
    void remove_tail()
    {
        current = head;
        while (current->next != 0)
        {
            before_current = current;
            current = current->next;
        }
        // current->data = 0;
        before_current->next = 0;
    }
    void append_first(int input)
    {
        ListNode *new_node = new ListNode();
        new_node->data = input;
        new_node->next = head->next;
        head->next = new_node;
    }
    void remove_first()
    {
        ListNode *first_Node = new ListNode();

        first_Node = head->next;

        head->next = first_Node->next;
        delete first_Node;
    }
};

main()
{
    LinkedList *A = new LinkedList();
    A->append_first(10);
    A->print_data();
    A->append_first(20);
    A->print_data();
    A->append_first(30);
    A->print_data();
    // A->remove_tail();
    // A->print_data();
}
