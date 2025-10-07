#include "clothing.h"
#include "util.h"
#include <sstream>
#include <set>
using namespace std;

Clothing::Clothing(const std::string& name, double price, int qty, const std::string& brand_, const std::string& size_)
    : Product("clothing", name, price, qty), brand_(brand_), size_(size_)
{
    //constructor
}

set<string> Clothing::keywords() const
{
    set<string> keys = parseStringToWords(convToLower(name_));
    set<string> brandWrds = parseStringToWords(convToLower(brand_));
    keys.insert(brandWrds.begin(), brandWrds.end());
    return keys;
}

string Clothing::displayString() const
{
    ostringstream oss;
    oss << name_ << endl;
    oss << "Size: " << size_ << " Brand: " << brand_ << endl;
    oss << price_ << " " << qty_ << " left.";
    return oss.str();
}

void Clothing::dump(ostream& os) const
{
    os << "clothing" << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << size_ << endl;
    os << brand_ << endl;
}