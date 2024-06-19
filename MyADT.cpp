/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * 
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and 
 *                    the elements are kept in ascending sort order of search key.
 *                  - Each element is unique (no duplicates). 
 *                  - Its data structure (CDT) is not expandable. This signifies that 
 *                    when this data collection becomes full, you do not have to resize 
 *                    its data structure (not in this Assignment 1). 
 *
 * Author: AL and Raakin Shabbir
 * Last modified on: Jan. 2024
 */



#include <iostream>
#include <cctype>
#include "MyADT.h"     // Header file of MyADT file
#include "Profile.h"   // Header file of Profile class

using std::cout;
using std::endl;

// Default constructor.
   // cout << "MyADT::default constructor executed!" << endl;   // For testing purposes ...
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   
MyADT::MyADT() {
    //initialize elements and elementCount to nullptr and 0
    for (unsigned int i = 0; i < MAX_ALPHA; i++) {
        elements[i] = nullptr;
        elementCount[i] = 0;
    }
}

// Copy constructor - Covered in Lab 3
   // cout << "MyADT::copy constructor executed!" << endl; // For testing purposes ... 
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
    
//copy constructor 
MyADT::MyADT(const MyADT& rhs) {

//copy the elements of rhs to elements 
    for(unsigned int i = 0; i < MAX_ALPHA; i++){
        elementCount[i] = rhs.elementCount[i]; 

        elements[i] = new Profile[rhs.elementCount[i]]; 
         for (unsigned int j = 0; j < rhs.elementCount[i]; j++) {
            elements[i][j] = rhs.elements[i][j];
        }
    }
}

// Overloaded assignment operator - Covered in Lab 5
// Therefore, we shall not be overloading this operator in our Assignment 1
// MyADT & MyADT::operator=(const MyADT& rhs) {
   // cout << "MyADT::operator= executed!" << endl; // For testing purposes ... 
   // You can also use the above to figure out when this overloaded assignment = operator is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   
   /* Put your code here */

//}

// Destructor
// Description: Destroys this object, releasing heap-allocated memory.
   // cout << "MyADT::destructor" << endl;  // For testing purposes ...
   // You can also use the above to figure out when this destructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

MyADT::~MyADT() {
    for (unsigned int i = 0; i < MAX_ALPHA; i++) {
        delete[] elements[i];
    }
}


// getElementCount function
// Description: Returns the total number of elements currently stored in the data collection MyADT.  
unsigned int MyADT::getElementCount() const {
    unsigned int numberOfElements = 0;
    //increment numberOfElements to match the elementCount
    for (unsigned int i = 0; i < MAX_ALPHA; i++) {
        numberOfElements += elementCount[i];
    }
    return numberOfElements;
}

// insert function 
// Description: Inserts an element in the data collection MyADT.
// Precondition: newElement must not already be in the data collection MyADT.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull, otherwise "false". 
bool MyADT::insert(const Profile& newElement) {
    char searchKey = newElement.getSearchKey();
    //change the first letter of the username to a number in order to manipulate it into an array
    unsigned int arrayIndex = searchKey - 'a';
    unsigned int insertIndex = 0;
    
    //check if space to insert
    if (elementCount[arrayIndex] < MAX_ELEMENTS) {
        //find the correct place to place the username
        for (insertIndex = 0; insertIndex < elementCount[arrayIndex]; insertIndex++) {
            if (elements[arrayIndex][insertIndex] > newElement) {
                break;
            }
            if (elements[arrayIndex][insertIndex] == newElement) {
                return false;
            }
        }
    
    //if the element already exists then return false
    if(search(newElement) != nullptr){
        return false; 
        }
    } 
        //allocate new memory for the array if it's the first element
        if (elementCount[arrayIndex] == 0) {
            elements[arrayIndex] = new Profile[MAX_ELEMENTS];
        }
        //shift elements to make space for the new element
        for (unsigned int i = elementCount[arrayIndex]; i > insertIndex; i--) {
            elements[arrayIndex][i] = elements[arrayIndex][i - 1];
        }
        //insert the new element at the correct position
        elements[arrayIndex][insertIndex] = newElement;
        elementCount[arrayIndex]++;
        return true;
}


//remove function
// Description: Removes an element from the data collection MyADT. 
// Postcondition: toBeRemoved (if found) is removed and the appropriate elementCount is decremented.
//                Returns "true" when the removal is successfull, otherwise "false".  
bool MyADT::remove(const Profile& toBeRemoved) {
    char searchKey = toBeRemoved.getSearchKey();
    unsigned int arrayIndex = searchKey - 'a';
    //where to shift the items when there is a gap due to removal of a username
    int gapIndex = -1;
    for (unsigned int i = 0; i < elementCount[arrayIndex]; i++) {
        if (elements[arrayIndex][i] == toBeRemoved) {
            gapIndex = i;
            break;
        }
    }
    if (gapIndex != -1) {
        for (unsigned int i = gapIndex; i < elementCount[arrayIndex] - 1; i++) {
            elements[arrayIndex][i] = elements[arrayIndex][i + 1];
        }
        elementCount[arrayIndex]--;
        return true;
    } else {
        return false;
    }
}

// removeAll function 
// Description: Removes all elements from the data collection MyADT. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed). 
void MyADT::removeAll() {
    for (unsigned int i = 0; i < MAX_ALPHA; i++) {
        delete[] elements[i];
        elements[i] = nullptr;
        elementCount[i] = 0;
    }
}

// search function 
// Description: Searches for target element in the data collection MyADT. 
//              Returns a pointer to the element if found, otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {
    char searchKey = target.getSearchKey();
    unsigned int arrayIndex = searchKey - 'a';
    for (unsigned int i = 0; i < elementCount[arrayIndex]; i++) {
        if (elements[arrayIndex][i] == target) {
            return &elements[arrayIndex][i];
        }
    }
    return nullptr;
}

// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
//print function 
void MyADT::print() {
    for (unsigned int i = 0; i < MAX_ALPHA; i++){
        for(unsigned int j = 0; j < elementCount[i]; j++){
            cout << elements[i][j]; 
        }
    }
}

//  End of implementation file