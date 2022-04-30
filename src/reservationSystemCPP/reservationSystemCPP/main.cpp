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
void DisplayArrayOfSeats (char **ArrayOfSeats, int numberOfRows, int numberOfSeats, int seatsAvailable, int seatCount);
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
    int seatCount = 0;    // Counter for seats taken
    int seatsAvailable;   // Counter for seats available
    
    
    // Get the number of numberOfRows and seats from the user
    // User input checked for valid numbers to create an array using
    // inputValidator()
    numberOfRows = inputValidator("Enter the number for numberOfRows: ");
    numberOfSeats = inputValidator("Enter the number for numberOfSeats: ");
    seatsAvailable = numberOfRows * numberOfSeats;
    // Set up array
    ArrayOfSeats = CreateArrayOfSeats(numberOfRows, numberOfSeats);
    InitializeSeats(ArrayOfSeats, numberOfRows, numberOfSeats);
    DisplayArrayOfSeats(ArrayOfSeats, numberOfRows, numberOfSeats, seatsAvailable, seatCount);
    
    // Get seat selections
    do {
        cout << endl << "Enter a seat selection" << endl;
        cout << "  (example 5F -or- 00 to Quit: ";
        cin  >> rowSelection;    // Get row from user
        cin  >> seatSelection;   // Get seat from user
        
        // Did user quit?
        if (rowSelection == '0')
            continue;              // Skip the rest of the loop
        
        // Convert to uppercase
        seatSelection = toupper(seatSelection);
        
        // Count from zero to work with array
        row = rowSelection - '1';
        // Convert A to 0, B to 1 etc
        seat = seatSelection - 'A';
        
        // Verify seat is available here=======
        if (ArrayOfSeats[row][seat] == '-')
            cout << "That seat has already been selected" << endl;
        else {
            ArrayOfSeats[row][seat] = '-';
            seatsAvailable--;
            seatCount++;
            
        }   // End of else
        //=====================================
        
        // Display seats
        DisplayArrayOfSeats(ArrayOfSeats, numberOfRows, numberOfSeats, seatsAvailable, seatCount);
        
    }   while (rowSelection != '0');   // End of do/while
    
    // Cleanup
    MemoryCleanup(ArrayOfSeats, numberOfRows, numberOfSeats);
    
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
void DisplayArrayOfSeats (char **ArrayOfSeats, int numberOfRows, int numberOfSeats, int seatsAvailable, int seatCount) {
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
    cout << "Seats Available: " << seatsAvailable << endl;
    cout << "Seats Taken    : " << seatCount << endl;
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
