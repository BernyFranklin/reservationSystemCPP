/*
 * reservationSystemCPP Version#1.0
 * Frank Bernal
 * CIS 054 C/C++ Programming
 * Input: rowSelection, seatSelection
 * Output: available seating
 * 29 April 2022
 */

#include <iostream>
#include <cctype>
using namespace std;

// Function declorations (prototypes)
char **CreateArrayOfSeats (int numberOfRows, int numberOfSeats);
void InitializeSeats (char **ArrayOfSeats, int numberOfRows, int numberOfSeats);
void DisplayArrayOfSeats (char **ArrayOfSeats, int numberOfRows, int numberOfSeats);
void MemoryCleanup (char **ArrayOfSeats, int numberOfRows, int numberOfSeats);

// Start main
int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}   // End of main

// Start of **CreateArrayOfSeats
char **CreateArrayOfSeats (int numberOfRows, int numberOfSeats) {
    // ** means pointers to pointers
    char **ArrayOfSeats;
    
    // Create array of numberOfRows
    ArrayOfSeats = new char*[numberOfRows];
    
    // Create an array of seats for each row
    for (int r = 0; r < numberOfRows; r++)
        ArrayOfSeats[r] = new char[numberOfSeats];
    
    // Return pointer to the array back to main
    return ArrayOfSeats;
    
}   // End of **CreateArrayOfSeats

// Start InitializeSeats
void InitializeSeats (char **ArrayOfSeats, int numberOfRows, int numberOfSeats) {
    // Initialize the data for each row
    for (int r = 0; r < numberOfRows; r++) {
        for (int s = 0; s < numberOfSeats; s++)
            ArrayOfSeats[r][s] = 'A' + s;   // Put A B C etc in each row
    }   // End of outer loop
    
}   // End of InitializeSeats

// Start of DisplayArrayOfSeats
void DisplayArrayOfSeats (char **ArrayOfSeats, int numberOfRows, int numberOfSeats) {
    // For each row
    for (int r = 0; r < numberOfRows; r++) {
        cout.width(2);
        cout << r+1 << ' ';   // Display row count starting at 1
        // Display info for each seat
        for (int s = 0; s < numberOfSeats; s++)
            cout << ArrayOfSeats[r][s] << ' ';
        // New line each row
        cout << endl;
    }   // End of loop
    
}   // End of DisplayArrayOfSeats

// Start MemoryCleanup
void MemoryCleanup (char **ArrayOfSeats, int numberOfRows, int numberOfSeats) {
    // Delete each row individually
    for (int r = 0; r < numberOfRows; r++)
        delete [] ArrayOfSeats[r];
    // Delete the row array
    delete [] ArrayOfSeats;
}   // End of MemoryCleanup
