#include <iostream>
#include <limits>
#include <iomanip>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

using namespace std;

// Robust integer input reader
int readInteger(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << "[Error] Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Submenu for Singly Linked List operations
void handleSinglyLinkedList() {
    SinglyLinkedList sll;
    int choice;

    while (true) {
        cout << "\n********** Operation on Singly Linked List **********\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Insert Before a Node\n";
        cout << "6. Delete from Beginning\n";
        cout << "7. Delete from End\n";
        cout << "8. Delete from Position\n";
        cout << "9. Delete by Value\n";
        cout << "10. Search\n";
        cout << "11. Update\n";
        cout << "12. Display\n";
        cout << "13. Count Nodes\n";
        cout << "14. Find Maximum\n";
        cout << "15. Find Minimum\n";
        cout << "16. Find Middle Element\n";
        cout << "17. Reverse\n";
        cout << "18. Sort\n";
        cout << "19. Remove Duplicates\n";
        cout << "20. Exit\n";

        choice = readInteger("Enter the choice:- ");

        switch (choice) {
            case 1: {
                int val = readInteger("Enter value to insert at beginning: ");
                sll.insertAtBeginning(val);
                cout << "[Success] Inserted " << val << " at beginning.\n";
                cout << "Current List: ";
                sll.display();
                break;
            }
            case 2: {
                int val = readInteger("Enter value to insert at end: ");
                sll.insertAtEnd(val);
                cout << "[Success] Inserted " << val << " at end.\n";
                cout << "Current List: ";
                sll.display();
                break;
            }
            case 3: {
                int pos = readInteger("Enter 1-based position: ");
                int val = readInteger("Enter value to insert: ");
                if (sll.insertAtPosition(val, pos)) {
                    cout << "[Success] Inserted " << val << " at position " << pos << ".\n";
                } else {
                    cout << "[Error] Invalid position " << pos << ". Position out of range.\n";
                }
                cout << "Current List: ";
                sll.display();
                break;
            }
            case 4: {
                int target = readInteger("Enter target node value: ");
                int val = readInteger("Enter new value to insert after " + to_string(target) + ": ");
                if (sll.insertAfterValue(target, val)) {
                    cout << "[Success] Inserted " << val << " after node with value " << target << ".\n";
                } else {
                    cout << "[Error] Node with value " << target << " not found in the list.\n";
                }
                cout << "Current List: ";
                sll.display();
                break;
            }
            case 5: {
                int target = readInteger("Enter target node value: ");
                int val = readInteger("Enter new value to insert before " + to_string(target) + ": ");
                if (sll.insertBeforeValue(target, val)) {
                    cout << "[Success] Inserted " << val << " before node with value " << target << ".\n";
                } else {
                    cout << "[Error] Node with value " << target << " not found in the list.\n";
                }
                cout << "Current List: ";
                sll.display();
                break;
            }
            case 6: {
                if (sll.deleteFromBeginning()) {
                    cout << "[Success] Deleted node from beginning.\n";
                } else {
                    cout << "[Error] Cannot delete from empty list.\n";
                }
                cout << "Current List: ";
                sll.display();
                break;
            }
            case 7: {
                if (sll.deleteFromEnd()) {
                    cout << "[Success] Deleted node from end.\n";
                } else {
                    cout << "[Error] Cannot delete from empty list.\n";
                }
                cout << "Current List: ";
                sll.display();
                break;
            }
            case 8: {
                int pos = readInteger("Enter 1-based position to delete: ");
                if (sll.deleteFromPosition(pos)) {
                    cout << "[Success] Deleted node at position " << pos << ".\n";
                } else {
                    cout << "[Error] Invalid or out-of-range position " << pos << ".\n";
                }
                cout << "Current List: ";
                sll.display();
                break;
            }
            case 9: {
                int target = readInteger("Enter value to delete: ");
                if (sll.deleteByValue(target)) {
                    cout << "[Success] Deleted first occurrence of value " << target << ".\n";
                } else {
                    cout << "[Error] Value " << target << " not found in the list.\n";
                }
                cout << "Current List: ";
                sll.display();
                break;
            }
            case 10: {
                int target = readInteger("Enter value to search: ");
                int pos = sll.search(target);
                if (pos != -1) {
                    cout << "[Found] Value " << target << " found at position: " << pos << " (1-based index).\n";
                } else {
                    cout << "[Not Found] Value " << target << " does not exist in the list.\n";
                }
                break;
            }
            case 11: {
                int oldVal = readInteger("Enter existing value to update: ");
                int newVal = readInteger("Enter new replacement value: ");
                if (sll.update(oldVal, newVal)) {
                    cout << "[Success] Updated value " << oldVal << " to " << newVal << ".\n";
                } else {
                    cout << "[Error] Value " << oldVal << " not found in the list.\n";
                }
                cout << "Current List: ";
                sll.display();
                break;
            }
            case 12: {
                cout << "Singly Linked List: ";
                sll.display();
                break;
            }
            case 13: {
                int count = sll.countNodes();
                cout << "Total number of nodes: " << count << "\n";
                break;
            }
            case 14: {
                int maxVal;
                if (sll.findMaximum(maxVal)) {
                    cout << "Maximum value in the list: " << maxVal << "\n";
                } else {
                    cout << "[Error] List is empty. No maximum value.\n";
                }
                break;
            }
            case 15: {
                int minVal;
                if (sll.findMinimum(minVal)) {
                    cout << "Minimum value in the list: " << minVal << "\n";
                } else {
                    cout << "[Error] List is empty. No minimum value.\n";
                }
                break;
            }
            case 16: {
                int midVal, midPos, firstMidVal;
                bool isEven;
                if (sll.findMiddleElement(midVal, midPos, isEven, firstMidVal)) {
                    if (isEven) {
                        cout << "[Middle Element - Even Length List]\n";
                        cout << "  * Standard Convention (Fast/Slow Pointers): Second middle at position " 
                             << midPos << " is: " << midVal << "\n";
                        cout << "  * First middle at position " << (midPos - 1) << " is: " << firstMidVal << "\n";
                    } else {
                        cout << "[Middle Element - Odd Length List]\n";
                        cout << "  * Middle element at position " << midPos << " is: " << midVal << "\n";
                    }
                } else {
                    cout << "[Error] List is empty. No middle element.\n";
                }
                break;
            }
            case 17: {
                cout << "Before Reverse:\n";
                sll.display();
                sll.reverse();
                cout << "After Reverse:\n";
                sll.display();
                break;
            }
            case 18: {
                cout << "Before Sort:\n";
                sll.display();
                sll.sort();
                cout << "After Sort (Ascending):\n";
                sll.display();
                break;
            }
            case 19: {
                cout << "Before Removing Duplicates:\n";
                sll.display();
                int removed = sll.removeDuplicates();
                cout << "[Success] Removed " << removed << " duplicate node(s).\n";
                cout << "After Removing Duplicates:\n";
                sll.display();
                break;
            }
            case 20:
                cout << "Returning to Main Application Menu...\n";
                return;
            default:
                cout << "[Error] Invalid choice! Please select an option between 1 and 20.\n";
                break;
        }
    }
}

// Submenu for Doubly Linked List operations
void handleDoublyLinkedList() {
    DoublyLinkedList dll;
    int choice;

    while (true) {
        cout << "\n********** Operation on Doubly Linked List **********\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Insert Before a Node\n";
        cout << "6. Delete from Beginning\n";
        cout << "7. Delete from End\n";
        cout << "8. Delete from Position\n";
        cout << "9. Delete by Value\n";
        cout << "10. Search\n";
        cout << "11. Update\n";
        cout << "12. Display Forward\n";
        cout << "13. Display Backward\n";
        cout << "14. Count Nodes\n";
        cout << "15. Find Maximum\n";
        cout << "16. Find Minimum\n";
        cout << "17. Find Middle Element\n";
        cout << "18. Reverse\n";
        cout << "19. Sort\n";
        cout << "20. Remove Duplicates\n";
        cout << "21. Exit\n";

        choice = readInteger("Enter the choice:- ");

        switch (choice) {
            case 1: {
                int val = readInteger("Enter value to insert at beginning: ");
                dll.insertAtBeginning(val);
                cout << "[Success] Inserted " << val << " at beginning.\n";
                cout << "Current List (Forward): ";
                dll.displayForward();
                break;
            }
            case 2: {
                int val = readInteger("Enter value to insert at end: ");
                dll.insertAtEnd(val);
                cout << "[Success] Inserted " << val << " at end.\n";
                cout << "Current List (Forward): ";
                dll.displayForward();
                break;
            }
            case 3: {
                int pos = readInteger("Enter 1-based position: ");
                int val = readInteger("Enter value to insert: ");
                if (dll.insertAtPosition(val, pos)) {
                    cout << "[Success] Inserted " << val << " at position " << pos << ".\n";
                } else {
                    cout << "[Error] Invalid position " << pos << ". Position out of range.\n";
                }
                cout << "Current List (Forward): ";
                dll.displayForward();
                break;
            }
            case 4: {
                int target = readInteger("Enter target node value: ");
                int val = readInteger("Enter new value to insert after " + to_string(target) + ": ");
                if (dll.insertAfterValue(target, val)) {
                    cout << "[Success] Inserted " << val << " after node with value " << target << ".\n";
                } else {
                    cout << "[Error] Node with value " << target << " not found in the list.\n";
                }
                cout << "Current List (Forward): ";
                dll.displayForward();
                break;
            }
            case 5: {
                int target = readInteger("Enter target node value: ");
                int val = readInteger("Enter new value to insert before " + to_string(target) + ": ");
                if (dll.insertBeforeValue(target, val)) {
                    cout << "[Success] Inserted " << val << " before node with value " << target << ".\n";
                } else {
                    cout << "[Error] Node with value " << target << " not found in the list.\n";
                }
                cout << "Current List (Forward): ";
                dll.displayForward();
                break;
            }
            case 6: {
                if (dll.deleteFromBeginning()) {
                    cout << "[Success] Deleted node from beginning.\n";
                } else {
                    cout << "[Error] Cannot delete from empty list.\n";
                }
                cout << "Current List (Forward): ";
                dll.displayForward();
                break;
            }
            case 7: {
                if (dll.deleteFromEnd()) {
                    cout << "[Success] Deleted node from end.\n";
                } else {
                    cout << "[Error] Cannot delete from empty list.\n";
                }
                cout << "Current List (Forward): ";
                dll.displayForward();
                break;
            }
            case 8: {
                int pos = readInteger("Enter 1-based position to delete: ");
                if (dll.deleteFromPosition(pos)) {
                    cout << "[Success] Deleted node at position " << pos << ".\n";
                } else {
                    cout << "[Error] Invalid or out-of-range position " << pos << ".\n";
                }
                cout << "Current List (Forward): ";
                dll.displayForward();
                break;
            }
            case 9: {
                int target = readInteger("Enter value to delete: ");
                if (dll.deleteByValue(target)) {
                    cout << "[Success] Deleted first occurrence of value " << target << ".\n";
                } else {
                    cout << "[Error] Value " << target << " not found in the list.\n";
                }
                cout << "Current List (Forward): ";
                dll.displayForward();
                break;
            }
            case 10: {
                int target = readInteger("Enter value to search: ");
                int pos = dll.search(target);
                if (pos != -1) {
                    cout << "[Found] Value " << target << " found at position: " << pos << " (1-based index).\n";
                } else {
                    cout << "[Not Found] Value " << target << " does not exist in the list.\n";
                }
                break;
            }
            case 11: {
                int oldVal = readInteger("Enter existing value to update: ");
                int newVal = readInteger("Enter new replacement value: ");
                if (dll.update(oldVal, newVal)) {
                    cout << "[Success] Updated value " << oldVal << " to " << newVal << ".\n";
                } else {
                    cout << "[Error] Value " << oldVal << " not found in the list.\n";
                }
                cout << "Current List (Forward): ";
                dll.displayForward();
                break;
            }
            case 12: {
                cout << "Doubly Linked List (Forward):\n";
                dll.displayForward();
                break;
            }
            case 13: {
                cout << "Doubly Linked List (Backward):\n";
                dll.displayBackward();
                break;
            }
            case 14: {
                int count = dll.countNodes();
                cout << "Total number of nodes: " << count << "\n";
                break;
            }
            case 15: {
                int maxVal;
                if (dll.findMaximum(maxVal)) {
                    cout << "Maximum value in the list: " << maxVal << "\n";
                } else {
                    cout << "[Error] List is empty. No maximum value.\n";
                }
                break;
            }
            case 16: {
                int minVal;
                if (dll.findMinimum(minVal)) {
                    cout << "Minimum value in the list: " << minVal << "\n";
                } else {
                    cout << "[Error] List is empty. No minimum value.\n";
                }
                break;
            }
            case 17: {
                int midVal, midPos, firstMidVal;
                bool isEven;
                if (dll.findMiddleElement(midVal, midPos, isEven, firstMidVal)) {
                    if (isEven) {
                        cout << "[Middle Element - Even Length List]\n";
                        cout << "  * Standard Convention (Fast/Slow Pointers): Second middle at position " 
                             << midPos << " is: " << midVal << "\n";
                        cout << "  * First middle at position " << (midPos - 1) << " is: " << firstMidVal << "\n";
                    } else {
                        cout << "[Middle Element - Odd Length List]\n";
                        cout << "  * Middle element at position " << midPos << " is: " << midVal << "\n";
                    }
                } else {
                    cout << "[Error] List is empty. No middle element.\n";
                }
                break;
            }
            case 18: {
                cout << "Before Reverse:\n";
                cout << "Forward:  "; dll.displayForward();
                cout << "Backward: "; dll.displayBackward();
                dll.reverse();
                cout << "\nAfter Reverse:\n";
                cout << "Forward:  "; dll.displayForward();
                cout << "Backward: "; dll.displayBackward();
                break;
            }
            case 19: {
                cout << "Before Sort:\n";
                cout << "Forward: "; dll.displayForward();
                dll.sort();
                cout << "After Sort (Ascending):\n";
                cout << "Forward:  "; dll.displayForward();
                cout << "Backward: "; dll.displayBackward();
                break;
            }
            case 20: {
                cout << "Before Removing Duplicates:\n";
                cout << "Forward: "; dll.displayForward();
                int removed = dll.removeDuplicates();
                cout << "[Success] Removed " << removed << " duplicate node(s).\n";
                cout << "After Removing Duplicates:\n";
                cout << "Forward:  "; dll.displayForward();
                cout << "Backward: "; dll.displayBackward();
                break;
            }
            case 21:
                cout << "Returning to Main Application Menu...\n";
                return;
            default:
                cout << "[Error] Invalid choice! Please select an option between 1 and 21.\n";
                break;
        }
    }
}

// Option 3: Compare Singly vs Doubly Linked List
void displayComparison() {
    cout << "\n========================================================================================\n";
    cout << "                    COMPARATIVE ANALYSIS: SINGLY vs DOUBLY LINKED LIST                   \n";
    cout << "========================================================================================\n\n";

    cout << left << setw(28) << "Feature / Parameter" 
         << setw(30) << "Singly Linked List" 
         << setw(30) << "Doubly Linked List" << "\n";
    cout << string(88, '-') << "\n";

    cout << left << setw(28) << "Pointers per Node" 
         << setw(30) << "1 pointer (next)" 
         << setw(30) << "2 pointers (prev, next)" << "\n";

    cout << left << setw(28) << "Memory Overhead" 
         << setw(30) << "Lower (data + 1 pointer)" 
         << setw(30) << "Higher (data + 2 pointers)" << "\n";

    cout << left << setw(28) << "Traversal Direction" 
         << setw(30) << "Unidirectional (Forward only)" 
         << setw(30) << "Bidirectional (Forward & Backward)" << "\n";

    cout << left << setw(28) << "Insert at Beginning" 
         << setw(30) << "O(1)" 
         << setw(30) << "O(1)" << "\n";

    cout << left << setw(28) << "Insert at End" 
         << setw(30) << "O(n) [O(1) if tail stored]" 
         << setw(30) << "O(1) [with tail pointer]" << "\n";

    cout << left << setw(28) << "Delete from Beginning" 
         << setw(30) << "O(1)" 
         << setw(30) << "O(1)" << "\n";

    cout << left << setw(28) << "Delete from End" 
         << setw(30) << "O(n) [must traverse to n-1]" 
         << setw(30) << "O(1) [with tail & prev pointer]" << "\n";

    cout << left << setw(28) << "Delete Given Node Pointer" 
         << setw(30) << "O(n) [needs predecessor node]" 
         << setw(30) << "O(1) [node->prev directly available]" << "\n";

    cout << left << setw(28) << "Implementation Complexity" 
         << setw(30) << "Simpler (fewer pointer updates)" 
         << setw(30) << "Moderate (both links must stay sync)" << "\n";

    cout << left << setw(28) << "Risk of Dangling Links" 
         << setw(30) << "Low" 
         << setw(30) << "Higher if prev/next mismanaged" << "\n";

    cout << left << setw(28) << "Primary Real-World Uses" 
         << setw(30) << "Hash Chaining, Simple Stacks" 
         << setw(30) << "LRU Cache, Browser History, Playlists" << "\n";

    cout << string(88, '-') << "\n\n";

    cout << "KEY TAKEAWAYS:\n";
    cout << "1. Use Singly Linked List when memory conservation is paramount and forward-only\n";
    cout << "   traversal suffices (e.g., Symbol tables, basic queues, chained hashing).\n";
    cout << "2. Use Doubly Linked List when bidirectional navigation and O(1) deletion of an arbitrary\n";
    cout << "   known node are required (e.g., LRU caches, text editor undo/redo, music players).\n\n";

    cout << "Press Enter to return to the Main Application Menu...";
    cin.get();
}

int main() {
    int choice;

    while (true) {
        cout << "\n==================================================\n";
        cout << "           LINKED LIST MANAGEMENT SYSTEM          \n";
        cout << "==================================================\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Compare Singly vs Doubly Linked List\n";
        cout << "4. Exit\n";

        choice = readInteger("Enter your choice: ");

        switch (choice) {
            case 1:
                handleSinglyLinkedList();
                break;
            case 2:
                handleDoublyLinkedList();
                break;
            case 3:
                displayComparison();
                break;
            case 4:
                cout << "\nThank you for using Linked List Management System. Goodbye!\n";
                return 0;
            default:
                cout << "[Error] Invalid selection. Please enter a choice between 1 and 4.\n";
                break;
        }
    }

    return 0;
}
