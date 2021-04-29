#ifndef USERLIST_H
#define USERLIST_H

#include<cstring>
#include<iostream>
#include "User.h"

class UserList
{
private:
    User* users;
    int capacity;
    int usersCount;
public:
    UserList();//Default constructor
    UserList(int capacity);// Constructor with parameter capacity, that initialize "capacity", "usersCount", and array
    void setCapacity(int theCapacity); //setter for the capacity, with return type void, and parameter theCapacity
    void addUser(User user); // A function with return type "void", that adds user to user list, and takes an object of type User as parameter
    User& searchUser(string name);// A function with return type "reference to User", that searches for user in user list, and takes the name of user as a parameter
    User& searchUser(int id); // A function with return type "reference to User", that searches for user in user list , and takes the id of user as a parameter
    void deleteUser(int id); // A function with return type "void", that deletes user from user list, and takes the user id as a parameter
    friend ostream &operator<<(ostream &output, UserList &userList);// output stream overloading
    ~UserList();//Destructor

};

#endif // USERLIST_H
