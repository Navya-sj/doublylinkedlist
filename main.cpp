#include <iostream>
#include <fstream>
using namespace std;


class Node{
   public:
       int value;
       Node* prev;
       Node* next;
       Node(int val){
            value=val;
            prev=nullptr;
            next=nullptr;
       }

};

Node* searchInDoublyLL(Node* head, int target) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == target) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void TextFile(Node* head, const std::string& filename) {
    std::ofstream outFile(filename);
    Node* current = head;
    while (current != nullptr) {
        outFile << current->value << "\n";
        current = current->next;
    }
    outFile.close();
}

void BinaryFile(Node* head, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    Node* current = head;
    while (current != nullptr) {
        outFile.write(reinterpret_cast<char*>(&current->value), sizeof(int));
        current = current->next;
    }
    outFile.close();
}

int main()
{
     Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;

    int targetElement = 30;
    Node* resultNode = searchInDoublyLL(node1, targetElement);
    if (resultNode) {
        std::cout << "Element " << targetElement << " found in the linked list." << std::endl;
    } else {
        std::cout << "Element " << targetElement << " not found in the linked list." << std::endl;
    }

    TextFile(node1, "doubly_linked_list.txt");
    BinaryFile(node1, "doubly_linked_list.bin");

    delete node1;
    delete node2;
    delete node3;
    delete node4;


    return 0;
}
