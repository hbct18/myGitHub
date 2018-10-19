#include <iostream>
using namespace std;

class LibMat
{
public:
    LibMat(){ cout << "LibMat::LibMat() default constructor!\n"; }
    
    virtual ~LibMat(){ cout << "LibMat::LibMat() destructor!\n"; }
    virtual void print() const
        { cout << "LibMat::print() -- I am a LibMat object!\n"; }
};

class Magazine : public LibMat
{
public:
    Magazine(const string &title, const string &date)
        : _title(title), _date(date)
    {
        cout << "Magazine::Magazine( " << _title << ", "
             << _date << " ) constructor!\n";
    }
    ~Magazine(){ cout << "Magazine::~Magazine() destructor!\n"; }
    
    void print() const
    {
        cout << "Magazine::print() -- I am a Magazine object!\n"
             << "My title is: " << _title << '\n'
             << "My date is: " << _date << endl;
    }

    const string& title() const { return _title; }
    const string& date() const { return _date; }

protected:
    string _title;
    string _date;
};

class Book : public LibMat
{
public:
    Book(const string &title, const string &author)
        : _title(title), _author(author)
    {
        cout << "Book::Book( " << _title << ", "
             << _author << " ) constructor!\n";
    }

    virtual ~Book(){ cout << "Book::~Book() destructor!\n"; }

    virtual void print() const
    {
        cout << "Book::print() -- I am a Book object!\n"
             << "My title is: " << _title << '\n'
             << "My author is: " << _author << endl;
    }

    const string& title() const { return _title; }
    const string& author() const { return _author; }

protected:
    string _title;
    string _author;
};

class AudioBook : public Book
{
public:
    AudioBook(const string &title, const string &author, const string &narrator)
        : Book(title, author), _narrator(narrator)
    {
        cout << "AudioBook::AudioBook( " << _title
             << ", " << _author
             << ", " << _narrator
             << " ) constructor!\n"; 
    }

    ~AudioBook(){ cout << "AudioBook::~AudioBook() destructor!\n"; }
    virtual void print() const
    {
        cout << "AudioBook::print() -- I am an AudioBook object!\n"
             // 注意，以下直接取用继承而来的
             // data members: _title 和 _author
             << "My title is: " << _title << '\n'
             << "My author is: " << _author << '\n'
             << "My narrator is: " << _narrator << endl;
    }
    const string& narrator() const { return _narrator; }

protected:
    string _narrator;
};

void print(const LibMat &mat)
{
    cout << "in global print(): about to print mat.print()\n";

    // 下一行会依据 mat 实际指向的对象
    // 决议该执行哪一个 print() member function
    mat.print();
}

int main()
{
    AudioBook ab("Man Without Qualities", "Robert Musil", "Kenneth Meyer");
    print(ab);

    Magazine mg("English daily", "2018-10-15");
    print(mg);
    
    return 0;
}