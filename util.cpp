#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    for(size_t i = 0; i < rawWords.size(); i++){
        if(!isalpha(rawWords[i])){ //any non letters (like punctuation/numbers) become spaces
        rawWords[i] = ' ';
        } 
    }

    //the critera is:
    //1. 2 or more letters
    //2. split at punctation marks
    //3. ignore anything < than 2 letters

    set<string> words; //a set is its own type of container like a vector or array. this is a an empty set that stores elemtns in sorted order and no duplicates
    stringstream ss(rawWords); //stringstream named ss that loads in the string rawWords. It processes the string you pass in (could come from user or file)
    string word; //temporary variable that holds each word as you extract it from the stringstream
    while(ss >> word){ //stringstream by default separates each word by the space
        word = convToLower(word); //make it all lowercase
        if(word.size() >= 2){
            words.insert(word);
        }
    }
    return words;

    //function processess a string, splits it into words, converts them to lowercase, filters short words, and returns the set of unique words.



}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
        std::find_if(s.begin(), 
             s.end(), 
             [](int ch) { return !std::isspace(ch); }));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
        std::find_if(s.rbegin(), 
             s.rend(), 
             [](int ch) { return !std::isspace(ch); }).base(), 
        s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

