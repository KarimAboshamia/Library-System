///////////////////////////////////////////////////////
//  Author      : [Kareem Mostafa Aboshamia] <E-mail: Karimaboshamia@gmail.com>
//  Project Name: Online library system
//  Description :
//      This project uses 4 classes in order to create an online library system
//      which allows the user to create a list of users, delete users, and modify it, as well as
//      creating a list of books and assign authors to this books list from the users list,
//      as well as having full control of the books list.
//
//  Created On  : 12/24/2020 9:37:38 PM
///////////////////////////////////////////////////////

#include <iostream>
#include "User.h"
#include "Book.h"
#include <vector>
#include "UserList.h"
#include "BookList.h"

using namespace std;

int main()
{
    int men;
    int numOfUsers;
    int numOfBooks;
    bool state = true;
    bool state2 = true;
    UserList list1;
    BookList listOfBooks;

    while(true)
    {
        cout<<"Select one of the following choices:"<<endl;
        cout<< "1- Books Menu"<<endl;
        cout<< "2- Users Menu"<<endl;
        cout<< "3- Exit"<<endl;
        cin>>men;
        if(men == 1)
        {
            if(state2 == true)
            {

                cout<<"How many books will be added?"<<endl;
                cin>>numOfBooks;
                listOfBooks.setCapacity(numOfBooks);
                Book::count-=numOfBooks;
                state2 = false;
            }
            while(true)
            {
                cout<<"BOOKS MENU"<<endl;
                cout<<"1- Create a book and add it to the list"<<endl;
                cout<<"2- Search for a book"<<endl;
                cout<<"3- Display all books (with book rating)"<<endl;
                cout<<"4- Get the highest rating book"<<endl;
                cout<<"5- Get all books of a user"<<endl;
                cout<<"6- Copy the current Book List to a new Book List and switch to it"<<endl;
                cout<<"7- Back to the main menu"<<endl;
                int ind;
                cin>>ind;
                if(ind == 1)
                {
                    Book book;
                    cin>>book;
                    int assignAuth;
                    while(true)
                    {
                        cout<<"1- Assign author"<<endl;
                        cout<<"2- Continue"<<endl;
                        cin>>assignAuth;
                        if(assignAuth == 1)
                        {
                            cout<<"Enter author (user) ID:"<<endl;
                            int authid;
                            cin>>authid;
                            if(list1.searchUser(authid).getName() == "empty")
                            {
                                cout<<"No Author found with ID = "<< authid <<endl;
                            }
                            else
                            {
                                book.setAuthor(list1.searchUser(authid));
                                listOfBooks.addBook(book);
                                break;
                            }
                        }
                        else
                        {
                            listOfBooks.addBook(book);
                            break;
                        }
                    }
                }
                else if (ind == 2)
                {
                    cout<<"SEARCH FOR A BOOK"<<endl;
                    cout<<"1- Search by name"<<endl;
                    cout<<"2- Search by ID"<<endl;
                    cout<<"3- return to Books Menu"<<endl;
                    int dum;
                    cin>>dum;
                    if(dum == 1)
                    {
                        string name;
                        cout<<"Enter Name"<<endl;
                        cin>>name;
                        if(listOfBooks.searchBook(name).getTitle() == "empty")
                        {
                            cout<<"We didn't find a book with this name"<<endl;
                        }
                        else
                        {

                            cout<<listOfBooks.searchBook(name)<<endl;
                            int currentBookId = listOfBooks.searchBook(name).getId();
                            /*
                            I will use the book "ID" to determine which book is active,
                            because I can't use name in case the user has changed the book name
                            "I won't be able to find the book"
                            */
                            while(true)
                            {
                                cout<<"1- Update author"<<endl;
                                cout<<"2- Update name"<<endl;
                                cout<<"3- Update category"<<endl;
                                cout<<"4- Delete Book"<<endl;
                                cout<<"5- Rate Book"<<endl;
                                cout<<"6- Get Back to books menu"<<endl;
                                int choose;
                                cin>>choose;
                                if(choose == 1)
                                {
                                    cout<<"Enter author (user) ID:"<<endl;
                                    int authid;
                                    cin>>authid;
                                    if(list1.searchUser(authid).getName() == "empty")
                                    {
                                        cout<<"No Author found with ID = "<< authid <<endl;
                                    }
                                    else
                                    {
                                        listOfBooks.searchBook(currentBookId).setAuthor(list1.searchUser(authid));
                                    }
                                }
                                else if(choose == 2)
                                {
                                    cout<<"Enter new name"<<endl;
                                    string newName;
                                    cin>>newName;
                                    listOfBooks.searchBook(currentBookId).setTitle(newName);
                                }
                                else if(choose == 3)
                                {
                                    cout<<"Enter new category"<<endl;
                                    string newCategory;
                                    cin>>newCategory;
                                    listOfBooks.searchBook(currentBookId).setCategory(newCategory);
                                }
                                else if(choose == 4)
                                {
                                    listOfBooks.deleteBook(currentBookId);
                                }
                                else if(choose == 5)
                                {
                                    cout<<"Enter Rating Value"<<endl;
                                    int rateBook;
                                    cin>>rateBook;
                                    listOfBooks.searchBook(currentBookId).setRating(rateBook);
                                }
                                else if(choose == 6)
                                {
                                    break;
                                }
                            }
                        }
                    }
                    else if (dum == 2)
                    {
                        int bookI;
                        cout<<"Enter ID"<<endl;
                        cin>>bookI;
                        if(listOfBooks.searchBook(bookI).getTitle() == "empty")
                        {
                            cout<<"We didn't find a book with this ID"<<endl;
                        }
                        else
                        {

                            cout<<listOfBooks.searchBook(bookI)<<endl;
                            int currentBookId = listOfBooks.searchBook(bookI).getId();
                            /*
                            I will use the book "ID" to determine which book is active,
                            because I can't use name in case the user has changed the book name
                            "I won't be able to find the book"
                            */
                            while(true)
                            {
                                cout<<"1- Update author"<<endl;
                                cout<<"2- Update name"<<endl;
                                cout<<"3- Update category"<<endl;
                                cout<<"4- Delete Book"<<endl;
                                cout<<"5- Rate Book"<<endl;
                                cout<<"6- Get Back to books menu"<<endl;
                                int choose;
                                cin>>choose;
                                if(choose == 1)
                                {
                                    cout<<"Enter author (user) ID:"<<endl;
                                    int authid;
                                    cin>>authid;
                                    if(list1.searchUser(authid).getName() == "empty")
                                    {
                                        cout<<"No Author found with ID = "<< authid <<endl;
                                    }
                                    else
                                    {
                                        listOfBooks.searchBook(currentBookId).setAuthor(list1.searchUser(authid));
                                    }
                                }
                                else if(choose == 2)
                                {
                                    cout<<"Enter new name"<<endl;
                                    string newName;
                                    cin>>newName;
                                    listOfBooks.searchBook(currentBookId).setTitle(newName);
                                }
                                else if(choose == 3)
                                {
                                    cout<<"Enter new category"<<endl;
                                    string newCategory;
                                    cin>>newCategory;
                                    listOfBooks.searchBook(currentBookId).setCategory(newCategory);
                                }
                                else if(choose == 4)
                                {
                                    listOfBooks.deleteBook(currentBookId);
                                }
                                else if(choose == 5)
                                {
                                    cout<<"Enter Rating Value"<<endl;
                                    int rateBook;
                                    cin>>rateBook;
                                    listOfBooks.searchBook(currentBookId).setRating(rateBook);
                                }
                                else if(choose == 6)
                                {
                                    break;
                                }
                            }
                        }

                    }
                }
                else if(ind == 3)
                {
                    cout<<listOfBooks<<endl;
                }
                else if(ind == 4)
                {
                    BookList printList(1);
                    printList[0] = listOfBooks.getTheHighestRatedBook();
                    printList.setBookCount(1);
                    cout<<printList;

                }
                else if(ind == 5)
                {
                    cout<<"Enter user ID"<<endl;
                    int tempId;
                    cin>>tempId;
                    for(int i=0; i<listOfBooks.getBooksCount(); i++)
                    {

                        if((listOfBooks.getBooksForUser(list1.searchUser(tempId))[i].getTitle()) == "")
                        {

                        }
                        else
                        {
                            cout<<*(listOfBooks.getBooksForUser(list1.searchUser(tempId))+i)<<endl;
                        }
                    }

                }
                else if(ind == 6)
                {
                    BookList newList(listOfBooks);
                    listOfBooks = newList;
                    cout<<"Copied current list ("<<listOfBooks.getBooksCount()<<" books) to a new List and switched to it"<<endl;
                }
                else
                {
                    break;
                }
            }
        }
        else if(men == 2)
        {
            if(state == true)
            {
                cout<<"How many users will be added?"<<endl;
                cin>>numOfUsers;
                list1.setCapacity(numOfUsers);
                User::count-=numOfUsers;
                state = false;
            }
            while(true)
            {
                cout<<"USERS MENU"<<endl;
                cout<<"1- Create a USER and add it to the list"<<endl;
                cout<<"2- Search for a user"<<endl;
                cout<<"3- Display all users"<<endl;
                cout<<"4- Back to the main menu"<<endl;
                int index;
                cin>>index;
                if(index == 1)
                {
                    User user;
                    cin>>user;
                    list1.addUser(user);
                }
                else if(index == 2)
                {
                    while(true)
                    {
                        cout<<"SEARCH FOR A USER"<<endl;
                        cout<<"1- Search by name"<<endl;
                        cout<<"2- Search by ID"<<endl;
                        cout<<"3- Return to Users Menu"<<endl;
                        int searchIndex;
                        cin>>searchIndex;
                        if(searchIndex == 1)
                        {
                            string name;
                            cout<<"Enter a name:"<<endl;
                            cin>>name;
                            if(list1.searchUser(name).getName() == "empty")
                            {
                                cout<<"We didn't find a user with this name"<<endl;
                            }
                            else
                            {
                                cout<<list1.searchUser(name);
                                cout<<"1- Delete user"<<endl;
                                cout<<"2- Return to Users Menu"<<endl;
                                int operation;
                                cin>>operation;
                                if(operation == 1)
                                {
                                    list1.deleteUser(list1.searchUser(name).getId());
                                }
                            }

                        }
                        else if(searchIndex == 2)
                        {
                            int num;
                            cout<<"Enter an ID:"<<endl;
                            cin>>num;
                            if(list1.searchUser(num).getName() == "empty")
                            {
                                cout<<"We didn't find a user with this ID"<<endl;
                            }
                            else
                            {
                                cout<<list1.searchUser(num);
                                cout<<"1- Delete user"<<endl;
                                cout<<"2- Return to Users Menu"<<endl;
                                int operation;
                                cin>>operation;
                                if(operation == 1)
                                {
                                    list1.deleteUser(num);
                                }
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else if(index == 3)
                {
                    cout<<list1<<endl;
                }
                else
                {
                    cout<<"============================================="<<endl;
                    break;
                }
            }

        }
        else
        {
            return 0;
        }
    }
}
