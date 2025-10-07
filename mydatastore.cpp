#include "mydatastore.h"
#include <iostream>
#include <set>
using namespace std;

MyDataStore::MyDataStore() {}

MyDataStore::~MyDataStore() {
    for(size_t i = 0; i < products_.size(); ++i) {
        delete products_[i];
    }
    for(size_t i = 0; i < users_.size(); ++i) {
        delete users_[i];
    }
}

void MyDataStore::dump(ostream& ofile)
{
    ofile << "<products>" << endl;
    for(size_t i = 0; i < products_.size(); ++i) {
        products_[i]->dump(ofile);
    }
    ofile << "</products>" << endl;
    ofile << "<users>" << endl;
    for(size_t i = 0; i < users_.size(); ++i) {
        users_[i]->dump(ofile);
    }
    ofile << "</users>" << endl;
}

void MyDataStore::addToCart(const string& username, Product* product)
{
    // Only add if user exists
    for (size_t i = 0; i < users_.size(); ++i) {
        if (users_[i]->getName() == username) {
            carts[username].push_back(product);
            return;
        }
    }
    // If user not found, do nothing
}

void MyDataStore::viewCart(const string& username)
{
    if (carts.find(username) == carts.end()) {
        cout << "Cart is empty." << endl;
        return;
    }
    vector<Product*>& cart = carts[username];
    for (size_t i = 0; i < cart.size(); ++i) {
        cout << "Item " << (i + 1) << endl;
        cout << cart[i]->displayString() << endl;
    }
}

void MyDataStore::buyCart(const string& username)
{
    if(carts.find(username) == carts.end()) return;
    vector<Product*>& cart = carts[username];
    User* user = nullptr;
    for(size_t i = 0; i < users_.size(); ++i) {
        if(users_[i]->getName() == username) {
            user = users_[i];
            break;
        }
    }
    if(!user) return;

    vector<Product*> newCart;
    for(size_t i = 0; i < cart.size(); ++i) {
        if(cart[i]->getQty() > 0 && user->getBalance() >= cart[i]->getPrice()) {
            cart[i]->subtractQty(1);
            user->deductAmount(cart[i]->getPrice());
        } else {
            newCart.push_back(cart[i]);
        }
    }
    cart = newCart;
}

void MyDataStore::addProduct(Product* p)
{
    products_.push_back(p);
}

void MyDataStore::addUser(User* u)
{
    users_.push_back(u);
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{
    vector<Product*> results;
    for(size_t i = 0; i < products_.size(); ++i) {
        set<string> keys = products_[i]->keywords();
        bool match = (type == 0); // AND: start true, OR: start false
        for(size_t j = 0; j < terms.size(); ++j) {
            bool found = (keys.find(terms[j]) != keys.end());
            if(type == 0) match = match && found; // AND
            else match = match || found;          // OR
        }
        if(match) results.push_back(products_[i]);
    }
    return results;
}

const vector<User*>& MyDataStore::getUsers() const
{
    return users_;
}