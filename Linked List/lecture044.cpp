#include <iostream>

using namespace std;


void p1() {
    // p1 : Linked list 

    // Linked list : is a linear data structure which is made by collection of nodes 
    // node is an entity which stores data and address of next node 
    // Unlike arrays, linked list elements are not stored at a contiguous location 
    // the elements are linked using pointers. 
    // it is dynamic 
    // Insertion and Deletion are easy in linked list 
    // Random access is not allowed
    // Extra memory space for a pointer is required with each element
    // It takes a lot of time in traversing and changing the pointers.

    // Types of linked list 

    // Simple Linked List – In this type of linked list, 
    // one can move or traverse the linked list in only one direction. 
    // where the next pointer of each node points to other nodes 
    // but the next pointer of the last node points to NULL. 

    // Doubly Linked List – In this type of linked list, 
    // one can move or traverse the linked list in both directions (Forward and Backward)

    // Circular Linked List – In this type of linked list, 
    // the last node of the linked list contains 
    // the link of the first/head node of the linked list in its next pointer.

    // Doubly Circular Linked List – A Doubly Circular linked list 
    // or a circular two-way linked list is a more complex type of linked list 
    // that contains a pointer to the next as well as the previous node in the sequence. 
    // The difference between the doubly linked and circular doubly list 
    // is the same as that between a singly linked list and a circular linked list. 
    // The circular doubly linked list does not contain null in the previous field of the first node.

    // Header Linked List – A header linked list is a special type of linked list 
    // that contains a header node at the beginning of the list. 
}

class Node {
    // for p1
    // implementation of Node for Simple linked list 
    public:
        int data; // for data 
        Node *next = NULL; // for storing address of next node 

        // constructors 
        Node() {}

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }

        Node(int data, Node *next) {
            this->data = data;
            this->next = next;
        }

        // getters 
        int getData() {
            return this->data;
        }

        Node *getNextNode() {
            return this->next;
        }

        // setters 
        void setData(int data) {
            this->data = data;
        }

        void setNext(Node *next) {
            this->next = next;
        }

        static void printallnodesvalue(Node *head_node) {
            // this will print all nodes values from given head node 
            // till not found a null node 
            Node *temp = head_node;

            while (temp != NULL) {
                cout << temp->getData() << " ";
                temp = temp->getNextNode();
            }
            cout << endl;
        }

        static void insert_at_head(Node *&head_node, int data) {
            // this method is used to set node as head node 
            // => [1, 2, 3, 4] // insert 7 at head 
            // => [7, 1, 2, 3, 4] // inserted 7 at head 

            // creating new node 
            Node *node = new Node(head_node->getData(), head_node->getNextNode());

            // updating head node 
            head_node->setData(data);
            head_node->setNext(node);

            // now node has value of previews head_node 
            // and head_node has value data 
        }

        static Node *insert_at_tail(Node &tail_node, int data) {
            // this method is used to set given node node as tail node 
            // => [1, 2, 3, 4] // insert 7 at tail 
            // => [1, 2, 3, 4, 7] // inserted 7 at tail 

            // create a new node for data 
            Node *node = new Node(data);

            // just update the address from null to new created node 
            tail_node.setNext(node);

            // now tail_node is no more tail node 
            // it is pointing to node (given node)
            // and node which is pointing to null 
            // is tail node now 

            // after adding new tail return the address of tail node
            return node;
        }

        static void insert_after(Node &node, int data) {
            Node *new_node = new Node(data);
            new_node->setNext(node.getNextNode());
            node.setNext(new_node);
        }

        static void insert_at(Node *&head_node, int postion, int data) {
            // this function is used to insert a new node with given data
            // at given position after head_node 

            if (postion == 0) {
                // insert at head 
                Node::insert_at_head(head_node, data);
                return;
            }

            // traversing linked list till c < position 
            Node *temp = head_node;
            int c = 1;

            while (c < postion) {
                if (temp->getNextNode() == NULL) {
                    Node::insert_at_tail(*temp, data);
                    return;
                }
                temp = temp->getNextNode();
                c++;
            }

            // inserting new node 
            Node *new_node = new Node(data, temp->getNextNode());
            temp->setNext(new_node);
        }

        static void delete_at(Node *&head_node, int position) {
            // this method is used to delete a node at position after head_node

            // delete head node 
            if (position == 0) {
                Node *prev_node = head_node;
                head_node = head_node->getNextNode();
                prev_node->setNext(NULL);

                delete prev_node;

                return;
            }

            // delete (nodes other then head)
            int c = 1;
            Node *temp = head_node;

            // traverse the linked list 
            while (c < position) {
                temp = temp->getNextNode();
                c++;

                if (temp == NULL) {
                    // return is we reached to null 
                    return;
                }
            }

            // store the next node (which will be get deleted)
            Node *del_node = temp->getNextNode();
            if (del_node != NULL) {
                // if node is not null then set the current node's next pointer to 
                // next of deletable node 
                temp->setNext(del_node->getNextNode());
                // remove the pointer from deletable node 
                del_node->setNext(NULL);
            }

            // free up memory 
            delete del_node;
        }

        // destructor 
        ~Node() {}
};

void p2() {
    // p2 : implementing node of linked list (Simple)

    Node *n1 = new Node(54);

    // getting data of node 
    cout << n1->getData() << endl;

    // creating new node 
    Node *n2 = new Node(34);

    // setting next node 
    n1->setNext(n2);

    // getting next node 
    Node *next_node_of_n1 = n1->getNextNode();

    // value of next node of n1 
    cout << n1->getNextNode()->getData() << endl;
    cout << next_node_of_n1->getData() << endl;
}

void p3() {
    // p3 : printing all nodes 

    // first node 
    Node *n1 = new Node(54);

    // head node 
    Node *head_node = n1; // [54 - NULL]

    // second node 
    Node *n2 = new Node(45);

    // connecting second node 
    n1->setNext(n2); // [54 - 45 - NULL]

    // connection more nodes 
    Node *n3 = new Node(5);
    n2->setNext(n3); // [54 - 45 - 5 - NULL]
    Node *n4 = new Node(7);
    n3->setNext(n4); // [54 - 45 - 5 - 7 - NULL]
    Node *n5 = new Node(3);
    n4->setNext(n5); // [54 - 45 - 5 - 7 - 3 - NULL]
    Node *n6 = new Node(9);
    n5->setNext(n6); // [54 - 45 - 5 - 7 - 3 - 9 - NULL]
    Node *n7 = new Node(12);
    n6->setNext(n7); // [54 - 45 - 5 - 7 - 3 - 9 - 12 - NULL]

    cout << "printing all the nodes value" << endl;
    Node::printallnodesvalue(head_node); // [54 - 45 - 5 - 7 - 3 - 9 - 12]
}

void p4() {
    // p4 : inserting at head 

    // creating and connecting nodes 
    Node *n1 = new Node(1);
    Node *head_node = n1;

    // others 
    Node *n2 = new Node(2);
    n1->setNext(n2);
    Node *n3 = new Node(3);
    n2->setNext(n3);
    Node *n4 = new Node(4);
    n3->setNext(n4);
    Node *n5 = new Node(5);
    n4->setNext(n5);

    // before insertion
    // printing all nodes from head_node 
    Node::printallnodesvalue(head_node);

    // inserting node 
    Node::insert_at_head(head_node, 7);

    // after insertion 
    // printing all nodes from head_node 
    Node::printallnodesvalue(head_node);

    // inserting node 
    Node::insert_at_head(head_node, 21);

    // after insertion 
    // printing all nodes from head_node 
    Node::printallnodesvalue(head_node);
}

void p5() {
    // p5 : inserting at tail 

    // creating and connecting nodes 
    Node *n1 = new Node(1);
    Node *head_node = n1;

    // others 
    Node *n2 = new Node(2);
    n1->setNext(n2);
    Node *n3 = new Node(3);
    n2->setNext(n3);
    Node *n4 = new Node(4);
    n3->setNext(n4);
    Node *n5 = new Node(5);
    n4->setNext(n5);

    // printing all nodes from head_node 
    Node::printallnodesvalue(head_node);

    // tail node is last node 
    // which is n5 (value : 5)
    // because n5 is not pointing to any other node 

    // inserting node 
    Node *tail_node = Node::insert_at_tail(*n5, 45);
    // now n5 is no more tail node 
    // because now we have 45 at tail 
    // now tail_node is new tail node 

    // after insertion 
    // printing all nodes 
    Node::printallnodesvalue(head_node);

    // inserting new node at tail 
    // and also updating tail_node value 
    tail_node = Node::insert_at_tail(*tail_node, 7);

    // printing all nodes 
    Node::printallnodesvalue(head_node);
}

void p6() {
    // p6 : inserting a new node after a node 

    // creating and connecting nodes 
    Node *n1 = new Node(1);
    Node *head_node = n1;

    // others 
    Node *n2 = new Node(2);
    n1->setNext(n2);
    Node *n3 = new Node(3);
    n2->setNext(n3);
    Node *n4 = new Node(4);
    n3->setNext(n4);
    Node *n5 = new Node(5);
    n4->setNext(n5);

    // printing all nodes from head_node 
    Node::printallnodesvalue(head_node);

    // inserting node between at position 2 
    Node::insert_after(*n3, 13);

    // printing all nodes from head_node 
    Node::printallnodesvalue(head_node);

    // inserting node between at position 2 
    Node::insert_after(*n3, 45);

    // printing all nodes from head_node 
    Node::printallnodesvalue(head_node);
}

void p7() {
    // p7 : inserting a node at a specific position 

    // creating and connecting nodes 
    Node *n1 = new Node(1);
    Node *head_node = n1;

    // others 
    Node *n2 = new Node(2);
    n1->setNext(n2);
    Node *n3 = new Node(3);
    n2->setNext(n3);
    Node *n4 = new Node(4);
    n3->setNext(n4);
    Node *n5 = new Node(5);
    n4->setNext(n5);

    // printing all nodes from head_node 
    Node::printallnodesvalue(head_node);

    // insert at specific position 
    Node::insert_at(*&head_node, 2, 45);

    // printing all nodes from head_node 
    Node::printallnodesvalue(head_node);

    Node::insert_at(*&head_node, 0, 45);
    Node::printallnodesvalue(head_node);

    Node::insert_at(*&head_node, 1, 45);
    Node::printallnodesvalue(head_node);

    Node::insert_at(*&head_node, 54, 45);
    Node::printallnodesvalue(head_node);
}

void p8() {
    // p8 : Deletion in linked list 

    // creating and connecting nodes 
    Node *n1 = new Node(1);
    Node *head_node = n1;

    // others 
    Node *n2 = new Node(2);
    n1->setNext(n2);
    Node *n3 = new Node(3);
    n2->setNext(n3);
    Node *n4 = new Node(4);
    n3->setNext(n4);
    Node *n5 = new Node(5);
    n4->setNext(n5);

    // printing all nodes from head_node 
    Node::printallnodesvalue(head_node);

    // deletion by position 
    // Node::delete_at(head_node, 2);
    // Node::delete_at(head_node, 1);
    // Node::delete_at(head_node, 0);
    // Node::delete_at(head_node, 4);
    // Node::delete_at(head_node, 5);
    Node::delete_at(head_node, 500);

    // printing all nodes from head_node 
    Node::printallnodesvalue(head_node);
}

class Node_for_doubly {
    // implementation of node for doubly linked list 

    private:
        int data;
        Node_for_doubly *prev_node;
        Node_for_doubly *next_node;

    public:

        // constructors 
        Node_for_doubly() {}

        Node_for_doubly(int data) {
            this->data = data;
            this->prev_node = NULL;
            this->next_node = NULL;
        }

        Node_for_doubly(int data, Node_for_doubly *prev_node) {
            this->data = data;
            this->prev_node = prev_node;
            this->next_node = NULL;
        }

        Node_for_doubly(int data, Node_for_doubly *prev_node, Node_for_doubly *next_node) {
            this->data = data;
            this->prev_node = prev_node;
            this->next_node = next_node;
        }

        // getters 
        int get_data() {
            return this->data;
        }

        Node_for_doubly *get_prev_node() {
            return this->prev_node;
        }

        Node_for_doubly *get_next_node() {
            return this->next_node;
        }

        // setters 
        void set_data(int data) {
            this->data = data;
        }

        void set_prev_node(Node_for_doubly *prev_node) {
            this->prev_node = prev_node;
        }

        void set_next_node(Node_for_doubly *next_node) {
            this->next_node = next_node;
        }

        static void print_values_of_nodes(Node_for_doubly *&head_node) {
            Node_for_doubly *temp = head_node;

            while (temp != NULL) {
                cout << temp->get_data() << " ";
                temp = temp->get_next_node();
            }
            cout << endl;
        }

        static void print_reverse(Node_for_doubly *&tail_node) {
            Node_for_doubly *temp = tail_node;

            while (temp != NULL) {
                cout << temp->get_data() << " ";
                temp = temp->get_prev_node();
            }
            cout << endl;
        }

        static int length(Node_for_doubly *&head_node) {
            Node_for_doubly *temp = head_node;
            int c = 0;

            while (temp != NULL) {
                c++;
                temp = temp->get_next_node();
            }

            return c;
        }

        static void insert_at_head(Node_for_doubly *&head_node, int data) {
            // this function will create a new node 
            // with value of head node 
            // then change the value of head node to given data 
            // change the next pointer of head node to new node 
            // and update the prev pointer of new node to head 

            // creating new node 
            Node_for_doubly *n_node = new Node_for_doubly(head_node->get_data(), head_node->get_prev_node(), head_node->get_next_node());

            // changing pointers 
            head_node->get_next_node()->set_prev_node(n_node);
            n_node->set_prev_node(head_node);
            head_node->set_next_node(n_node);

            // changing value 
            head_node->set_data(data);
        }

        static void insert_at_tail(Node_for_doubly *&tail_node, int data) {
            // create a new node with value of data of given tail node 
            // change next pointer of tail node's prev node to new node 
            // update value of tail node to data 

            Node_for_doubly *n_node = new Node_for_doubly(tail_node->get_data(), tail_node->get_prev_node(), tail_node);
            tail_node->get_prev_node()->set_next_node(n_node);
            tail_node->set_prev_node(n_node);
            tail_node->set_data(data);
        }

        static void insert_at(Node_for_doubly *head_node, int position, int data) {
            // this function will insert the data 
            // at given position after head_node 

            // check if position is 0 call insert_at_head with proper args and return 
            // else continue 
            // and add a new node after the temp node 
            // if next node of temp is null 
            // call insert at tail function 
            // and return 

            if (position == 0) {
                Node_for_doubly::insert_at_head(head_node, data);
                return;
            }

            int c = 1;
            Node_for_doubly *temp = head_node;
            while (c < position) {
                temp = temp->get_next_node();
                c++;

                if (temp->get_next_node() == NULL) {
                    Node_for_doubly::insert_at_tail(temp, data);
                    return;
                }
            }

            // inserting new node 
            Node_for_doubly *n_node = new Node_for_doubly(data, temp, temp->get_next_node());
            temp->get_next_node()->set_prev_node(n_node);
            temp->set_next_node(n_node);
        }

        static void delete_at(Node_for_doubly *&head_node, int position) {
            // handling delete head node 
            if (position == 0) {
                Node_for_doubly *temp = head_node;
                head_node->get_next_node()->set_prev_node(NULL);
                head_node = head_node->get_next_node();

                delete temp;

                return;
            }

            // handling delete nodes present inside linked list after head 
            Node_for_doubly *temp = head_node;
            int c = 1;
            while (c < position) {
                temp = temp->get_next_node();
                c++;

                if (temp == NULL || temp->get_next_node() == NULL) {
                    // if position goes out of range 
                    cout << "out of range" << endl;
                    return;
                }
            }

            if (temp->get_next_node()->get_next_node() == NULL) {
                // handle delete tail node 
                temp->get_next_node()->set_data(temp->get_data());
                temp->get_next_node()->set_prev_node(temp->get_prev_node());
                temp->get_prev_node()->set_next_node(temp->get_next_node());

                delete temp;

                return;
            }

            // handling delete nodes between head and tail node 
            Node_for_doubly *del_node = temp->get_next_node();
            temp->set_next_node(del_node->get_next_node());
            del_node->get_next_node()->set_prev_node(temp);

            delete del_node;
        }
};

void p9() {
    // p9 : creation of doubly linked list 

    // creating first node 
    Node_for_doubly *n1 = new Node_for_doubly(1, NULL, NULL); // [ [null, 1, null] ]

    // creating head node 
    Node_for_doubly *head_node = n1;

    // other nodes 
    Node_for_doubly *n2 = new Node_for_doubly(2, n1);
    n1->set_next_node(n2);
    // [ [null, 1, 2] [1, 2, null] ]
    Node_for_doubly *n3 = new Node_for_doubly(3, n2);
    n2->set_next_node(n3);
    // [ [null, 1, 2] [1, 2, 3] [2, 3, null] ]
    Node_for_doubly *n4 = new Node_for_doubly(4, n3);
    n3->set_next_node(n4);
    // [ [null, 1, 2] [1, 2, 3] [2, 3, 4] [3, 4, null] ]
    Node_for_doubly *n5 = new Node_for_doubly(5, n4);
    n4->set_next_node(n5);
    // [ [null, 1, 2] [1, 2, 3] [2, 3, 4] [3, 4, 5] [4, 5, null] ]
    Node_for_doubly *n6 = new Node_for_doubly(6, n5);
    n5->set_next_node(n6);
    // [ [null, 1, 2] [1, 2, 3] [2, 3, 4] [3, 4, 5] [4, 5, 6] [5, 6, null] ]
    Node_for_doubly *n7 = new Node_for_doubly(7, n6);
    n6->set_next_node(n7);
    // [ [null, 1, 2] [1, 2, 3] [2, 3, 4] [3, 4, 5] [4, 5, 6] [5, 6, 7] [6, 7, null] ]

    // printing nodes 
    Node_for_doubly::print_values_of_nodes(head_node);

    // printing in reverse order 
    Node_for_doubly::print_reverse(n7);
}

void p10() {
    // p10 : inserting node at head 

    // creating first node 
    Node_for_doubly *n1 = new Node_for_doubly(1, NULL, NULL);

    // creating head node 
    Node_for_doubly *head_node = n1;

    // other nodes 
    Node_for_doubly *n2 = new Node_for_doubly(2, n1);
    n1->set_next_node(n2);
    Node_for_doubly *n3 = new Node_for_doubly(3, n2);
    n2->set_next_node(n3);
    Node_for_doubly *n4 = new Node_for_doubly(4, n3);
    n3->set_next_node(n4);
    Node_for_doubly *n5 = new Node_for_doubly(5, n4);
    n4->set_next_node(n5);
    Node_for_doubly *n6 = new Node_for_doubly(6, n5);
    n5->set_next_node(n6);
    Node_for_doubly *n7 = new Node_for_doubly(7, n6);
    n6->set_next_node(n7);

    // printing nodes 
    Node_for_doubly::print_values_of_nodes(head_node);
    // printing reverse 
    Node_for_doubly::print_reverse(n7);

    // inserting at head 
    Node_for_doubly::insert_at_head(head_node, 45);

    // printing nodes after insertion 
    Node_for_doubly::print_values_of_nodes(head_node);
    // printing reverse 
    Node_for_doubly::print_reverse(n7);
}

void p11() {
    // p11 : insertion at tail 

    // creating first node 
    Node_for_doubly *n1 = new Node_for_doubly(1, NULL, NULL);

    // creating head node 
    Node_for_doubly *head_node = n1;

    // other nodes 
    Node_for_doubly *n2 = new Node_for_doubly(2, n1);
    n1->set_next_node(n2);
    Node_for_doubly *n3 = new Node_for_doubly(3, n2);
    n2->set_next_node(n3);
    Node_for_doubly *n4 = new Node_for_doubly(4, n3);
    n3->set_next_node(n4);
    Node_for_doubly *n5 = new Node_for_doubly(5, n4);
    n4->set_next_node(n5);
    Node_for_doubly *n6 = new Node_for_doubly(6, n5);
    n5->set_next_node(n6);
    Node_for_doubly *n7 = new Node_for_doubly(7, n6);
    n6->set_next_node(n7);

    // printing nodes 
    Node_for_doubly::print_values_of_nodes(head_node);
    // printing reverse 
    Node_for_doubly::print_reverse(n7);

    // insertion at tail 
    Node_for_doubly *tail_node = n7;
    Node_for_doubly::insert_at_tail(tail_node, 55);

    // printing nodes 
    Node_for_doubly::print_values_of_nodes(head_node);
    // printing reverse 
    Node_for_doubly::print_reverse(n7);
}

void p12() {
    // p12 : insert at a specific position 

    // creating first node 
    Node_for_doubly *n1 = new Node_for_doubly(1, NULL, NULL);

    // creating head node 
    Node_for_doubly *head_node = n1;

    // other nodes 
    Node_for_doubly *n2 = new Node_for_doubly(2, n1);
    n1->set_next_node(n2);
    Node_for_doubly *n3 = new Node_for_doubly(3, n2);
    n2->set_next_node(n3);
    Node_for_doubly *n4 = new Node_for_doubly(4, n3);
    n3->set_next_node(n4);
    Node_for_doubly *n5 = new Node_for_doubly(5, n4);
    n4->set_next_node(n5);
    Node_for_doubly *n6 = new Node_for_doubly(6, n5);
    n5->set_next_node(n6);
    Node_for_doubly *n7 = new Node_for_doubly(7, n6);
    n6->set_next_node(n7);

    // printing nodes 
    Node_for_doubly::print_values_of_nodes(head_node);
    // printing reverse 
    Node_for_doubly::print_reverse(n7);

    // insertion 
    // Node_for_doubly::insert_at(head_node, 0, 45);
    // Node_for_doubly::insert_at(head_node, 500, 45);
    // Node_for_doubly::insert_at(head_node, 1, 45);
    // Node_for_doubly::insert_at(head_node, 7, 45);
    // Node_for_doubly::insert_at(head_node, 6, 45);
    // Node_for_doubly::insert_at(head_node, 2, 45);
    Node_for_doubly::insert_at(head_node, 3, 45);

    // printing nodes 
    Node_for_doubly::print_values_of_nodes(head_node);
    // printing reverse 
    Node_for_doubly::print_reverse(n7);
}

void p13() {
    // p13 : deletion in DLL 

    // creating first node 
    Node_for_doubly *n1 = new Node_for_doubly(1, NULL, NULL);

    // creating head node 
    Node_for_doubly *head_node = n1;

    // other nodes 
    Node_for_doubly *n2 = new Node_for_doubly(2, n1);
    n1->set_next_node(n2);
    Node_for_doubly *n3 = new Node_for_doubly(3, n2);
    n2->set_next_node(n3);
    Node_for_doubly *n4 = new Node_for_doubly(4, n3);
    n3->set_next_node(n4);
    Node_for_doubly *n5 = new Node_for_doubly(5, n4);
    n4->set_next_node(n5);
    Node_for_doubly *n6 = new Node_for_doubly(6, n5);
    n5->set_next_node(n6);
    Node_for_doubly *n7 = new Node_for_doubly(7, n6);
    n6->set_next_node(n7);

    // printing nodes 
    Node_for_doubly::print_values_of_nodes(head_node);
    // printing reverse 
    Node_for_doubly::print_reverse(n7);

    // deletion 
    // Node_for_doubly::delete_at(head_node, 0);
    // Node_for_doubly::delete_at(head_node, 500);
    // Node_for_doubly::delete_at(head_node, 1);
    // Node_for_doubly::delete_at(head_node, 7);
    // Node_for_doubly::delete_at(head_node, 6);
    // Node_for_doubly::delete_at(head_node, 2);
    Node_for_doubly::delete_at(head_node, 3);

    // printing nodes 
    Node_for_doubly::print_values_of_nodes(head_node);
    // printing reverse 
    Node_for_doubly::print_reverse(n7);
}

class Node_for_circular {
    // implementation of node for singly circular linked list 
    private:
        int data;
        Node_for_circular *next;

    public:

        // constructors 
        Node_for_circular() {}

        Node_for_circular(int data) {
            this->data = data;
            this->next = NULL;
        }

        Node_for_circular(int data, Node_for_circular *node) {
            this->data = data;
            this->next = node;
        }

        // getters 
        int get_data() {
            return this->data;
        }

        Node_for_circular *get_next() {
            return this->next;
        }

        // setters 
        void set_data(int data) {
            this->data = data;
        }

        void set_next(Node_for_circular *node) {
            this->next = node;
        }

        static void print_all_nodes(Node_for_circular *&tail_node) {
            Node_for_circular *temp = tail_node;

            do {
                temp = temp->get_next();
                cout << temp->get_data() << " ";
            } while (temp != tail_node);
            cout << endl;
        }

        static void insert_at_head(Node_for_circular *&tail_node, int data) {
            Node_for_circular *new_node = new Node_for_circular(data, tail_node->get_next());
            tail_node->set_next(new_node);
        }

        static Node_for_circular *insert_at_tail(Node_for_circular *&tail_node, int data) {
            Node_for_circular *new_node = new Node_for_circular(data, tail_node->get_next());
            tail_node->set_next(new_node);

            return new_node;
        }

        static void insert_at(Node_for_circular *&tail_node, int position, int data) {
            Node_for_circular *temp = tail_node->get_next();

            if (position == 0) {
                // insert at head 
                Node_for_circular::insert_at_head(tail_node, data);
                return;
            }

            int c = 1;
            while (c < position) {
                temp = temp->get_next();
                c++;

                if (temp == tail_node || temp->get_next() == tail_node) {
                    // insert at tail 
                    tail_node = Node_for_circular::insert_at_tail(tail_node, data);
                    return;
                }
            }

            Node_for_circular *new_node = new Node_for_circular(data, temp->get_next());
            temp->set_next(new_node);
        }

        static void delete_at(Node_for_circular *tail_node, int position) {
            // handle head 
            // handle tail / handle out of range 
            // handle nodes bw head and tail 

            if (position == 0) {
                // handled 
                Node_for_circular *temp_head = tail_node->get_next();
                tail_node->set_next(temp_head->get_next());

                delete temp_head;

                return;
            }

            // all the other nodes 
            int c = 1;
            Node_for_circular *temp = tail_node->get_next(); // this is first/head node 
            Node_for_circular *prev = tail_node;
            while (c < position) {
                prev = temp;
                temp = temp->get_next();
                c++;

                if (temp == tail_node) {
                    return;
                }
            }

            prev->set_next(temp->get_next());
            temp->get_next()->set_data(temp->get_data());

            delete temp;
        }

        // destructor 
        ~Node_for_circular() {
            next = NULL;
            delete next;
        }
};

void p14() {
    // p14 : Creation of Circular linked list (singly)


    // first node 
    Node_for_circular *n1 = new Node_for_circular(0);

    // tail node 
    Node_for_circular *tail_node; // [54 - 54]

    // creating other nodes 
    Node_for_circular *n2 = new Node_for_circular(1);
    n1->set_next(n2);
    Node_for_circular *n3 = new Node_for_circular(2);
    n2->set_next(n3);
    Node_for_circular *n4 = new Node_for_circular(3);
    n3->set_next(n4);
    Node_for_circular *n5 = new Node_for_circular(4);
    n4->set_next(n5);
    Node_for_circular *n6 = new Node_for_circular(5);
    n5->set_next(n6);

    // tail node 
    tail_node = n6;
    tail_node->set_next(n1);

    // traversal of circular singly linked list 
    Node_for_circular::print_all_nodes(tail_node);
}

void p15() {
    // p15 : insertion at head in circular linked list (singly)

    // first node 
    Node_for_circular *n1 = new Node_for_circular(45);

    // tail node 
    Node_for_circular *tail_node = n1;
    tail_node->set_next(n1);

    // printing linked list 
    Node_for_circular::print_all_nodes(tail_node);

    // insertion 
    int arr[] = {5, 4, 3, 2, 1, 0};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[i]); i++) {
        Node_for_circular::insert_at_head(tail_node, arr[i]);

        // printing linked list 
        Node_for_circular::print_all_nodes(tail_node);
    }
}

void p16() {
    // p16 : insertion at tail in circular linked list (singly)

    // first node 
    Node_for_circular *n1 = new Node_for_circular(45);

    // tail node 
    Node_for_circular *tail_node = n1;
    tail_node->set_next(n1);

    // printing linked list 
    Node_for_circular::print_all_nodes(tail_node);

    // insertion 
    int arr[] = {5, 4, 3, 2, 1, 0};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[i]); i++) {
        tail_node = Node_for_circular::insert_at_tail(tail_node, arr[i]);

        // printing linked list 
        Node_for_circular::print_all_nodes(tail_node);
    }
}

void p17() {
    // p17 : insertion in between in circular linked list (singly)

    // first node 
    Node_for_circular *n1 = new Node_for_circular(10);

    // tail node 
    Node_for_circular *tail_node = n1;
    tail_node->set_next(n1);

    // creating linked list 
    int arr[] = {5, 4, 3, 2, 1, 0};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[i]); i++) {
        Node_for_circular::insert_at_head(tail_node, arr[i]);
    }

    // printing linked list 
    Node_for_circular::print_all_nodes(tail_node);

    // inserting 
    // Node_for_circular::insert_at(tail_node, 0, 94);
    // Node_for_circular::insert_at(tail_node, 500, 94);
    // Node_for_circular::insert_at(tail_node, 7, 94);
    // Node_for_circular::insert_at(tail_node, 1, 94);
    // Node_for_circular::insert_at(tail_node, 6, 94);
    // Node_for_circular::insert_at(tail_node, 12, 94);
    // Node_for_circular::insert_at(tail_node, 2, 94);
    Node_for_circular::insert_at(tail_node, 5, 94);

    // printing linked list 
    Node_for_circular::print_all_nodes(tail_node);
}

void p18() {
    // p18 : deletion in singly circular linked list 

    // first node 
    Node_for_circular *n1 = new Node_for_circular(10);

    // tail node 
    Node_for_circular *tail_node = n1;
    tail_node->set_next(n1);

    // creating linked list 
    int arr[] = {5, 4, 3, 2, 1, 0};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[i]); i++) {
        Node_for_circular::insert_at_head(tail_node, arr[i]);
    }

    // printing linked list 
    Node_for_circular::print_all_nodes(tail_node);

    // deletion 
    // Node_for_circular::delete_at(tail_node, 0);
    // Node_for_circular::delete_at(tail_node, 500);
    // Node_for_circular::delete_at(tail_node, 1);
    // Node_for_circular::delete_at(tail_node, 7);
    // Node_for_circular::delete_at(tail_node, 6);
    // Node_for_circular::delete_at(tail_node, 12);
    // Node_for_circular::delete_at(tail_node, 2);
    Node_for_circular::delete_at(tail_node, 5);

    // printing linked list 
    Node_for_circular::print_all_nodes(tail_node);
}

int main() {
    // Lecture 44 : Linked List 

    // p1();

    // p2();

    // p3();

    // p4();

    // p5();

    // p6();

    // p7();

    // p8();

    // p9();

    // p10();

    // p11();

    // p12();

    // p13();

    // p14();

    // p15();

    // p16();

    // p17();

    // p18();

    // To learn more 
    // - https://www.geeksforgeeks.org/what-is-linked-list/
    // - https://www.geeksforgeeks.org/data-structures/linked-list/
    // - https://www.programiz.com/dsa/linked-list

    return 0;
}
