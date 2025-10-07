#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <set>
#include "product.h"

//class declaration
class Movie : public Product{
    public:
    Movie(const std::string& name, double price, int qty, const std::string& genre_, const std::string& rating_);
    std::set<std::string> keywords() const override;
    std::string displayString() const override;
    void dump(std::ostream& os) const override;

    private:
    std::string genre_;
    std::string rating_;

};

#endif //MOVIE_H

//self note: a class is abstract if at least one pure virtual function (= 0)
//can't create (instantiate) objects of an abstract class
//abstract classes are meant to be base classes. They define an interface but not a full implementation