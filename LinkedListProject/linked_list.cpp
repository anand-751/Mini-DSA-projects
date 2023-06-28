#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};


/*inserting method from beggining is more efficient and fast than insertion in the end as we ndont have to traverse to the end element.....*/

Node* insertAtBeginning(Node* head, int value) {
    
    // Create a new node
    Node* newNode = new Node;
    newNode->data = value;
                                          
    // Make the new node point to the current head
    newNode->next = head;
    
    // Update the head pointer to the new node
    head = newNode;
    
    return head;
}

/*generally inserting at end is slower comparatively....*/

Node* insertAtEnd(Node* head1, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head1==nullptr){
        head1 = newNode;
    }else{
        Node* temp = head1;
        while (temp->next != nullptr){
            temp = temp->next;    
        }
        temp->next = newNode;
    }
    
    return head1;    
}

//deletion of a node in linked list

Node* deleteNode(Node* head, int value){
    Node* temp;

    if (head->data == value)
    {
        temp = head;
        head = head->next;
    }
    else{
        Node* current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == value)
            {
                temp = current->next;
                current->next = current->next->next;
                delete(temp);
                break;
            }
            else{
                current = current->next;
            }
        }
        
    }
    return head;
}



void displayLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    
}



int main() {
    Node* head = nullptr; // Initialize an empty linked list
   
    // Insert values at the beginning
   
    head =  insertAtBeginning(head, 1);
    head =  insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 3);
    head =  insertAtBeginning(head, 4);               // check working by removing comment"//"

            

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head,40 );                    // check working by removing comment"//"

    //head = deleteNode(head, 4);

   


    // Display the linked list                       //check it by decommenting it...
    displayLinkedList(head);

    cout << "-nullptr-";
    
    return 0;
}
