#ifndef CLOTHING_H
#define CLOTHING_H

#include <iostream>
#include <string>
#include <set>
#include "product.h"

class Clothing : public Product{
public:
    Clothing(const std::string& name, double price, int qty, const std::string& brand_, const std::string& size_);
    std::set<std::string> keywords() const override; //override is saying this function intends to override a virtual function from the base class. if the function signature doesnt match the base class, you'll get an error. this is just proper code ettiquette to help catch bugs
    std::string displayString() const override;
    void dump(std::ostream& os) const override;

private:
    std::string brand_;
    std::string size_;

};

#endif //CLOTHING_H