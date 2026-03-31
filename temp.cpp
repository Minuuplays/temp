#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() : data(0), next(NULL), prev(NULL) {}
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    // ─── INSERTION ───────────────────────────────────────────────

    void insertFirst(int x)
    {
        Node* newNode = new Node(x);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertLast(int x)
    {
        Node* newNode = new Node(x);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int x)
    {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "VALUE NOT FOUND !!" << endl;
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    void insertBefore(int key, int x)
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }

        if (head->data == key)
        {
            insertFirst(x);
            return;
        }

        Node* temp = head;

        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "VALUE NOT FOUND !!" << endl;
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void insertAtPosition(int pos, int x)
    {
        if (pos <= 0)
        {
            cout << "INVALID POSITION !!" << endl;
            return;
        }

        if (pos == 1)
        {
            insertFirst(x);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "POSITION OUT OF RANGE !!" << endl;
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    // ─── DELETION ────────────────────────────────────────────────

    void deleteFirst()
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        cout << "Deleted first node with value : " << temp->data << endl;
        delete temp;
    }

    void deleteLast()
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }

        if (head->next == NULL)
        {
            cout << "Deleted last node with value : " << head->data << endl;
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        cout << "Deleted last node with value : " << temp->data << endl;
        temp->prev->next = NULL;
        delete temp;
    }

    void deleteNode(int key)
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }

        if (head->data == key)
        {
            deleteFirst();
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "VALUE NOT FOUND !!" << endl;
            return;
        }

        temp->prev->next = temp->next;

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }

        cout << "Deleted node with value : " << temp->data << endl;
        delete temp;
    }

    void deleteAtPosition(int pos)
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }

        if (pos <= 0)
        {
            cout << "INVALID POSITION !!" << endl;
            return;
        }

        if (pos == 1)
        {
            deleteFirst();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "POSITION OUT OF RANGE !!" << endl;
            return;
        }

        temp->prev->next = temp->next;

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }

        cout << "Deleted node at position " << pos << " with value : " << temp->data << endl;
        delete temp;
    }

    // ─── SEARCH & TRAVERSE ───────────────────────────────────────

    void searchValue(int x)
    {
        int pos = 1;
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->data == x)
            {
                cout << "Value found at position : " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Value Not Found !!" << endl;
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "EMPTY !!" << endl;
            return;
        }

        Node* temp = head;
        cout << "NULL <-> ";
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL) cout << " <-> ";
            temp = temp->next;
        }
        cout << " <-> NULL" << endl;
    }

    void printReverse()
    {
        if (head == NULL)
        {
            cout << "EMPTY !!" << endl;
            return;
        }

        // Go to the last node using next
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Traverse backwards using prev
        cout << "NULL <-> ";
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->prev != NULL) cout << " <-> ";
            temp = temp->prev;
        }
        cout << " <-> NULL" << endl;
    }

    // ─── UTILITY ─────────────────────────────────────────────────

    void listSize()
    {
        int count = 0;
        Node* temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        cout << "Size of the linked list : " << count << endl;
    }

    void clearList()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;
        cout << "List cleared." << endl;
    }

    ~DoublyLinkedList()
    {
        clearList();
    }
};


int main()
{
    DoublyLinkedList dll;

    cout << "=== INSERT ===" << endl;
    dll.insertLast(10);
    dll.insertLast(20);
    dll.insertLast(30);
    dll.insertFirst(5);
    dll.insertAfter(20, 25);
    dll.insertBefore(10, 7);
    dll.insertAtPosition(3, 99);
    dll.printList();

    cout << "\n=== SIZE ===" << endl;
    dll.listSize();

    cout << "\n=== SEARCH ===" << endl;
    dll.searchValue(25);
    dll.searchValue(99);
    dll.searchValue(77);

    cout << "\n=== DELETE ===" << endl;
    dll.deleteFirst();
    dll.deleteLast();
    dll.deleteNode(25);
    dll.deleteAtPosition(2);
    dll.printList();

    cout << "\n=== REVERSE PRINT ===" << endl;
    dll.printReverse();

    cout << "\n=== CLEAR ===" << endl;
    dll.clearList();
    dll.printList();

    return 0;
}