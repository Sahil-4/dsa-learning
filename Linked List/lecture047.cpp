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

    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }

    static void print_nodes(Node *head_node, int i = -1) {
        Node *temp = head_node;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;

            // to break the loop
            // in case of circular/looped linked list
            if (i != -1)
                i--;
            if (i == 0)
                break;
        }
        cout << endl;
    }
};

Node *find_loop(Node *head) {
    // return the node where both pointers meet
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast) {
            return slow;
        }
    }

    return NULL;
}

Node *find_start(Node *head, Node *loop_node) {
    // return start of loop / node after tail
    Node *slow = head;

    while (slow != loop_node) {
        slow = slow->next;
        loop_node = loop_node->next;
    }

    return slow;
}

void remove_loop(Node *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    // find intersaction of loop
    Node *loop = find_loop(head);

    // find start of loop
    Node *start = find_start(head, loop);

    // remove loop
    Node *temp = start;
    while (temp->next != start) {
        temp = temp->next;
    }

    temp->next = NULL;
}

void p1() {
    // Problem 1 : Detect and Remove Loop - https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049

    // Statement : Given a singly linked list,
    // you have to detect the loop and remove the loop from the linked list, if present.
    // You have to make changes in the given linked list itself
    // and return the updated linked list.

    // Logic :
    // first find if there is any loop
    // then find the starting node of loop from head
    // after that find the tail and remove the loop
    // create three functions
    // find_loop(Node *head) -> Node* used to find the loop and return any node of loop
    // find_start(Node *head, Node *loop_node) -> Node* used to find the starting of loop node
    // or simply the node which is coming after tail node
    // remove_loop(Node *head) -> Void used to call other two function get starting loop node
    // and remove the loop by updating next pointer of tail node to null
    // inside find_loop(Node *head) -> Node*
    // make two Node pointers slow and fast
    // slow = head
    // fast = head
    // run a loop while slow != null and fast is also not equal to null
    // inside loop
    // update fast = fast->next->next
    // slow = slow->next
    // check if slow == fast
    // if true return slow or fast as loop node
    // after completing loop return null
    // inside find_start(Node *head, Node *loop_node) -> Node*
    // create a pointer Node *slow = head
    // run a loop till slow != loop_node
    // inside loop update
    // slow = slow->next
    // loop_node = loop_node->next
    // after completing loop
    // return slow as starting point of loop
    // or the node which is coming after tail node
    // inside remove_loop(Node *head) -> Void
    // check if head is null
    // if true return from the function
    // after that call find_loop(), with head
    // and store loop_node in a pointer
    // after that check if loop_node == null
    // if true return from function
    // else call the find_start(), with head and loop_node
    // and store start of loop in a pointer
    // after finding start of loop
    // make a temp Node pointer
    // temp = start_of_loop
    // then run a loop till temp->next != start_of_loop
    // inside loop update temp = temp->next
    // at the end
    // update next pointer of temp to null

    // Code :
    // making linked list
    Node *n9 = new Node(9);
    Node *n8 = new Node(8, n9);
    Node *n7 = new Node(7, n8);
    Node *n6 = new Node(6, n7);
    Node *n5 = new Node(5, n6);
    Node *n4 = new Node(4, n5);
    Node *n3 = new Node(3, n4);
    Node *n2 = new Node(2, n3);
    Node *n1 = new Node(1, n2);

    // head node
    Node *head = n1;

    // printing nodes
    Node::print_nodes(head);

    // making cyclic
    n9->next = n4;
    // [ 1 2 3 4 5 6 7 8 9 -> 4 5 6 7 8 9 -> 4 5 6 7 8 9 -> ... ]

    // finding loop
    // find the start of loop
    // remove the loop
    remove_loop(head);

    // printing nodes
    Node::print_nodes(head, 13);
}

int main() {
    // Lecture 47 : Linked List Day 4

    // p1();

    // To Learn above used approach
    // - https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/
    // - https://leetcode.com/discuss/general-discussion/1116359/intro-to-floyds-cycle-detection-algorithm

    return 0;
}