#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;

    Node(int x) {
        data = x;
        next = NULL;
        child = NULL;
    }

    static void print_nodes(Node *&head_node) {
        Node *temp = head_node;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    static void print_nodes_address(Node *&head_node) {
        Node *temp = head_node;

        while (temp != NULL) {
            cout << temp << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    static Node *insert(Node *&head_node, int data) {
        if (head_node == NULL) {
            head_node = new Node(data);
            return head_node;
        }

        Node *temp = head_node;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        Node *n_node = new Node(data);
        temp->next = n_node;

        return n_node;
    }

    static Node *insert_child(Node *&head_node, int data) {
        if (head_node == NULL) {
            head_node = new Node(data);
            return head_node;
        }

        Node *temp = head_node;
        while (temp->child != NULL) {
            temp = temp->child;
        }

        Node *n_node = new Node(data);
        temp->child = n_node;

        return n_node;
    }

    static void print_nodes_with_child(Node *head_node) {
        Node *temp = head_node;
        while (temp != NULL) {
            cout << temp->data << " ";
            Node *temp_2 = temp->child;
            while (temp_2 != NULL) {
                cout << temp_2->data << " ";
                temp_2 = temp_2->child;
            }
            cout << endl;
            temp = temp->next;
        }
    }
};


Node *_merge(Node *list1, Node *list2) {
    // merge both lists
    // and return head of new list
    Node *new_list = NULL;

    // if any list is empty return another list
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    // merge both lists recursively
    if (list1->data <= list2->data) {
        new_list = list1;
        new_list->next = _merge(list1->next, list2);
    } else {
        new_list = list2;
        new_list->next = _merge(list1, list2->next);
    }

    return new_list;
}

void split_list(Node *start, Node *&ptr1, Node *&ptr2) {
    // using tortoise and hare approach to find mid
    // and then assign next pointer of mid(or slow) to ptr 2
    // so that it can point to second half of pointer
    Node *slow = start;
    Node *fast = start->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    ptr1 = start;
    ptr2 = slow->next;
    slow->next = NULL;
}

void merge_sort(Node *&head) {
    // merge sort implmentation for linked list 

    // pointers
    Node *start = head;
    Node *list1;
    Node *list2;

    // Base Case
    if ((start == NULL) || (start->next == NULL)) {
        return;
    }

    // split list
    split_list(start, list1, list2);

    // recursively sort both part
    merge_sort(list1);
    merge_sort(list2);

    // merge lists
    head = _merge(list1, list2);
}

void p1() {
    // Problem 1 : MergeSort Linked List - https://www.codingninjas.com/codestudio/problems/mergesort-linked-list_630514

    // Statement : For a given Singly Linked List of integers, 
    // sort the list using the 'Merge Sort' algorithm.

    // Logic : 
    // devide linked list into two halves 
    // use tortoise and hare approach to find mid and split linked list into two halves 
    // after that call merge_sort recursively for both parts of the linked list 
    // after that merge both the halves 

    // Code : 
    // creating linked list of some integers in random order 
    Node *l1 = new Node(5);
    Node *head_node = l1;

    int arr[] = {2, 5, 1, 0, 8, 5, 7, 3, 6};
    // int arr[] = {2, 5, 1, 0, 8, 5, 7, 3};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        Node::insert(head_node, arr[i]);
    }

    // printing nodes value and address 
    Node::print_nodes(head_node);
    Node::print_nodes_address(head_node);

    // sorting 
    merge_sort(head_node);

    // printing values after sorting 
    Node::print_nodes(head_node);
    Node::print_nodes_address(head_node);
}

Node *merge(Node *list1, Node *list2) {
    Node *new_head = new Node(-1);

    Node *temp = new_head;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            temp->child = list1;
            temp = temp->child;
            list1 = list1->child;
        } else {
            temp->child = list2;
            temp = temp->child;
            list2 = list2->child;
        }
    }

    if (list1 == NULL) {
        temp->child = list2;
    } else {
        temp->child = list1;
    }

    return new_head->child;
}

Node *flatten(Node *head_node) {
    if (head_node == NULL || head_node->next == NULL) {
        return head_node;
    }

    // rr 
    head_node->next = flatten(head_node->next);

    // merge 
    head_node = merge(head_node, head_node->next);

    return head_node;
}

void p2() {
    // Problem 2 : Flatten A Linked List - https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655

    // Statement : You are given a linked list containing N nodes, 
    // where every node in the linked list contains two pointers, 
    // first one is ‘NEXT’ which points to the next node in the list 
    // and the second one is ‘CHILD’ pointer to a linked list 
    // where the head is this node. 
    // And each of these child linked lists is in sorted order.
    // Your task is to flatten this linked 
    // such that all nodes appear in a single layer or level 
    // while the nodes should maintain the sorted order 

    // Logic : performing merge sort on two nodes till last node 
    // take two nodes 
    // apply merge sort on them 
    // make a new sorted linked list from both of them 
    // now repeat merge sort for new linked list and other linked list (next one)
    // till only one node is left 

    // Code : 
    // making some linked lists pointers 
    // main 
    Node *n1 = NULL;

    // childs 
    Node *c1 = NULL;
    Node *c2 = NULL;
    Node *c3 = NULL;

    // head pointer 
    Node *head_node = n1;

    // temporary pointer 
    Node *temp;

    // adding elements in child linked list c1, c2 and c3 
    for (int i = 1; i < 4; i++) {
        Node::insert_child(c1, i);
    }
    for (int i = 6; i < 10; i++) {
        Node::insert_child(c2, i);
    }
    for (int i = 12; i < 13; i++) {
        Node::insert_child(c3, i);
    }

    // creating main linked list 
    for (int i = 0; i < 17; i++) {
        if (!(i >= 1 && i < 4) && !(i >= 6 && i < 10) && !(i >= 12 && i < 13)) {
            temp = Node::insert(head_node, i);
        }

        // setting child list 
        if (i == 0) {
            temp->child = c1;
        }
        if (i == 6) {
            temp->child = c2;
        }
        if (i == 10) {
            temp->child = c3;
        }
    }

    Node::print_nodes_with_child(head_node);

    // Solution 
    head_node = flatten(head_node);

    // printing nodes 
    temp = head_node;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->child;
    }
    cout << endl;
}

int main() {
    // Lecture 53 - Linked list Day 10

    // p1();

    // p2();

    return 0;
}
