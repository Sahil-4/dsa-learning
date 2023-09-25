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

Node *sum_up(Node *list1, Node *list2, Node *&ans) {
    Node *temp = ans;
    int carry = 0;

    while (list1 != NULL || list2 != NULL || carry != 0) {
        int val1 = 0, val2 = 0, val3 = 0;

        if (list1 != NULL) {
            val1 = list1->data;
        }

        if (list2 != NULL) {
            val2 = list2->data;
        }

        if (carry != 0) {
            val3 = carry;
        }

        int sum = val1 + val2 + val3;

        temp->data = sum%10;

        carry = sum/10;

        if (list1 != NULL) {
            list1 = list1->next;
        }

        if (list2 != NULL) {
            list2 = list2->next;
        }

        temp->next = new Node(0);
        temp = temp->next;
    }

    return ans;
}

void p1() {
    // Problem 1 : Add two numbers represented by linked lists - https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

    // Statement : Given two decimal numbers represented by two linked lists of size N and M respectively. 
    // The task is to return a linked list that represents the sum of these two numbers.
    // For example, 
    // the number 190 will be represented by the linked list, 
    // 1->9->0->null, 
    // similarly 25 by 2->5->null. 
    // Sum of these two numbers is 190 + 25 = 215, 
    // which will be represented by 2->1->5->null. 
    // You are required to return the head of the linked list 2->1->5->null.

    // Logic : 
    // first reverse first given linked list 
    // then second given linked list 
    // after that create a Node* pointer for storing final answer 
    // after that sum up all the numbers in the list 
    // and add them in answer pointer as single digits 
    // after adding up all the numbers 
    // reverse the answer linked list 
    // and also first and second linked list 
    // at the end return head of answer linked list 

    // Code : 
    // making two linked list of digits 
    int arr1[] = {1, 3, 4, 5, 5, 9, 9}; // => 1245599 
    int arr2[] = {2, 2, 2, 3, 4, 5, 9, 9}; // => 22234599 
    int size_1 = sizeof(arr1) / sizeof(arr1[0]);
    int size_2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *list1 = new Node(arr1[0]);
    Node *list2 = new Node(arr2[0]);

    // for first linked list 
    Node *temp = list1;
    for (int i = 1; i < size_1; i++) {
        Node *n_node = new Node(arr1[i]);
        temp->next = n_node;
        temp = temp->next;
    }

    // for second linked list 
    temp = list2;
    for (int i = 1; i < size_2; i++) {
        Node *n_node = new Node(arr2[i]);
        temp->next = n_node;
        temp = temp->next;
    }

    // two linked lists are created 

    // printing nodes 
    Node::print_nodes(list1);
    Node::print_nodes(list2);

    // reversing list 1 and list 2 
    list1 = reverse(list1);
    list2 = reverse(list2);

    Node *ans = new Node(0); // answer linked list 

    // finding answer 
    ans = sum_up(list1, list2, ans);

    // reversing the answer 
    ans = reverse(ans);

    if (ans->data == 0) {
        ans = ans->next;
    }

    // reversing list 1 and list 2 
    list1 = reverse(list1);
    list2 = reverse(list2);

    // printing answer 
    Node::print_nodes(ans);
}

int main() {
    // Lecture 51 - Linked list Day 8 

    // p1();


    return 0;
}