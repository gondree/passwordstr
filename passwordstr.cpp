#include <iostream>
#include <fstream>
#include <gmpxx.h>
#include "StringRules.hpp"
#include "util.hpp"

using namespace std;

int main(int argc, char** argv) {
    string y;

    // Get the alphabet and intialize the StringRules container
    cout << "What characters might appear in the password?" << endl;
    cout << "> ";
    getline(cin, y);

    StringRules sr(y);    
    sr.print_summary();

    // Get which types of rules from the user
    sr.print_menu();
    cout << "> "; 
    getline(cin, y);
    cout << "You entered '" << y << "'" << endl;

    // TODO: Validate the user-input
    
    // TODO: Based on the user-input, prompt for additional information

    // TODO: Do the calculation and output the statistics
    
    return 0;
}


