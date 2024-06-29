

#ifndef PROFILE_H
#define PROFILE_H

#include <string>

using std::string;
using std::ostream;


class Profile {
     
private:

    inline static const string defaultStrValue = "tbd";

    string userName;
    string name; 
    string email;
    string birthday;

    void setUserName(const string aUserName);
    
    
public:

    // Default Constructor
    // Description: Creates a Profile object. 
    // Postcondition: userName, name, email and birthday set to defaultStrValue.
    Profile();

    // Parameterized Constructor
    // Description: Creates a Profile object with the given userName.
    // Postcondition: If aUserName is not valid, then the member attribute userName it set to defaultStrValue.
    //                All other member attributes are set to defaultStrValue. 
    Profile(string aUserName);
    
    // Parameterized Constructor
    // Description: Creates a Profile object with the given userName, name, email and birthday.
    // Postcondition: If aUserName is not valid, then the member attribute userName is set to defaultStrValue.
    //                All other member attributes are set to the given parameters, respectively.
    Profile(string aUserName, string aName, string anEmail, string aBirthday);


    // Getters and setters
    
    // Description: Returns Profile object's userName.
    string getUserName() const;
    
    // Description: Returns Profile object's name.
    string getName() const;

    // Description: Returns Profile object's email.
    string getEmail() const;

    // Description: Returns Profile object's birthday.
    string getBirthday() const;

    // Description: Returns defaultStrValue.
    static string getDefaultStrValue();
    
    // Description: Sets the Profile object's name.
    // Postcondition: name is set to aName. No need to validate aName.
    void setName(const string aName);

    // Description: Sets the Profile object's email.
    // Postcondition: email is set to anEmail. No need to validate anEmail.
    void setEmail(const string anEmail);

    // Description: Sets the Profile object's birthday.
    // Postcondition: birthday is set to aBirthday. No need to validate aBirthday.
    void setBirthday(const string aBirthday);


    // Overloaded Operators
    // Description: Comparison (equality) operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if both Profile objects have the same userName.
    bool operator==(const Profile & rhs);

    // Description: Greater than operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if the userName of "this" Profile object is > the userName of "rhs" 
    //              Profile object, i.e., the userName of "this" Profile object goes after 
    //              the userName of "rhs" Profile object when ordered in ascending alpha order.
    bool operator > (const Profile & rhs);

    // Description: Lesser than operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if the userName of "this" Profile object is < the userName of "rhs" 
    //              Profile object, i.e., the userName of "this" Profile object goes before 
    //              the userName of "rhs" Profile object when ordered in ascending alpha order.
    bool operator < (const Profile & rhs);


    // Utility methods
    // Description: Returns the first character (a lower case letter) of userName.
    char getSearchKey() const;

    // Description: Prints the content of "this" Profile object as follows:
    //              <userName>, <name>, <email>, born on <birthday>
    friend ostream & operator<<(ostream & os, const Profile & p);

};
// end of Profile.h
#endif
