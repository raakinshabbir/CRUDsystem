#include "MyADT.h"
#include "Profile.h"
#include <iostream>
using namespace std; 

int main() {
    //ceate profiles 
    Profile profile1("ken_carson");
    Profile profile2("playboi_carti");
    Profile profile3("homixide_gang");

    Profile profile4("taylor_swift");
    Profile profile5("travis_kelce");

    //create MyADT object
    MyADT myADT;

    //insert profiles into MyADT - INSERT METHOD TEST
    myADT.insert(profile1);
    myADT.insert(profile2);
    myADT.insert(profile3); 

    //search for profile that doesnt exist. - SEARCH METHOD TEST
    Profile searchTarget1("destroy_lonely");
    Profile* result1 = myADT.search(searchTarget1);
    if (result1 != nullptr) {
        cout << "Profile found: " << *result1 << endl;
    } else {
        cout << "Profile not found." << endl;
    }

    //search for profile that exists - SEARCH METHOD TEST
    Profile searchTarget2("ken_carson");
    Profile* result2 = myADT.search(searchTarget2);
    if (result2 != nullptr) {
        cout << "Profile found: " << *result2 << endl;
    } else {
        cout << "Profile not found." << endl;
    }

    Profile searchTarget3("homixide_gang");
    Profile* result3 = myADT.search(searchTarget3);
    if (result3 != nullptr) {
        cout << "Profile found: " << *result3 << endl;
    } else {
        cout << "Profile not found." << endl;
    }
    

    //remove a profile that exists - REMOVE METHOD TEST
    Profile toBeRemoved1("ken_carson");
    bool removed1 = myADT.remove(toBeRemoved1);
    if (removed1) {
        cout << "Profile removed successfully." << endl;
    } else {
        cout << "Profile removal failed." << endl;
    }

    //remove a profile that dont exist - REMOVE METHOD TEST
    Profile toBeRemoved2("central_cee");
    bool removed2 = myADT.remove(toBeRemoved2);
    if (removed2) {
        cout << "Profile removed successfully." << endl;
    } else {
        cout << "Profile removal failed." << endl;
    }

    //remove all the profiles - REMOVE ALL TEST
    myADT.removeAll();
    if (myADT.getElementCount() == 0) {
        cout << "MyADT is empty after removeAll." << endl;
    } else {
        cout << "MyADT is not empty after removeAll." << endl;
    }

    //insert more profiles - INSERT METHOD TEST
    myADT.insert(profile4);
    myADT.insert(profile5);

    //element count - GET ELEMENT COUNT METHOD TEST
    unsigned int count = myADT.getElementCount(); 
    cout << "Number of elements in MyADT: " << count << endl;

    //PRINT METHOD TEST
    myADT.print(); 
    









}