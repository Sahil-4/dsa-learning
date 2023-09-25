#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
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

    static void set_arb(Node *&head_node, int node_position, int arb_position) {
        Node *temp = head_node;
        while (temp != NULL && node_position > 0) {
            temp = temp->next;
            node_position--;
        }

        Node *arb_node = head_node;
        while (arb_node != NULL && arb_position > 0) {
            arb_node = arb_node->next;
            arb_position--;
        }

        temp->arb = arb_node;
    }

    static void print_arb(Node *&head_node) {
        Node *temp = head_node;

        while (temp != NULL) {
            if (temp->arb != NULL) {
                cout << temp->arb->data << " ";
            } else {
                cout << "null ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    static void copy_list(Node *&head_node, Node *&clone_head) {
        // this function is used to clone linked list 
        // this will clone head_node values to clone_head list 

        if (head_node == NULL) {
            return;
        }

        if (clone_head == NULL) {
            clone_head = new Node(head_node->data);
        }

        Node *temp = head_node->next;
        Node *temp2 = clone_head;

        while (temp != NULL) {
            // copying next node of temp to temp2 (of head list to clone list)
            temp2->next = new Node(temp->data);

            // updating pointers 
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
};

void p1() {
    // Problem 1 : Clone a linked list with next and random pointer - https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

    // Statement : You are given a special linked list with N nodes
    // where each node has a next pointer pointing to its next node.
    // You are also given M random pointers,
    // where you will be given M number of pairs
    // denoting two nodes a and b
    // i.e. a->arb = b.
    // Construct a copy of the given list.
    // The copy should consist of exactly N new nodes,
    // where each new node has its value set to the value of its corresponding original node.
    // Both the next and random pointer of the new nodes should point to new nodes in the copied list
    // such that the pointers in the original list and copied list represent the same list state.
    // None of the pointers in the new list should point to nodes in the original list.

    // Logic :
    // Step 1 : clone the given linked list into new linked list
    // Step 2 : insert clone linked list nodes between given linked list nodes
    // Step 3 : assign random pointers to cloned linked list nodes
    // Step 4 : revert changes of second step
    // Step 5 : return head of clone node as answer

    // Code :
    // STEP 0 :
    // creating a linked list
    int arr_data[] = {1, 2, 3, 4};
    Node *head = new Node(arr_data[0]);
    Node *tail;

    // adding more elements
    for (int i = 1; i < sizeof(arr_data) / sizeof(arr_data[0]); i++) {
        tail = Node::insert(head, arr_data[i]);
    }

    // setting arbitary nodes
    int arr_arbs[] = {1, 3};
    for (int i = 0; i < sizeof(arr_arbs) / sizeof(arr_arbs[0]); i++) {
        Node::set_arb(head, i, arr_arbs[i]);
    }

    // printing linked list
    Node::print_nodes(head);

    // printing arbs
    Node::print_arb(head);

    // STEP 1 :
    // making clone linked list
    Node *clone_head = NULL;

    // copying data to clone node
    Node::copy_list(head, clone_head);

    // before solution
    // printing clone linked list
    Node::print_nodes(clone_head);
    // printing arbs of clone linked list
    Node::print_arb(clone_head);

    // STEP 2 :
    // adding all clone nodes between given linked list
    Node *given_list = head;
    Node *clone_list = clone_head;
    while (given_list != NULL && clone_list != NULL) {
        // storing next node of given linked list
        Node *next = given_list->next;
        // updating next pointer of given linked list to cloned list node
        given_list->next = clone_list;
        // updating pointer to next node 
        given_list = next;

        // storing next node of cloned linked list
        next = clone_list->next;
        // updating next pointer of clone linked list to given list node
        clone_list->next = given_list;
        // updating pointer to next node 
        clone_list = next;
    }

    // STEP 3 :
    // copying random pointers
    Node *temp = head;
    while (temp != NULL) {
        if (temp->next != NULL) {
            // updating arb if given linked list nodes have any arb 
            temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
        }

        temp = temp->next->next;
    }

    // STEP 4 :
    // revert changes of STEP 2
    given_list = head;
    clone_list = clone_head;
    while (given_list != NULL && clone_list != NULL) {
        // assigning given linked list nodes next pointer to next of next (cloned linked list nodes next)
        given_list->next = clone_list->next;
        given_list = given_list->next;

        // updating next of cloned linked list
        if (given_list != NULL) {
            clone_list->next = given_list->next;
        }
        // updating pointer
        clone_list = clone_list->next;
    }

    // after solution
    // printing clone linked list
    Node::print_nodes(clone_head);
    // printing arbs of clone linked list
    Node::print_arb(clone_head);
}

int main() {
    // Lecture 52 - Linked list Day 9

    // p1();


    return 0;
}
