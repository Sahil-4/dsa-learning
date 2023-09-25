#include <iostream>
#include <cstdlib>

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

Node *sort012(Node *head) {
    // three linked list 
    // for zeroes ones and twoes 
    Node *zero_h = new Node(-1);
    Node *zero_t = zero_h;
    Node *one_h = new Node(-1);
    Node *one_t = one_h;
    Node *two_h = new Node(-1);
    Node *two_t = two_h;

    Node *curr = head;

    // adding values in all three linked list 
    while (curr != NULL) {
        int val = curr->data;

        if (val == 0) {
            // insert in 0s
            Node::insert_after(zero_t, 0);
        } else if (val == 1) {
            // insert in 1s
            Node::insert_after(one_t, 1);
        } else if (val == 2) {
            // insert in 2s
            Node::insert_after(two_t, 2);
        }

        curr = curr->next;
    }

    // creating a new linked list by merging all three linked list 
    head = zero_h;
    if (one_h->next != NULL) {
        zero_t->next = one_h->next;
        one_t->next = two_h->next;
    } else {
        zero_t->next = two_h->next;
    }

    two_t->next = NULL;

    return head->next;
}

void p1() {
    // Problem 1 : Sort linked list of 0s 1s 2s - https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937

    // Statement : You are given a linked list having N number of nodes 
    // and each node will have an integer which can be 0, 1, or 2. 
    // You have to sort the given linked list in ascending order.

    // Logic : 
    // create a function sort012(), 
    // which will take head of given linked list 
    // inside function 
    // create 6 pointers 
    // 3 for head of all 0s 1s and 2s linked list 
    // 3 pointers for tail of 0s 1s and 2s linked list 
    // create another pointer Node *curr pointing to head 
    // now run a loop till curr != null 
    // inside loop 
    // make an integer variable int val = curr->data 
    // check value of val 
    // if val is 0 
    // add one 0 at the tail of 0s linked list 
    // if val is 1 
    // add one 1 at the tail of 1s linked list 
    // if val is 2 
    // add one 2 at the tail of 2s linked list 
    // after checking update curr = curr->next 
    // after completing loop 
    // merge all the pointers and make a new sorted linked list 
    // to merge all pointers 
    // take tail of 0s and assign next pointer pointing to next of head of 1s 
    // take tail of 1s and assign next pointer pointing to next of head of 2s 
    // take tail of 2s and assign next pointer pointing to null 

    // Code : 
    // making a linked list 
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 0; i < 10; i++) {
        temp->next = new Node(rand()%3);
        temp = temp->next;
    }

    // print nodes 
    Node::print_nodes(head);

    // sorting 
    head = sort012(head);

    // printing nodes after sorting 
    Node::print_nodes(head);
}

Node *merge(Node *list1, Node *list2) {
    Node *head = NULL;

    // base conditions 
    if (list1 == NULL) {
        return list2;
    }

    if (list2 == NULL) {
        return list1;
    }

    if (list1->data <= list2->data) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }

    Node *temp = head;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        } else {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
    }

    while (list1 != NULL) {
        temp->next = list1;
        temp = temp->next;
        list1 = list1->next;
    }

    while (list2 != NULL) {
        temp->next = list2;
        temp = temp->next;
        list2 = list2->next;
    }

    return head;
}

void p2() {
    // Problem 2 : Merge Two Sorted Linked Lists - https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332

    // Statement : You are given two sorted linked lists. 
    // You have to merge them to produce a combined sorted linked list. 
    // You need to return the head of the final linked list.

    // Logic : using two pointers 
    // create a function merge(), 
    // which will take two head pointer of linked list 
    // and return another pointer of new linked list 
    // inside function add base condition 
    // check whether any pointer is null or not 
    // if any one pointer is null simply return second pointer 
    // create a Node* pointer head = null 
    // check list1->data <= list2->data 
    // if true assign head = list1
    // else assign head = list2
    // create another pointer Node *temp = head
    // run a loop till list1 != null and list2 != null 
    // inside loop 
    // check if list->data <= list2->data 
    // update temp->next = list1 
    // temp = temp->next 
    // and list1 = list1->next 
    // else 
    // update temp->next = list2 
    // temp = temp->next 
    // and list2 = list2->next 
    // after completing the loop 
    // add all the remaining elements of list1 and list2 
    // at the end return head 

    // Code : 
    // making two linked list 
    int arr1[] = {1, 3, 4, 5, 5, 9, 9};
    int arr2[] = {2, 2, 2, 3, 4, 5, 9, 9};
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

    // printing all nodes before merging 
    Node::print_nodes(list1);
    Node::print_nodes(list2);

    // merging 
    Node *head = merge(list1, list2);

    // final answer 
    Node::print_nodes(head);
}


int main() {
    // Lecture 49 - Linked list Day 6 

    // p1();

    // p2();

    return 0;
}