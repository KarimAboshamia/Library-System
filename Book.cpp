#include "Book.h"

int Book::count = 0;
Book::Book()
{
    title_ = "";
    isbn_ = "";
    category_ = "";
    count++;
    id_ = count;
    averageRating_ = 0;
}
Book::Book(string title, string isbn, string category)
{
    title_ = title;
    isbn_ = isbn;
    category_ = category;
    count++;
    id_ = count;
    averageRating_= 0;
}
Book::Book(const Book& book)
{
    title_ = book.title_;
    isbn_ = book.isbn_;
    category_ = book.category_;
    author = book.author;
    id_ = book.id_;

}
void Book::setTitle(string title)
{
    title_ = title;
}
string Book::getTitle()
{
    return title_;
}

void Book::setISBN(string isbn)
{
    isbn_ = isbn;
}

string Book::getISBN()
{
    return isbn_;
}

void Book::setId(int id)
{
    id_ = id;
}
int Book::getId()
{
    return id_;
}

void Book::setAuthor(User user)
{
    author = user;
}
User Book::getAuthor()
{
    return author;
}

void Book::setCategory(string category)
{
    category_ = category;
}
string Book::getCategory()
{
        return category_;
}

void Book::rateBook(vector<int>rating)
{
    double sum = 0;
    int i =0;
    for(;i<rating.size();i++)
    {
        sum += rating[i];
    }
    sum = sum/i;
    averageRating_ = sum;
}
bool Book::operator==(const Book& book)
{
    return title_ == book.title_ && isbn_ == book.isbn_ && category_ == book.category_ && id_ == book.id_ && author == book.author;

}

istream &operator>>(istream &input, Book & book)
{
    cout<<"Enter the book information in this order"<<endl;
    cout<<"Title ISBN Category(space separated)"<<endl;
    input>>book.title_>>book.isbn_>>book.category_;
    return input;
}
ostream &operator <<(ostream &output, Book& book)
{
    output<<"======== Book "<< book.id_<< " info ======="<<endl;
    output<<"Title: "<< book.title_<<endl;
    output<<"ISBN: "<<book.isbn_<<endl;
    output<<"ID: "<< book.id_<<endl;
    output<<"Category: "<<book.category_<<endl;
    output<<"Avg Rating: "<<book.averageRating_<<endl;
    output<<"Author: "<< book.author.getName()<<endl;



    return output;
}
