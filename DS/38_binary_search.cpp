#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    Node* getHead() {
        return head;
    }

    Node* getLastNode() {
        Node* temp = head;
        while (temp && temp->next) temp = temp->next;
        return temp;
    }

    Node* middle(Node* start, Node* end) {
        if (!start) return nullptr;
        Node* slow = start;
        Node* fast = start->next;
        while (fast != end) {
            fast = fast->next;
            if (fast != end) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }

    Node* binarySearch(Node* start, Node* end, int key) {
        while (start != end) {
            Node* mid = middle(start, end);
            if (!mid) return nullptr;
            if (mid->data == key) return mid;
            else if (mid->data < key) start = mid->next;
            else end = mid;
        }
        return nullptr;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList list;
    int n, val;
    cout << "Enter number of elements:\n";
    cin >> n;
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertEnd(val);
    }

    cout << "List contents:\n";
    list.print();

    int key;
    cout << "Enter element to search:\n";
    cin >> key;

    Node* res = list.binarySearch(list.getHead(), nullptr, key);
    if (res) cout << "Element found: " << res->data << "\n";
    else cout << "Element not found\n";

    return 0;
}
