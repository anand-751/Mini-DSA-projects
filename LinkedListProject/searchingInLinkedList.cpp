#include <iostream>
using namespace std;
// Define the linked list node structure
struct Node {
    int data;
    Node* next;
};

// Search for a value in the linked list
bool searchLinkedList(Node* head, int value) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == value) {
            return true;  // Value found
        }
        current = current->next;
    }

    return false;  // Value not found
}

int main() {

 Node* head = nullptr;
    Node* current = nullptr;

    for (int i = 1; i <= 100; ++i) {
        // Create a new node
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    current = head;

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    std::cout << "nullptr" << std::endl;

    // Prompt the user to enter a value
    int target;
    cout << "Enter a value to search in the linked list: ";
    cin >> target;

    bool found = searchLinkedList(head, target);

    // Print the result
    if (found) {
        cout << "Value " << target << " is found in the linked list." << endl;
    } else {
        cout << "Value " << target << " is not found in the linked list." << endl;
    }

    return 0;
}
