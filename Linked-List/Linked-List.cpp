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

    void print_data()
    {

        ListNode *current = new ListNode();
        delete current;
        ListNode *pre_current = new ListNode();
        delete pre_current;
        if (head->next == 0)
        {
            cout << "list is empty" << endl;
        }
        else
        {
            current = head;
            while (current->next != 0)
            {
                pre_current = current;
                current = current->next;
                cout << current->data << "->";
            }
            cout << "Null" << endl;
        }
    }
    void append_tail(int input)
    {
        ListNode *current = new ListNode();
        delete current;
        ListNode *pre_current = new ListNode();
        delete pre_current;
        ListNode *new_node = new ListNode();

        current = head;
        new_node->data = input;

        for (; current->next != 0; pre_current = current, current = current->next)
            ;

        current->next = new_node;
    }
    void remove_tail()
    {
        ListNode *current = new ListNode();
        delete current;
        ListNode *pre_current = new ListNode();
        delete pre_current;
        current = head;
        while (current->next != 0)
        {
            pre_current = current;
            current = current->next;
        }
        // current->data = 0;
        pre_current->next = 0;
    }
    void append_first(int input)
    {
        ListNode *current = new ListNode();
        delete current;

        ListNode *new_node = new ListNode();
        new_node->data = input;
        new_node->next = head->next;
        head->next = new_node;
    }
    void remove_first()
    {
        ListNode *current = new ListNode();
        delete current;

        ListNode *first_Node = new ListNode();
        delete first_Node;

        first_Node = head->next;

        head->next = first_Node->next;
        delete first_Node;
    }
    void node_len()
    {
        int count = 0;
        ListNode *current = new ListNode();
        delete current;
        current = head;
        while (current->next != 0)
        {
            count++;
            current = current->next;
        }
        cout << "linked list have " << count << " nodes" << endl;
    }
    void delete_node(int target)
    {

        ListNode *current = new ListNode();
        delete current;
        ListNode *pre_current = new ListNode();
        delete pre_current;

        bool hitData;
        current = head;
        if (target == 0)
        {
            cout << "data can't use 0" << endl;
        }
        else
        {

            for (current = head; current->next != 0; pre_current = current, current = current->next)
            {
                if (current->data == target)
                {
                    hitData = 1;
                    break;
                }
            }
            if (hitData == 1)
            {
                pre_current->next = current->next;
                delete current;
            }
            else
            {
                cout << "not found" << endl;
            }
        }
    }
    void reverse()
    {
        ListNode *pre_current = new ListNode();
        delete pre_current;
        ListNode *current = new ListNode();
        delete current;
        ListNode *next_node = new ListNode();
        delete next_node;
        current = head->next;
        pre_current = 0;
        next_node = current->next;
        while (next_node != 0)
        {
            current->next = pre_current;
            pre_current = current;
            current = next_node;
            next_node = next_node->next;
        }
        current->next = pre_current;

        head->next = current;
    }
};

main()
{
    LinkedList *A = new LinkedList();
    A->append_tail(1);
    A->append_tail(2);
    A->append_tail(3);
    A->append_tail(4);
    A->append_tail(5);
    A->append_tail(6);
    A->print_data();
    A->reverse();
    A->print_data();
    // A->remove_tail();
    // A->print_data();
}
