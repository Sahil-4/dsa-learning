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
};

void remove_dups(Node *head_node) {
    if (head_node == NULL || head_node->next == NULL) {
        return;
    }

    Node *start = head_node;
    Node *temp = head_node->next;

    while (temp != NULL) {
        if (start->data != temp->data) {
            start->next = temp;
            start = start->next;
            temp = temp->next;
        } else {
            Node *del = temp;
            temp = temp->next;
            delete del;
        }
    }

    start->next = NULL;
}

void p1() {
    // Problen 1 : Remove Duplicates From Sorted List - https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283

    // Statement : You want to play with your friend, 
    // but your friend has pending homework, help him complete that.
    // You are given a ‘Head’ of a sorted linked list. 
    // You can remove some values from the linked list. 
    // In the end, you must return a sorted linked list that 
    // contains no adjacent values that are equal.

    // Logic : using two pointer approach
    // create a functuin remove_dups(Node *head) -> Void
    // inside function add base condition
    // if list is empty or has only one element
    // return
    // make Node two pointers
    // start = head;
    // temp = head->next
    // run a loop till temp != null
    // check if start->data != temp->data
    // if true
    // update next of start to temp
    // and start = start->next
    // and temp = temp->next
    // else
    // store temp in _del any pointer
    // update temp = temp->next
    // and delete the _del pointer
    // after completing loop update next of start to null

    // Code :
    // making linked list
    Node *head_node = new Node(1);
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 5, 6, 7, 7, 8, 9, 9, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < size; i++) {
        Node::insert(head_node, arr[i]);
    }

    // printing all nodes
    Node::print_nodes(head_node);

    // removing duplicates
    remove_dups(head_node);

    // printing all nodes
    Node::print_nodes(head_node);
}

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
    // using slow and fast pointer to find mid
    // and then assign next pointer of mid to ptr 2
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

// Merge Sort
void merge_sort(Node *&head) {
    // Base Case
    // pointers
    Node *start = head;
    Node *list1;
    Node *list2;

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

void p2() {
    // Problem 2 : Remove Duplicates From an Unsorted Linked List - https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331

    // Statement : You are given a linked list of N nodes. 
    // Your task is to remove the duplicate nodes from the linked list 
    // such that every element in the linked list occurs only once 
    // i.e. in case an element occurs more than once, 
    // only keep its first occurrence in the list.

    // Logic : first sort the linked list using merge sort
    // then remove duplicates using two pointer approach
    // in merge sort
    // first split the linked list into two halves
    // using slow and fast pointer and by finding mid
    // after that solve both part recursively
    // then merge them

    // Code :
    // making linked list
    Node *head_node = new Node(6);
    int arr[] = {6, 1, 0, 2, 7, 3, 2, 5, 5, 9, 4, 9, 8, 9, 7, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < size; i++) {
        Node::insert(head_node, arr[i]);
    }

    // printing all nodes
    Node::print_nodes(head_node);

    // sorting linked list
    merge_sort(head_node);

    // removing all duplicates
    remove_dups(head_node);

    // printing all nodes
    Node::print_nodes(head_node);
}

int main() {
    // Lecture 48 - Linked list Day 5

    // p1();

    // p2();

    return 0;
}
