#include "mydatastore.h"
#include <iostream>
using namespace std;

MyDataStore::MyDataStore() {}

MyDataStore::~MyDataStore() {}

void MyDataStore::dump(ostream& ofile)
{
    // Simple implementation for now
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
    carts[username].push_back(product);
}

void MyDataStore::viewCart(const string& username)
{
    if(carts.find(username) == carts.end()) {
        cout << "Cart is empty." << endl;
        return;
    }
    vector<Product*>& cart = carts[username];
    for(size_t i = 0; i < cart.size(); ++i) {
        cout << cart[i]->displayString() << endl;
    }
}

void MyDataStore::buyCart(const string& username)
{
    if(carts.find(username) == carts.end()) return;
    vector<Product*>& cart = carts[username];
    for(size_t i = 0; i < cart.size(); ++i) {
        if(cart[i]->getQty() > 0) {
            cart[i]->subtractQty(1);
        }
    }
    cart.clear();
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
        for(size_t j = 0; j < terms.size(); ++j) {
            if(keys.find(terms[j]) != keys.end()) {
                results.push_back(products_[i]);
                break;
            }
        }
    }
    return results;
}