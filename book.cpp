#include "book.h"
#include "util.h"
#include <sstream>
#include <set>
using namespace std;

Book::Book(const string& name, double price, int qty, const string& author_, const string& isbn_)
    : Product("book", name, price, qty), author_(author_), isbn_(isbn_)
{
    // constructor
}

set<string> Book::keywords() const{
    set<string> keys = parseStringToWords(convToLower(name_));
    set<string> authorWords = parseStringToWords(convToLower(author_));
    keys.insert(authorWords.begin(), authorWords.end());
    keys.insert(isbn_); // ISBN is used as-is
    return keys;
}

string Book::displayString() const
{
    ostringstream oss;
    oss << name_ << endl;
    oss << "Author: " << author_ << " ISBN: " << isbn_ << endl;
    oss << price_ << " " << qty_ << " left.";
    return oss.str();
}

void Book::dump(ostream& os) const
{
    os << "book" << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << author_ << endl;
    os << isbn_ << endl;
}

