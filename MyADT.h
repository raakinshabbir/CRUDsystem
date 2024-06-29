
 
 
#ifndef MyADT_H
#define MyADT_H

/*
 * You can add more #include statements, if needed.
 */
 
#include <string>
#include "Profile.h"


class MyADT {

private:

 
    constexpr static unsigned int MAX_ALPHA = 26;   // 26 letters in the alphabet 
    constexpr static unsigned int MAX_ELEMENTS = 5; // Small capacity so can test when data collection becomes full 
                                                    // Feel free to change this MAX_ELEMENTS value.
    Profile * elements[MAX_ALPHA];                  // MAX_ALPHA arrays of elements 
    unsigned int elementCount[MAX_ALPHA];           // Current element count in each of the MAX_ALPHA arrays of elements



      
public:


    // Default constructor
    MyADT();

    MyADT(const MyADT& rhs);

    
    // Destructor
    // Description: Destroys this object, releasing heap-allocated memory.
    ~MyADT();

    // Description: Returns the total number of elements currently stored in the data collection MyADT.  
    unsigned int getElementCount() const;

    // Description: Inserts an element in the data collection MyADT.
    // Precondition: newElement must not already be in the data collection MyADT.  
    // Postcondition: newElement inserted and the appropriate elementCount has been incremented.
    //                Returns "true" when the insertion is successfull, otherwise "false".
    bool insert(const Profile& newElement);

    // Description: Removes an element from the data collection MyADT. 
    // Postcondition: toBeRemoved (if found) is removed and the appropriate elementCount is decremented.
    //                Returns "true" when the removal is successfull, otherwise "false".    
    bool remove(const Profile& toBeRemoved);
	
    // Description: Removes all elements from the data collection MyADT. 
    // Postcondition: MyADT reverts back to its initialization state, i.e., 
    //                the state it is in once it has been constructed (once
    //                the default constructor has executed). 
    void removeAll();
   
    // Description: Searches for target element in the data collection MyADT. 
    //              Returns a pointer to the element if found, otherwise, returns nullptr.
    Profile * search(const Profile& target);
    
    // Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
    // ***For Testing Purposes - Not part of this class' public interface.***
    void print();
   

}; // end MyADT
#endif
