#include "BookList.h"
BookList::BookList()
{
    capacity = 0;
    booksCount = 0;
    books = new Book[0];
}
BookList::BookList(int capacity)
{
    this->capacity = capacity;
    booksCount = 0;
    books = new Book[this->capacity];

}

BookList::BookList(const BookList& anotherList)
{
    books = anotherList.books;
    capacity = anotherList.capacity;
    booksCount = anotherList.booksCount;
}

BookList::~BookList()
{
    delete [] books;
    books = NULL;
}

void BookList::setCapacity(int theCapacity)
{
    this->capacity = theCapacity;
    books = new Book[this->capacity];

}
void BookList::addBook(Book book)
{
    if(booksCount == capacity)
    {
        cout<<"This List is Full"<<endl;
        return;
    }
    books[booksCount] = book;
    booksCount++;
}

Book& BookList::searchBook(string name)
{
    for(int i = 0 ; i < booksCount; i++)
    {
        if(books[i].getTitle() == name)
        {
            return books[i];
        }
    }
    Book *emptyBook = new Book("empty","","");
    return *emptyBook;
}

Book& BookList::searchBook(int id)
{
    for(int i = 0 ; i < booksCount; i++)
    {
        if(books[i].getId() == id)
        {
            if(books[i].getTitle() == "")
            {
                Book *emptyBook= new Book("empty","","");
                return *emptyBook;
            }
            else
            {
                return books[i];
            }
        }
    }
    Book *emptyBook= new Book("empty","","");
    return *emptyBook;
}

void BookList::deleteBook(int id)
{
    for(int i = 0; i < booksCount; i++)
    {
        if(books[i].getId() == id)
        {
            for(int k = i + 1; k < booksCount; k++)
            {
                books[i] = books[k];
                i++;
            }
            break;
        }
    }
    booksCount--;
}


Book& BookList::getTheHighestRatedBook()
{
    Book* tempList;
    tempList = new Book[capacity];
    tempList = books;

    for(int i = 0; i < booksCount; i++)
    {
        if(tempList[0].getAvgRating() < tempList[i].getAvgRating())
        {
            tempList[0] = tempList[i];
        }
    }
    for(int i = 0 ; i < booksCount; i++)
    {
        if(books[i].getAvgRating() == tempList[0].getAvgRating())
        {
            return books[i];
        }
    }
}

Book *BookList::getBooksForUser(User us)
{
    int dum = 0;
    Book *temp;
    temp = new Book[capacity];
    for(int i = 0 ; i< booksCount; i++)
    {
        if(books[i].getAuthor().getId() == us.getId())
        {
            temp[dum] = books[i];
            dum++;
        }
    }
    return temp;

}

ostream &operator<<(ostream &output, BookList &booklist)
{
    for(int i = 0 ; i < booklist.booksCount; i++)
    {
        if(booklist.books[i].getTitle() != "")
        {
            output<<"========= Book "<< booklist.books[i].getId()<<" info ========="<<endl;
            output<<"Title: "<<booklist.books[i].getTitle()<<endl;
            output<<"ISBN: "<<booklist.books[i].getISBN()<<endl;
            output<<"ID: "<<booklist.books[i].getId()<<endl;
            output<<"Category: "<<booklist.books[i].getCategory()<<endl;
            output<<"Avg Rating: "<<booklist.books[i].getAvgRating()<<endl;
            if(booklist.books[i].getAuthor().getName() == "")
            {

            }
            else
            {
                output<<"========= Author info ========="<<endl;
                output<<"Name: "<<booklist.books[i].getAuthor().getName()<<endl;
                output<<"Age: "<<booklist.books[i].getAuthor().getAge()<<endl;
                output<<"ID: "<<booklist.books[i].getAuthor().getId()<<endl;
                output<<"E-mail: "<<booklist.books[i].getAuthor().getEmail()<<endl;
                output<<"===================================="<<endl;
            }
        }
        else
        {
            break;
        }
    }
    return output;
}

Book &BookList::operator[](int position)
{
    if (position > capacity|| position < 0) cout << "No Book";
    else
    {
        return books[position];
    }
}

