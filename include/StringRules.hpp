#ifndef __StringRules
#define __StringRules

#include <string>
#include <gmpxx.h>

// Some useful constants
#define LOWER        0x00
#define UPPER        0x01
#define DIGIT        0x02
#define SPECIAL      0x03
#define TOTAL_RULES  0x04
#define HAS_EXACTLY  0x05
#define HAS_AT_LEAST 0x06


class StringRules {
    
  public:
    StringRules(std::string symbols);
    ~StringRules();

    size_t strength(mpz_t size);
    
    void print_menu(void);
    void print_summary(void);

  private:
    unsigned int lower;
    unsigned int upper;
    unsigned int digit;
    unsigned int special;
};

#endif //  __StringRules

