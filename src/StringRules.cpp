#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "StringRules.hpp"
#include "util.hpp"

using namespace std; 

// 
// Constructor
//
// Take a string of symbols and counts these,
//  eliminating repeats.
// 
StringRules::StringRules( string symbols )
{
    set < char, greater <char> > alphabet;
    set < char, greater <char> > :: iterator itr;

    upper = lower = digit = special = 0;
    for (int i = 0 ; i < symbols.length(); i++){
        alphabet.insert(symbols[i]);
    }
    for (itr = alphabet.begin(); itr != alphabet.end(); ++itr) {
        if (isupper(*itr)) {
            upper++;
        } else if (islower(*itr)) {
            lower++;
        } else if (isdigit(*itr)) {
            digit++;
        } else {
            special++;
        }
    }
    return;
}


// 
// Destructor
// 
StringRules::~StringRules()
{
    // TODO (if needed)
}



// 
// Public member function.
// 
// Prints a menu to standard out.
//
void StringRules::print_menu(void)
{        
    cout << "\n" << " Options" << "\n=========\n";
    cout << "1. Repeated symbols, variable length.\n";
    cout << "2. No repeated symbols, variable length.\n";
    cout << "3. Repeated symbols, variable length, with 'at least one' rules.";
    cout << endl;
    return;
}


// 
// Public member function.
// 
// Prints a summary of the custom alphabet.
//
void StringRules::print_summary(void)
{
    cout << " Lower:   " << lower << endl;
    cout << " Upper:   " << upper << endl;
    cout << " Digits:  " << digit << endl;
    cout << " Special: " << special << endl;
    return;
}


// 
// Public member function.
// 
// Returns the naive guessing strength
//  of brute-forcing a password space with cardinality 'size.'
//
size_t StringRules::strength(mpz_t size)
{
    return mpz_sizeinbase(size, 2);
}

