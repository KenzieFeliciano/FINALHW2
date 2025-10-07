#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <set>
#include "product.h"

class Book : public Product{
    //class declaration
public:
    Book(const std::string& name, double price, int qty, const std::string& author_, const std::string& isbn_);
    std::set<std::string> keywords() const override; //override is saying this function intends to override a virtual function from the base class. if the function signature doesnt match the base class, you'll get an error. this is just proper code ettiquette to help catch bugs
    std::string displayString() const override;
    void dump(std::ostream& os) const override;

private:
    std::string author_;
    std::string isbn_;

};

#endif //BOOK_H


//self note: the constructor needs to initialize all data members including the ones from product

//self note: the reason we re-add functions like keywords(), displayString(), and dump() even though they're already in Product class (that Book is inheriting) 
//is to tell the compiler these are the specific Book versions (function overriding/polymorphism). So we're using Book specific behavior that is not calling to the Product version (Product* to Book)

//self note: endif is to end the header so its not duplicated

//self note: what is polymorphism? It means "many forms" and lets you use a base class pointer or reference to call functions that behave differently. a Product* could point ot Book

//self note: virtual allows other classes to override those functions with more specific versions (a form of polymorphism)

//self note: class is the blueprint, constructor initializes the object you create. you might have multiple constructors if you want to have different ways of creating a book. maybe the second constructor only has some arguments like only name and author
