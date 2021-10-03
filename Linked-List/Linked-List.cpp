#include <iostream>
#include <string>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next; //C++ null=0
    ListNode() : data(0), next(0){};
};
class LinkedList
{
public:
    void append(ListNode *current, int data)
    {
        ListNode *new_node = new ListNode();
        new_node->data = data;
        for (; current->next != 0; current = current->next)
            ;
        current->next = new_node;
    }
    // void insert(ListNode node, int index)
    // {
    // }
}

main()
{
    ListNode *head = new ListNode();
    LinkedList A;
}
