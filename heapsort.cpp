#include <iostream>
using namespace std;

class Heap {
    int a[50], b[50], n; // Arrays for heap and sorted elements, 'n' is the size
public:
    Heap() {
        n = -1; // Initialize heap size to -1 (empty heap)
    }

    void insheap(int item); // Insert into the heap
    int delheap();          // Delete the root element from the heap
    void display();         // Display the heap
    void heapsort();        // Perform heap sort
};
// Function to insert an element into the heap
void Heap::insheap(int item) {
    int i, j;
    n++;           // Increment the size of the heap
    i = n;         // Start from the end of the heap
    while (i > 0) {
        j = (i - 1) / 2;  // Find the parent of the current node
        if (item <= a[j]) {
            a[i] = item;  // If item is smaller than or equal to the parent, place it
            return;
        }
        a[i] = a[j];      // Move parent down
        i = j;            // Move up to the parent
    }
    a[0] = item;          // Place the item at the root
}
// Function to delete the root element (maximum) from the heap
int Heap::delheap() {
    int left, right, last, i, item;
    item = a[0];       // Store the root (max element)
    last = a[n];       // Store the last element
    n--;               // Decrease the size of the heap
    i = 0;             // Start from the root
    left = 1;          // Left child index
    right = 2;         // Right child index

    while (right <= n) {           // While the current node has two children
        if (last >= a[left] && last >= a[right]) { // If last is greater than both children
            a[i] = last;
            return item;
        }
        if (a[right] <= a[left]) { // If left child is greater than or equal to right
            a[i] = a[left];
            i = left;              // Move to the left child
        } else {                   // If right child is greater
            a[i] = a[right];
            i = right;             // Move to the right child
        }
        left = (2 * i) + 1;        // Update left child index
        right = left + 1;          // Update right child index
    }
    if (left == n && last < a[left]) { // If only one child is present
        a[i] = a[left];
        i = left;
    }
    a[i] = last;       // Place the last element
    return item;       // Return the root element
}
// Function to display the heap
void Heap::display() {
    cout << "\nHeap elements are:\n";
    for (int i = 0; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
// Function to perform heap sort
void Heap::heapsort() {
    int item, ch, temp, j = 0;

    do {
        cout << "\nEnter item to insert: ";
        cin >> item;              // Declare and use the variable 'item'
        insheap(item);            // Insert into the heap
        cout << "\nDo you want to insert again? Press 1 for Yes, 0 for No: ";
        cin >> ch;
    } while (ch != 0);

    cout << "\nBefore sorting:\n";
    display();                    // Display the heap before sorting

    while (n != -1) {
        b[j] = delheap();         // Delete the root and store it in the sorted array
        j++;
    }

    cout << "\nAfter sorting:\n";
    for (int i = j - 1; i >= 0; i--) { // Display the sorted elements in descending order
        cout << b[i] << " ";
    }
    cout << endl;
}
// Main function
int main() {
    Heap h;
    h.heapsort(); // Perform heap sort
    return 0;
}
