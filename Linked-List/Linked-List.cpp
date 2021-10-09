#include <iostream>
#include <string>

using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next; //C++ null=0
    ListNode() : data(0), next(nullptr){};
    ListNode(int a) : data(a), next(nullptr){};
};
class LinkedList
{
public:
    ListNode *head = new ListNode();

    void print_data()
    {

        ListNode *current = nullptr;
        ListNode *pre_current = nullptr;
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
        ListNode *current = nullptr;
        ListNode *pre_current = nullptr;
        ListNode *new_node = new ListNode();
        if (head == nullptr)
        {
            new_node->data = input;
            head->next = new_node;
        }
        else
        {
            current = head;
            new_node->data = input;

            while (current->next != 0)
            {
                pre_current = current;
                current = current->next;
            }

            current->next = new_node;
        }
    }
    void remove_tail()
    {
        ListNode *current = nullptr;
        ListNode *pre_current = nullptr;
        current = head;
        while (current->next != 0)
        {
            pre_current = current;
            current = current->next;
        }
        // current->data = 0;
        delete current;
        pre_current->next = 0;
    }
    void append_first(int input)
    {
        ListNode *current = nullptr;

        ListNode *new_node = new ListNode();
        new_node->data = input;
        new_node->next = head->next;
        head->next = new_node;
    }
    void remove_first()
    {
        ListNode *current = nullptr;

        ListNode *first_Node = nullptr;

        first_Node = head->next;

        head->next = first_Node->next;
        delete first_Node;
    }
    void node_len()
    {
        int count = 0;
        ListNode *current = nullptr;
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

        ListNode *current = nullptr;
        ListNode *pre_current = nullptr;

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
        ListNode *pre_current = nullptr;
        ListNode *current = nullptr;
        ListNode *next_node = nullptr;
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
