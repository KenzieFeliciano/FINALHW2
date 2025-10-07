#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> result; //empty set called result
    //for every element in s1, check if its also in s2
    //remember, a union is two sets that don't overlap in elements. Every element is unique {1,2,3,4}
    for(typename std::set<T>::iterator it = s1.begin(); it != s1.end(); ++it){ //typebname std::set<T>::iterator is the type (pointer for sets)
        if(s2.find(*it) != s2.end()){ //.end means "not found" aka past the last element. so its saying if it is found in both s1 and s2, it will be put into result
            result.insert(*it); //dereference the pointer. get the value starting from beginning -> end and insert into the empty container of sets.
        }
    }
    return result;

    //self note: we want to use set because it automatically only stores unique elements
    //self note: an iterator is like a pointer that lets you move through the elements of a continer. *it dereferences
    //self note: onyl if the elements overlap, then it goes to result.

}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> result; //empty set called result

    for(typename std::set<T>::iterator it = s1.begin(); it != s1.end(); ++it){
        result.insert(*it);
    }
    for(typename std::set<T>::iterator it = s2.begin(); it!= s2.end(); ++it){
        result.insert(*it);
    }

    return result;

}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
