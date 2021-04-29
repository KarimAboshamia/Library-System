#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "Book.h"


class BookList
{
private:
    Book* books;
    int capacity;
    int booksCount;
public:

    BookList(); //Default Constructor
    BookList(const BookList& anotherList);//copy constructor "Copy the values from one object to another"
    BookList(int capacity);//Constructor with parameter capacity that initialize the capacity variable as well as booksCount, and the dynamic array

    void setCapacity(int theCapacity); // A function with return type "void", it is used to setCapacity
    void addBook(Book book); // A function with return type "void", it adds book to the book list, and take an object of type "Book" as a parameter
    void deleteBook(int id); // A function with return type "void" it deletesBook from the list of books, and takes the book that must be deleted 'id' as a parameter

    int getBooksCount() //Getter for booksCount with return type int
    {
        return booksCount;
    }

    Book& searchBook(string name); //A function with return type "reference to Book", it searches for a book using it's name, 'parameter is the book name'
    Book& searchBook(int id); // A function with return type "reference to Book", it searches for a books using it's id, 'parameter is the book id'
    Book *getBooksForUser(User);// A function with return type "Pointer to Book", it gets all the books for a specific user, and takes User object as parameter
    Book& getTheHighestRatedBook();// A function with return type "reference to Book", it searches for the highest rated book, and it takes no parameter

    void setBookCount(int num)// A function with return type "void, it sets booksCount variable
    {
        booksCount = num;
    }

    Book &operator[](int position); //subscript operator overloading
    friend ostream &operator<<(ostream &output, BookList &booklist);//output stream operator overloading

    ~BookList();// destructor
};

#endif // BOOKLIST_H
