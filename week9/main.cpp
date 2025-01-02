
#include <iostream>

using namespace std;

#include "BST.hpp"

void displayMenu();

int main()
{
    BST bst;
    ItemType target, n;

    int dataArray[10] = { 55, 28, 87, 32, 90, 16, 45, 79, 66, 37 };

    for (int i = 0; i < 10; i++) {
        bst.insert(dataArray[i]);
    }

    bool end = false;
    int option;

    while (!end) {
        displayMenu();
        cout << "Enter option : ";
        cin >> option;
        cout << endl;

        switch (option) {
        default:
            cout << "Option should be between 0 and 7 (inclusive)" << endl;
            break;
        case 0:
            end = true;
            cout << "Ending..." << endl;
            break;
        case 1:
            bst.inOrder();
            cout << endl;
            break;
        case 2:
            cout << "Number to search: ";
            cin >> target;
            cout << endl;
            if (bst.search(target) == nullptr) {
                cout << "Not found";
            } else {
                cout << "Found";
            }
            break;
        case 3:
            cout << "Number to add: ";
            cin >> n;
            cout << endl;
            bst.insert(n);
            break;
        case 4:
            cout << "Number to delete: ";
            cin >> n;
            cout << endl;
            bst.remove(n);
            break;
        case 5:
            cout << "Number of items: " << bst.countNodes() << endl;
            break;
        case 6:
            cout << "Height: " << bst.getHeight() << endl;
            break;
        case 7:
            // show true / false instead of 1 / 0
            cout << boolalpha;
            cout << "Balanced: " << bst.isBalanced() << endl;
            break;
        case 8:
            cout << "Preorder: ";
            bst.preOrder();
            cout << endl;
            break;
        case 9:
            cout << "Postorder: ";
            bst.postOrder();
            cout << endl;
            break;
        }
    }
}

void displayMenu()
{
    cout << endl;
    cout << "Binary Search Tree Demo \n";
    cout << "--------------------------------\n";
    cout << "1 Display all the items in order\n";
    cout << "2 Search for an item            \n";
    cout << "3 Add a new item                \n";
    cout << "4 Delete an item                \n";
    cout << "5 Display total number of items \n";
    cout << "6 Display the height            \n";
    cout << "7 Check if tree is balanced     \n";
    cout << "8 Display preorder              \n";
    cout << "9 Display postorder             \n";
    cout << "0 Exit							 \n";
    cout << "--------------------------------\n";
}
