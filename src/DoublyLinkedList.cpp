#include "DoublyLinkedList.h"
#include <climits>
#include <utility>

// Constructor
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Destructor
DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

// Check if empty
bool DoublyLinkedList::isEmpty() const {
    return head == nullptr;
}

// Clear all nodes
void DoublyLinkedList::clear() {
    DoublyNode* curr = head;
    while (curr != nullptr) {
        DoublyNode* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

// 1. Insert at Beginning - O(1)
void DoublyLinkedList::insertAtBeginning(int val) {
    DoublyNode* newNode = new DoublyNode(val);
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// 2. Insert at End - O(1) with tail pointer
void DoublyLinkedList::insertAtEnd(int val) {
    DoublyNode* newNode = new DoublyNode(val);
    if (tail == nullptr) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// 3. Insert at Position - 1-based index, O(n)
bool DoublyLinkedList::insertAtPosition(int val, int pos) {
    if (pos < 1) {
        return false;
    }

    if (pos == 1) {
        insertAtBeginning(val);
        return true;
    }

    DoublyNode* curr = head;
    int currentPos = 1;

    while (curr != nullptr && currentPos < pos) {
        curr = curr->next;
        currentPos++;
    }

    // Inserting at the end (pos == total nodes + 1)
    if (curr == nullptr) {
        if (currentPos == pos) {
            insertAtEnd(val);
            return true;
        }
        return false; // Position out of range
    }

    // Inserting before 'curr'
    DoublyNode* newNode = new DoublyNode(val);
    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev->next = newNode;
    curr->prev = newNode;
    return true;
}

// 4. Insert After a Node - O(n)
bool DoublyLinkedList::insertAfterValue(int target, int val) {
    DoublyNode* curr = head;
    while (curr != nullptr && curr->data != target) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        return false; // Target not found
    }

    if (curr == tail) {
        insertAtEnd(val);
        return true;
    }

    DoublyNode* newNode = new DoublyNode(val);
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next->prev = newNode;
    curr->next = newNode;
    return true;
}

// 5. Insert Before a Node - O(n)
bool DoublyLinkedList::insertBeforeValue(int target, int val) {
    DoublyNode* curr = head;
    while (curr != nullptr && curr->data != target) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        return false; // Target not found
    }

    if (curr == head) {
        insertAtBeginning(val);
        return true;
    }

    DoublyNode* newNode = new DoublyNode(val);
    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev->next = newNode;
    curr->prev = newNode;
    return true;
}

// 6. Delete from Beginning - O(1)
bool DoublyLinkedList::deleteFromBeginning() {
    if (head == nullptr) {
        return false; // Empty list
    }

    DoublyNode* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    return true;
}

// 7. Delete from End - O(1) with tail pointer
bool DoublyLinkedList::deleteFromEnd() {
    if (tail == nullptr) {
        return false; // Empty list
    }

    DoublyNode* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    return true;
}

// 8. Delete from Position - 1-based index, O(n)
bool DoublyLinkedList::deleteFromPosition(int pos) {
    if (head == nullptr || pos < 1) {
        return false;
    }

    if (pos == 1) {
        return deleteFromBeginning();
    }

    DoublyNode* curr = head;
    int currentPos = 1;

    while (curr != nullptr && currentPos < pos) {
        curr = curr->next;
        currentPos++;
    }

    if (curr == nullptr) {
        return false; // Position out of range
    }

    if (curr == tail) {
        return deleteFromEnd();
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    return true;
}

// 9. Delete by Value - Delete first matching node, O(n)
bool DoublyLinkedList::deleteByValue(int target) {
    DoublyNode* curr = head;
    while (curr != nullptr && curr->data != target) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        return false; // Target not found
    }

    if (curr == head) {
        return deleteFromBeginning();
    }

    if (curr == tail) {
        return deleteFromEnd();
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    return true;
}

// 10. Search - Returns 1-based index or -1 if not found, O(n)
int DoublyLinkedList::search(int target) const {
    DoublyNode* curr = head;
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
bool DoublyLinkedList::update(int oldVal, int newVal) {
    DoublyNode* curr = head;
    while (curr != nullptr) {
        if (curr->data == oldVal) {
            curr->data = newVal;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// 12. Display Forward - Traverse from head to NULL, O(n)
void DoublyLinkedList::displayForward() const {
    if (head == nullptr) {
        std::cout << "List is empty (NULL)\n";
        return;
    }
    std::cout << "NULL <- ";
    DoublyNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data;
        if (curr->next != nullptr) {
            std::cout << " <-> ";
        }
        curr = curr->next;
    }
    std::cout << " -> NULL\n";
}

// 13. Display Backward - Traverse from tail to NULL using prev pointers, O(n)
void DoublyLinkedList::displayBackward() const {
    if (tail == nullptr) {
        std::cout << "List is empty (NULL)\n";
        return;
    }
    std::cout << "NULL <- ";
    DoublyNode* curr = tail;
    while (curr != nullptr) {
        std::cout << curr->data;
        if (curr->prev != nullptr) {
            std::cout << " <-> ";
        }
        curr = curr->prev;
    }
    std::cout << " -> NULL\n";
}

// 14. Count Nodes - O(n)
int DoublyLinkedList::countNodes() const {
    int count = 0;
    DoublyNode* curr = head;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;
}

// 15. Find Maximum - O(n)
bool DoublyLinkedList::findMaximum(int& maxVal) const {
    if (head == nullptr) {
        return false;
    }
    maxVal = head->data;
    DoublyNode* curr = head->next;
    while (curr != nullptr) {
        if (curr->data > maxVal) {
            maxVal = curr->data;
        }
        curr = curr->next;
    }
    return true;
}

// 16. Find Minimum - O(n)
bool DoublyLinkedList::findMinimum(int& minVal) const {
    if (head == nullptr) {
        return false;
    }
    minVal = head->data;
    DoublyNode* curr = head->next;
    while (curr != nullptr) {
        if (curr->data < minVal) {
            minVal = curr->data;
        }
        curr = curr->next;
    }
    return true;
}

// 17. Find Middle Element using Slow and Fast pointers - O(n)
// Even length rule: Returns the second middle (N/2 + 1), also reports first middle (N/2)
bool DoublyLinkedList::findMiddleElement(int& middleVal, int& middlePos, bool& isEven, int& firstMidVal) const {
    if (head == nullptr) {
        return false;
    }

    int totalNodes = countNodes();
    isEven = (totalNodes % 2 == 0);

    DoublyNode* slow = head;
    DoublyNode* fast = head;
    DoublyNode* prevSlow = nullptr;
    int pos = 1;

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

// 18. Reverse - Reverses both prev and next pointers and swaps head and tail, O(n)
void DoublyLinkedList::reverse() {
    if (head == nullptr || head == tail) {
        return; // Empty or single-node list
    }

    DoublyNode* curr = head;
    DoublyNode* temp = nullptr;

    while (curr != nullptr) {
        // Swap prev and next
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to the next node (which is stored in curr->prev after swapping)
        curr = curr->prev;
    }

    // Update head and tail
    temp = head;
    head = tail;
    tail = temp;
}

// 19. Sort - Bubble sort by swapping data, O(n^2) time, O(1) space
void DoublyLinkedList::sort() {
    if (head == nullptr || head == tail) {
        return;
    }

    bool swapped;
    DoublyNode* ptr1;
    DoublyNode* lptr = nullptr;

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

// 20. Remove Duplicates - In-place O(n^2) time, O(1) space
int DoublyLinkedList::removeDuplicates() {
    if (head == nullptr || head == tail) {
        return 0;
    }

    int duplicatesCount = 0;
    DoublyNode* curr = head;

    while (curr != nullptr) {
        DoublyNode* runner = curr->next;

        while (runner != nullptr) {
            if (runner->data == curr->data) {
                DoublyNode* toDelete = runner;
                runner = runner->next; // Move runner ahead before deleting

                if (toDelete == tail) {
                    tail = toDelete->prev;
                    tail->next = nullptr;
                } else {
                    toDelete->prev->next = toDelete->next;
                    toDelete->next->prev = toDelete->prev;
                }

                delete toDelete;
                duplicatesCount++;
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }

    return duplicatesCount;
}
