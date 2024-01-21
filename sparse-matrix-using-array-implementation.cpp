// By Jahnavi Reddy
#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int sparseMatrix[rows][cols];

    cout << "Enter elements of the sparse matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> sparseMatrix[i][j];

    int size = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (sparseMatrix[i][j] != 0)
                size++;

    int compactMatrix[3][size];

    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }

    cout << "The compact matrix is:\n";
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<size; j++)
            cout <<" "<< compactMatrix[i][j];

        cout <<"\n";
    }
    return 0;
}
