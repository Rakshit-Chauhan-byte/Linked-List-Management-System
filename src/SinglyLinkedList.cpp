#include "SinglyLinkedList.h"
#include <climits>
#include <utility>

// Constructor
SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

// Destructor - Deallocates all nodes to prevent memory leaks
SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

// Check if list is empty
bool SinglyLinkedList::isEmpty() const {
    return head == nullptr;
}

// Clear all nodes
void SinglyLinkedList::clear() {
    SinglyNode* curr = head;
    while (curr != nullptr) {
        SinglyNode* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
}

// 1. Insert at Beginning - O(1)
void SinglyLinkedList::insertAtBeginning(int val) {
    SinglyNode* newNode = new SinglyNode(val);
    newNode->next = head;
    head = newNode;
}

// 2. Insert at End - O(n) without tail pointer
void SinglyLinkedList::insertAtEnd(int val) {
    SinglyNode* newNode = new SinglyNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    SinglyNode* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
}

// 3. Insert at Position - 1-based index, O(n)
bool SinglyLinkedList::insertAtPosition(int val, int pos) {
    if (pos < 1) {
        return false;
    }
    if (pos == 1) {
        insertAtBeginning(val);
        return true;
    }

    SinglyNode* curr = head;
    int currentPos = 1;

    // Traverse to node at position (pos - 1)
    while (curr != nullptr && currentPos < pos - 1) {
        curr = curr->next;
        currentPos++;
    }

    // Invalid position (greater than list length + 1)
    if (curr == nullptr) {
        return false;
    }

    SinglyNode* newNode = new SinglyNode(val);
    newNode->next = curr->next;
    curr->next = newNode;
    return true;
}

// 4. Insert After a Node - O(n)
bool SinglyLinkedList::insertAfterValue(int target, int val) {
    SinglyNode* curr = head;
    while (curr != nullptr && curr->data != target) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        return false; // Target not found
    }

    SinglyNode* newNode = new SinglyNode(val);
    newNode->next = curr->next;
    curr->next = newNode;
    return true;
}

// 5. Insert Before a Node - O(n)
bool SinglyLinkedList::insertBeforeValue(int target, int val) {
    if (head == nullptr) {
        return false;
    }

    if (head->data == target) {
        insertAtBeginning(val);
        return true;
    }

    SinglyNode* prev = nullptr;
    SinglyNode* curr = head;
    while (curr != nullptr && curr->data != target) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        return false; // Target not found
    }

    SinglyNode* newNode = new SinglyNode(val);
    newNode->next = curr;
    prev->next = newNode;
    return true;
}

// 6. Delete from Beginning - O(1)
bool SinglyLinkedList::deleteFromBeginning() {
    if (head == nullptr) {
        return false; // Empty list
    }
    SinglyNode* temp = head;
    head = head->next;
    delete temp;
    return true;
}

// 7. Delete from End - O(n) in singly linked list
bool SinglyLinkedList::deleteFromEnd() {
    if (head == nullptr) {
        return false; // Empty list
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return true;
    }

    SinglyNode* curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;
    return true;
}

// 8. Delete from Position - 1-based index, O(n)
bool SinglyLinkedList::deleteFromPosition(int pos) {
    if (head == nullptr || pos < 1) {
        return false;
    }

    if (pos == 1) {
        return deleteFromBeginning();
    }

    SinglyNode* curr = head;
    int currentPos = 1;

    while (curr != nullptr && currentPos < pos - 1) {
        curr = curr->next;
        currentPos++;
    }

    if (curr == nullptr || curr->next == nullptr) {
        return false; // Position out of bounds
    }

    SinglyNode* nodeToDelete = curr->next;
    curr->next = nodeToDelete->next;
    delete nodeToDelete;
    return true;
}

// 9. Delete by Value - Delete first matching node, O(n)
bool SinglyLinkedList::deleteByValue(int target) {
    if (head == nullptr) {
        return false;
    }

    if (head->data == target) {
        return deleteFromBeginning();
    }

    SinglyNode* prev = head;
    SinglyNode* curr = head->next;

    while (curr != nullptr && curr->data != target) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        return false; // Target value not found
    }

    prev->next = curr->next;
    delete curr;
    return true;
}

// 10. Search - Returns 1-based position if found, -1 otherwise, O(n)
int SinglyLinkedList::search(int target) const {
    SinglyNode* curr = head;
    int pos = 1;
    while (curr != nullptr) {
        if (curr->data == target) {
            return pos;
        }
        curr = curr->next;
        pos++;
    }
    return -1;
}

// 11. Update - Replace first matching node's data, O(n)
bool SinglyLinkedList::update(int oldVal, int newVal) {
    SinglyNode* curr = head;
    while (curr != nullptr) {
        if (curr->data == oldVal) {
            curr->data = newVal;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// 12. Display - Traverse from head to NULL, O(n)
void SinglyLinkedList::display() const {
    if (head == nullptr) {
        std::cout << "List is empty (NULL)\n";
        return;
    }
    SinglyNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}

// 13. Count Nodes - O(n)
int SinglyLinkedList::countNodes() const {
    int count = 0;
    SinglyNode* curr = head;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;
}

// 14. Find Maximum - O(n)
bool SinglyLinkedList::findMaximum(int& maxVal) const {
    if (head == nullptr) {
        return false;
    }
    maxVal = head->data;
    SinglyNode* curr = head->next;
    while (curr != nullptr) {
        if (curr->data > maxVal) {
            maxVal = curr->data;
        }
        curr = curr->next;
    }
    return true;
}

// 15. Find Minimum - O(n)
bool SinglyLinkedList::findMinimum(int& minVal) const {
    if (head == nullptr) {
        return false;
    }
    minVal = head->data;
    SinglyNode* curr = head->next;
    while (curr != nullptr) {
        if (curr->data < minVal) {
            minVal = curr->data;
        }
        curr = curr->next;
    }
    return true;
}

// 16. Find Middle Element using Slow and Fast pointers - O(n)
// Even length rule: Returns the second middle (N/2 + 1), also reports first middle (N/2)
bool SinglyLinkedList::findMiddleElement(int& middleVal, int& middlePos, bool& isEven, int& firstMidVal) const {
    if (head == nullptr) {
        return false;
    }

    int totalNodes = countNodes();
    isEven = (totalNodes % 2 == 0);

    SinglyNode* slow = head;
    SinglyNode* fast = head;
    SinglyNode* prevSlow = nullptr;
    int pos = 1;

    // Fast moves 2 steps, slow moves 1 step
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prevSlow = slow;
        slow = slow->next;
        pos++;
    }

    middleVal = slow->data;
    middlePos = pos;
    if (isEven && prevSlow != nullptr) {
        firstMidVal = prevSlow->data;
    } else {
        firstMidVal = middleVal;
    }
    return true;
}

// 17. Reverse - Reverses next links in O(n) time and O(1) auxiliary space
void SinglyLinkedList::reverse() {
    SinglyNode* prev = nullptr;
    SinglyNode* curr = head;
    SinglyNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// 18. Sort - Bubble sort by swapping data, O(n^2) time and O(1) space
void SinglyLinkedList::sort() {
    if (head == nullptr || head->next == nullptr) {
        return; // Empty or single-element list is already sorted
    }

    bool swapped;
    SinglyNode* ptr1;
    SinglyNode* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                std::swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// 19. Remove Duplicates - In-place O(n^2) time, O(1) space
int SinglyLinkedList::removeDuplicates() {
    if (head == nullptr || head->next == nullptr) {
        return 0;
    }

    int duplicatesCount = 0;
    SinglyNode* curr = head;

    while (curr != nullptr) {
        SinglyNode* prev = curr;
        SinglyNode* runner = curr->next;

        while (runner != nullptr) {
            if (runner->data == curr->data) {
                // Duplicate found: delete runner node
                prev->next = runner->next;
                delete runner;
                runner = prev->next;
                duplicatesCount++;
            } else {
                prev = runner;
                runner = runner->next;
            }
        }
        curr = curr->next;
    }

    return duplicatesCount;
}
