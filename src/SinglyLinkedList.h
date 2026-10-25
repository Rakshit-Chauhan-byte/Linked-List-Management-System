#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

// Node structure for Singly Linked List
struct SinglyNode {
    int data;
    SinglyNode* next;

    SinglyNode(int val) : data(val), next(nullptr) {}
};

// Singly Linked List Class
class SinglyLinkedList {
private:
    SinglyNode* head;

public:
    // Constructor & Destructor
    SinglyLinkedList();
    ~SinglyLinkedList();

    // Disable copy constructor and copy assignment to prevent shallow copy bugs
    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;

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
    int search(int target) const; // Returns 1-based index or -1 if not found
    bool update(int oldVal, int newVal);

    // Traversal and Inspection Operations
    void display() const;
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
    SinglyNode* getHead() const { return head; }
};

#endif // SINGLY_LINKED_LIST_H
