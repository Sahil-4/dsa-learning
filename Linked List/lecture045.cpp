#include <iostream>

using namespace std;

class Node {
    // implementation of Node for Simple linked list
private:
    int data;
    Node *next;

public:
    // constructors
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // constructors
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }

    // getters
    int get_data() {
        return this->data;
    }

    Node *get_next() {
        return this->next;
    }

    // setters
    void set_data(int data) {
        this->data = data;
    }

    void set_next(Node *next) {
        this->next = next;
    }

    // static methods
    static void print_nodes(Node *head_node) {
        Node *temp = head_node;

        while (temp != NULL) {
            cout << temp->get_data() << " ";
            temp = temp->get_next();
        }
        cout << endl;
    }

    static void insert(Node *&head_node, int data) {
        // inserting new node
        Node *temp = head_node;
        Node *new_node = new Node(data, temp->get_next());
        temp->set_next(new_node);
    }
};

Node *reverse(Node *head_node, Node *prev = NULL) {
    // this function will reverse the linked list
    // base case
    if (head_node == NULL || head_node->get_next() == NULL) {
        head_node->set_next(prev);
        return head_node; // this was tail
        // but now head_node is new head
        // for reversed linked list
    }

    Node *new_head = reverse(head_node->get_next(), head_node);
    head_node->set_next(prev);

    return new_head;
}

void p1() {
    // Problem 1 : Reverse Linked List - https://www.codingninjas.com/codestudio/problems/reverse-the-singly-linked-list_799897

    // Statement : Given a singly linked list of integers.
    // Your task is to reverse the linked list
    // and return the head of the reversed linked list.

    // Logic : using recursion
    // make a recursive function reverse(),
    // which will take two arguments
    // head_node and prev_node
    // initially call reverse(), with head node and null
    // inside function check base condition
    // if head_node == null or head_node->next_node == null
    // first set next of head_node as given prev_node
    // and return head_node
    // as new head node of reversed linked list
    // if base condition is not true
    // create a new node and call the reverse(),
    // with argument as head_node->next and head_node
    // and store its return value inside new node
    // after that set next node of given head_node as given prev_node
    // after that return new node (the return value of reverse())

    // Code :
    // creating a linked list
    Node *n1 = new Node(45);
    Node *head_node = n1;

    for (int i = 1; i < 45; i *= 2) {
        Node::insert(head_node, i);
    }

    // printing nodes value
    Node::print_nodes(head_node);

    // reverse the linked list
    head_node = reverse(head_node);

    // printing nodes value after reversing
    Node::print_nodes(head_node);
}

Node *get_middle(Node *head) {
    Node *p1 = head;
    Node *p2 = head->get_next();

    while (p2 != NULL) {
        if (p2->get_next() != NULL) {
            p2 = p2->get_next();
        }

        p1 = p1->get_next();
        p2 = p2->get_next();
    }

    return p1;
}

void p2() {
    // Problem 2 : Middle Of Linked List - https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250

    // Statement : Given the head node of the singly linked list,
    // return a pointer pointing to the middle of the linked list.
    // If there are an odd number of elements,
    // return the middle element
    // if there are even elements
    // return the one which is farther from the head node.

    // Logic :
    // make a function get_middle(Node *head) -> *Node
    // inside function make two pointers of Node
    // p1 and p2
    // initialise p1 = head
    // and p2 = head->next
    // run a while loop till p2 != null
    // inside loop
    // update p1 = p1->next
    // and p2 = p2->next->next
    // after loop
    // return p1 as middle node

    // Code :
    // creating a linked list
    Node *n1 = new Node(1);

    Node *head_node = n1;

    // making linked list of odd elements
    // for (int i = 25; i > 1; i /= 2) {
    // Node::insert(head_node, i);
    // }

    // making linked list of even elements
    for (int i = 50; i > 1; i /= 2) {
        Node::insert(head_node, i);
    }

    // printing nodes value
    Node::print_nodes(head_node);

    // finding mid of linked list
    Node *mid = get_middle(head_node);

    // value of mid node
    cout << mid->get_data() << endl;
}

int main() {
    // Lecture 45 : Linked List Day 2

    // p1();

    // p2();

    return 0;
}