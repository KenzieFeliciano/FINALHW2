#include "movie.h"
#include "util.h"
#include <sstream>
#include <set>
using namespace std;

Movie::Movie(const string& name, double price, int qty, const string& genre_, const string& rating_)
    : Product("movie", name, price, qty), genre_(genre_), rating_(rating_)
    {
//constructor
    }

set<string> Movie::keywords() const{
    set<string> keys = parseStringToWords(convToLower(name_));
    keys.insert(convToLower(genre_));
    return keys;
}

string Movie::displayString() const{
    ostringstream oss;
    oss << name_ << endl;
    oss << "Genre: " << genre_ << " Rating: " << rating_ << endl;
    oss << price_ << " " << qty_ << " left.";
    return oss.str();
}

void Movie::dump(ostream& os) const{
    os << "movie" << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << genre_ << endl;
    os << rating_ << endl;
}

