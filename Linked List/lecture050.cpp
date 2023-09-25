#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    static void print_nodes(Node *&head_node) {
        Node *temp = head_node;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    static Node *insert(Node *&head_node, int data) {
        Node *temp = head_node;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        Node *n_node = new Node(data);
        temp->next = n_node;

        return n_node;
    }

    static void insert_after(Node *&node, int d) {
        Node *new_node = new Node(d);
        node->next = new_node;

        node = new_node;
    }
};

Node *get_mid(Node *head) {
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *reverse(Node *head_node, Node *prev = NULL) {
    // this function will reverse the linked list
    // base case
    if (head_node == NULL || head_node->next == NULL) {
        head_node->next = prev;
        return head_node; // this was tail
        // but now head_node is new head
        // for reversed linked list
    }

    Node *new_head = reverse(head_node->next, head_node);
    head_node->next = prev;

    return new_head;
}

bool is_palindrome(Node *head, Node *head2) {
    Node *temp1 = head;
    Node *temp2 = head2;

    while (temp2 != NULL) {
        if (temp1->data != temp2->data) {
            return false;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
}

void p1() {
    // Problem 1 : Check if Linked List is Palindrome - https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

    // Statement : Given a singly linked list of size N of integers.
    // The task is to check if the given linked list is palindrome or not.

    // Logic :
    // find mid using slow and fast pointer method
    // reverse the linked list after mid using recursive method
    // check if both two parts of linked list
    // from head to mid and mid->next to null have same value or not
    // if they have same value then store answer as true else false
    // after that again reverse the linked list after mid pointer

    // Code :
    // making a linked list
    Node *head = new Node(1);
    Node *temp = head;
    // int arr[] = { 1, 2, 3, 2, 1 };
    // int arr[] = { 1, 2, 2, 10 };
    // int arr[] = { 1, 2, 2, 10 };
    int arr[] = {1, 2, 3, 20, 1};

    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    // printing nodes
    Node::print_nodes(head);

    // finding mid
    Node *mid = get_mid(head);

    // reversing linked list
    mid->next = reverse(mid->next);

    // checking for palindrome
    bool f = is_palindrome(head, mid->next);

    // turning linked list into its original state
    mid->next = reverse(mid->next);

    if (f) {
        cout << "linked list is palindrome" << endl;
    } else {
        cout << "linked list is not palindrome" << endl;
    }

    // printing nodes
    Node::print_nodes(head);
}

int main() {
    // Lecture 50 - Linked list Day 7

    // p1();


    return 0;
}