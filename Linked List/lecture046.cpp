#include <iostream>

using namespace std;

class Node {
    // implementation of Node for Simple linked list
public:
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

    // static methods
    static void print_nodes(Node *head_node) {
        Node *temp = head_node;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;

            if (temp == head_node) {
                break;
            }
        }
        cout << endl;
    }

    static void insert(Node *&head_node, int data) {
        // inserting new node
        Node *new_node = new Node(data, head_node->next);
        head_node->next = new_node;
    }

    static Node *give_tail(Node *&head_tail) {
        Node *temp = head_tail;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        return temp;
    }
};

Node *reverse_in_group(Node *head_node, int k) {
    // base condition
    if (head_node == NULL) {
        return NULL;
    }

    // reverse first k nodes
    Node *prev = NULL;
    Node *curr = head_node;
    Node *next = NULL;
    int c = 0;

    while (curr != NULL && c < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

        c++;
    }

    // recursive call to reverse remaining nodes
    if (next != NULL) {
        Node *l_head = reverse_in_group(next, k);
        head_node->next = l_head;
    }

    return prev; // new head of current part of ll
}

void p1() {
    // Problem 1 : Reverse List In K Groups - https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644

    // Statement : You are given a linked list of 'N' nodes
    // and an integer 'K'.
    // You have to reverse the given linked list in groups of size K
    // i.e if the list contains x nodes numbered from 1 to x,
    // then you need to reverse each of the groups (1,K),(K+1,2*K), and so on.
    // For example,
    // if the list is [1, 2, 3, 4, 5, 6] and K = 2,
    // then the new list will be [2, 1, 4, 3, 6, 5].
    // [1, 2, 3, 4, 5, 6] -> [[1, 2], [3, 4], [5, 6]] -> [[2, 1], [4, 3], [6, 5]]

    // Logic :
    // create a recursive function reverse_in_group(Node *head_node, int k) -> Node*
    // inside function add a base case
    // if head_node == null return
    // after that reverse the k nodes in linked list from head_node
    // make three pointers
    // prev = null, next = null, curr = head_node
    // and c = 0 for counting nodes
    // run a loop till c < k and curr != null
    // inside loop update prev, next and curr pointer
    // next = curr->next
    // set next of curr as prev
    // update prev = curr
    // after that update curr = next
    // and increament c by 1
    // after completing the loop check if next is not null
    // if next is not null
    // make a recursive call to self with next as head_node and k as k
    // and store return value in a new Node* l_head
    // set next of head_node to l_head
    // at the end return prev as new head node of current reversed sub linked list

    // Code :
    // creating linked list
    Node *head_node = new Node(1);

    // making linked list of even elements
    for (int i = 11; i > 1; i -= 1) {
        Node::insert(head_node, i);
    }

    // printing nodes value
    Node::print_nodes(head_node);

    // reversing
    // head_node = reverse_in_group(head_node, 3);

    // printing nodes value
    Node::print_nodes(head_node);
}

bool is_circular(Node *node) {
    Node *slow = node;
    Node *fast = node;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

void p2() {
    // Problem 2 : Circularly Linked

    // Statement : You are given the head of a linked list containing integers,
    // You need to find out whether the given linked list is circular or not.

    // Logic :
    // create a function is_circular(Node *node) -> bool
    // make two pointers Node *slow = node
    // and Node *fast = node;
    // run a loop till slow != null and fast != null
    // update fast = fast->next->next
    // and slow = slow->next
    // after updating check slow == fast
    // if true return true
    // else at the end return false

    // Code :
    // creating linked list
    Node *head_node = new Node(1);
    Node *tail;
    // making linked list of even elements
    for (int i = 11; i > 1; i -= 1) {
        Node::insert(head_node, i);
    }

    // printing nodes value
    Node::print_nodes(head_node);

    // finding tail
    tail = Node::give_tail(head_node);
    // making it circular
    // tail->next = head_node;

    // printing nodes value
    // Node::print_nodes(head_node);

    // checking circular
    cout << is_circular(head_node);
}

int main() {
    // Lecture 46 : Linked List Day 3

    // p1();

    // p2();

    return 0;
}
