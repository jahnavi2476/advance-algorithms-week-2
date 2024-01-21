// By Jahnavi Reddy

#include <iostream>
#include <sstream>
using namespace std;

class SparseElement {
public:
    int row;
    int col;
    int value;
    SparseElement* next;

    SparseElement(int r, int c, int val) : row(r), col(c), value(val), next(nullptr) {}
};

void addElement(SparseElement*& head, int rowIndex, int colIndex, int data) {
    SparseElement* newNode = new SparseElement(rowIndex, colIndex, data);

    if (head == nullptr) {
        head = newNode;
    } else {
        SparseElement* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displaySparseMatrix(SparseElement* head) {
    SparseElement* current = head;

    cout << "Sparse Matrix Representation:" << endl;
    while (current != nullptr) {
        cout << "Row: " << current->row << ", Col: " << current->col << ", Value: " << current->value << endl;
        current = current->next;
    }
}

int main() {
    int numRows, numCols;

    cout << "Enter the number of rows and columns (space-separated): ";
    cin >> numRows >> numCols;
    cin.ignore();

    SparseElement* sparseList = nullptr;
    string inputRow;

    for (int i = 0; i < numRows; i++) {
        cout << "Enter values for row " << i << " (space-separated): ";
        getline(cin, inputRow);

        istringstream iss(inputRow);
        int j = 0;
        int inputValue;

        while (iss >> inputValue) {
            if (inputValue != 0) {
                addElement(sparseList, i, j, inputValue);
            }
            j++;
        }
    }

    displaySparseMatrix(sparseList);

    SparseElement* current = sparseList;
    while (current != nullptr) {
        SparseElement* nextElement = current->next;
        delete current;
        current = nextElement;
    }

    return 0;
}
