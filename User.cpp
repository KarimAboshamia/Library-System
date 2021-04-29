#include "User.h"

int User::count = 0;
User::User()
{
    name_ = "";
    age_  = 0;
    email_ = "";
    password_ = "";
    User::count ++;
    User::id_ = User::count;


}

User::User(string name, int age, string email, string password)
{
    name_ = name;
    age_  = age;
    email_ = email;
    password_ = password;
    count++;
    id_ = count;

}
User::User(const User& user)
{
    name_ = user.name_;
    email_ = user.email_;
    age_ = user.age_;
    password_ = user.password_;
    id_ = user.id_;
}

void User::setName(string name)
{
    name_ = name;
}
string User::getName()
{
    return User::name_;
}

void User::setEmail(string email)
{
    email_ = email;
}
string User::getEmail()
{
    return User::email_;
}

void User::setPassword(string password)
{
    password_ = password;
}
string User::getPassword()
{
    return User::email_;
}

void User::setAge(int age)
{
    age_ = age;
}
int User::getAge()
{
    return User::age_;
}

void User::setId(int id)
{
    id_ = id;
}
int User::getId()
{
    return User::id_;
}


bool User::operator==(const User& user)
{

    return name_ == user.name_&& age_ == user.age_ && id_ == user.id_ && email_ == user.email_;
}
ostream &operator <<(ostream &output, User &user)
{
    output<<"======== User "<<user.id_<<" info ========"<<endl;
    output<<"Name: "<<user.name_<<endl;
    output<<"Age: "<<user.age_<<endl;
    output<<"ID: "<<user.id_<<endl;
    output<<"Email: "<< user.email_<<endl;
    output<<"========================================================="<<endl;
    return output;
}
istream &operator>>(istream &input, User &user)
{
    cout<<"Enter the user information in this order"<<endl;
    cout<<"Name Age Email Password (Space separated)"<<endl;

    input>>user.name_>>user.age_>>user.email_>>user.password_;
    cout<<endl;
    return input;

}
