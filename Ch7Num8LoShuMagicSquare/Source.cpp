/************************************************
** Author: Andrea Hayes
** Date: April 30, 2020
** Purpose: Check if an array is a Lo Shu Magic Square
** Input: User numbers, Two-dimensional array
** Processing: Pass array through function and add elements in array
** Output: Determine wether the array is a Lo Shu Magic Square
*************************************************/
#include <iostream>
#include <iomanip>

const int ROW = 3, COL = 3;
int getInput();
bool isSquare(const int[ROW][COL]);
void showArray(const int[ROW][COL]);

using namespace std;

int main() {
   
    int square[ROW][COL];
    bool status;
    
    //Get numbers and put them in the array
    cout << "Enter the numbers 1-9 in any order" << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
           square[i][j] = getInput();
        }
    } 

    // Call the function to display the numbers
    showArray(square);

    // Call the function to determine if magic square and display.
    status = isSquare(square);
    if (status == true) {
        cout << "This is a Lo Shu Magic Square";
    }
    else {
        cout << "This is NOT a Lo Shu Magic Square";
    }
    
    return 0;
}
// Function to get numbers
int getInput()
{
    int number;
    do {
        cout << "Enter number: ";
        cin >> number;
        if (number < 0 || number>10) {
            cout << "Enter a number between 1-9" << endl;
        }
    } while (number < 0 || number>9);
    return number;
}

// Function to show the numbers formated in a 3x3 square
void showArray(const int square[ROW][COL])
{
    for (int i = 0; i < ROW; i++) 
    {
        for (int j = 0; j < COL; j++) 
        {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
}
// Function to determine if Lo Shu Magic Square
bool isSquare(const int square[ROW][COL])
{
    bool status = true;
    int total = 0, currentTotal = 0;

    // sum rows
    for (int i = 0; i < ROW; i++)
    {
        currentTotal = 0;
        for (int j = 0; j < COL; j++)
        {
            currentTotal += square[i][j];
        }
        if (i == 0) {
            total = currentTotal;
        }
        if (total != currentTotal) {
            status = false;
        }
    }
    // sum columns
    for (int i = 0; i < COL; i++)
    {
        currentTotal = 0;
        for (int j = 0; j < ROW; j++)
        {
            currentTotal += square[j][i];
        }
        if (total != currentTotal) {
            status = false;
        }
    }
    // sum diagonal
    currentTotal = square[0][0] + square[1][1] + square[2][2];
    if (total != currentTotal) {
        status = false;
    }
    currentTotal = square[0][2] + square[1][1] + square[2][0];
    if (total != currentTotal) {
        status = false;
    }
    return status;
}
