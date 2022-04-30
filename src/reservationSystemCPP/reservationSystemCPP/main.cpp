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
// Added my input validator
int inputValidator (const char *prompt);

// Start main
int main(int argc, const char * argv[]) {
    // Declare variables
    char **ArrayOfSeats;
    int numberOfRows;
    int numberOfSeats;
    char rowSelection;    // 1 to max rows, input from user
    char seatSelection;   // 'A' to max seats, input from user, convert to num
    int row;              // Index into ArrayOfSeats, 0 to numberOfRows -1
    int seat;             // Index into ArrayOfSeats, 0 to numbersOfSeats -1
    
    // Get the number of numberOfRows and seats from the user
    // Might use inputValidator() ======================
    numberOfRows = inputValidator("Enter the number for numberOfRows: ");
    numberOfSeats = inputValidator("Enter the number for numberOfSeats: ");
    /*
    cout << "Enter the number for numberOfRows: ";
    cin  >> numberOfRows;
    cout << "Enter the number for numberOfSeats: " ;
    cin  >> numberOfSeats;*/
    //==================================================
    
    // Set up array
    ArrayOfSeats = CreateArrayOfSeats(numberOfRows, numberOfSeats);
    InitializeSeats(ArrayOfSeats, numberOfRows, numberOfSeats);
    DisplayArrayOfSeats(ArrayOfSeats, numberOfRows, numberOfSeats);
    
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

// Start inputValidator function
int inputValidator (const char *prompt) {
    // Declare variables
    // Return value used for number
    int inputValue = 0;
    // Flag for loop
    bool isValid;
    // Start loop for valid input
    do {
        // Assume valid input
        isValid = true;
        cout << prompt;
        cin >> inputValue;
        // Is input a number?
        if (!cin) {
            cout << "A numeric value is expected..." << endl << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            isValid = false;
        }   // End of !number
        // Is input positive?
        else if (inputValue <= 0) {
            cout << "Number must be greater than zero..." << endl << endl;
            isValid = false;
        }   // End of negative input
    } while (!isValid);   // Loop until input is valid
    
    // Returns value to number
    return inputValue;
}   // End of inputValidator
