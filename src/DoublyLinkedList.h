#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

// Node structure for Doubly Linked List
struct DoublyNode {
    int data;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List Class
class DoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    // Constructor & Destructor
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Disable copy constructor and assignment
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    // Insertion Operations
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    bool insertAtPosition(int val, int pos);
    bool insertAfterValue(int target, int val);
    bool insertBeforeValue(int target, int val);

    // Deletion Operations
    bool deleteFromBeginning();
    bool deleteFromEnd();
    bool deleteFromPosition(int pos);
    bool deleteByValue(int target);

    // Search and Update Operations
    int search(int target) const; // Returns 1-based index or -1
    bool update(int oldVal, int newVal);

    // Display Operations
    void displayForward() const;
    void displayBackward() const;

    // Utility & Inspection Operations
    int countNodes() const;
    bool findMaximum(int& maxVal) const;
    bool findMinimum(int& minVal) const;
    bool findMiddleElement(int& middleVal, int& middlePos, bool& isEven, int& firstMidVal) const;

    // Advanced Operations
    void reverse();
    void sort();
    int removeDuplicates();

    // Helper utilities
    bool isEmpty() const;
    void clear();
    DoublyNode* getHead() const { return head; }
    DoublyNode* getTail() const { return tail; }
};

#endif // DOUBLY_LINKED_LIST_H
