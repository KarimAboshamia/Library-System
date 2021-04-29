#include "UserList.h"
#include "User.h"

UserList::UserList()
{
    capacity = 0;
    usersCount = 0;
    users = new User[0];
}
UserList::UserList(int capacity)
{
    this->capacity = capacity;
    users = new User[this->capacity];
    usersCount = 0;
}

UserList::~UserList()
{
    delete[] users;
    users = NULL;
}
void UserList::setCapacity(int theCapacity)
{
    this->capacity = theCapacity;
    users = new User[this->capacity];
}
void UserList::addUser(User user)
{
    if(usersCount == capacity)
    {
        cout<<"This List is full"<<endl;
        return;
    }
    users[usersCount] = user;
    usersCount++;
}

User& UserList::searchUser(string name)
{
    for(int i = 0; i < usersCount; i++)
    {
        if(users[i].getName() == name)
        {
            return users[i];
        }
    }
    User *emptyUser = new User("empty",0,"","0");
    return *emptyUser;
}

User& UserList::searchUser(int id)
{
    for(int i = 0; i < usersCount; i++)
    {
        if(users[i].getId() == id)
        {
            return users[i];
        }

    }
    User *emptyUser = new User("empty",0,"","0");
    return *emptyUser;

}

void UserList::deleteUser(int id)
{
    for(int i = 0; i < usersCount; i++)
    {
        if(users[i].getId() == id)
        {
            for(int k = i + 1; k < usersCount; k++)
            {
                users[i] = users[k];
                i++;
            }
            break;
        }
    }
    usersCount--;
}

ostream &operator <<(ostream &output, UserList &userList)
{

    for(int i = 0; i < userList.usersCount ; i++)
    {
        output<<userList.users[i];
    }
    return output;
}
