#include <iostream>
#include <fstream>
#include <gmpxx.h>
#include "util.hpp"

using namespace std;

int main(int argc, char** argv) {
    unsigned long int n1, n2;
    mpz_t x1, x2, x3;

    // initialize each MPZ
    mpz_init(x1);  mpz_init(x2);  mpz_init(x3);

    // Ex A
    //   x3 = MPZ( 10 ) + MPZ( 100 )
    //   x3 = MPZ( 10 ) - MPZ( 100 )
    // add/subtract two MPZ to get an MPZ
    mpz_init_set_ui(x1,10);     // initialize each MPZ using an unsigned integer 10
    mpz_init_set_ui(x2,100);
    mpz_add(x3, x1, x2);        // x3 = x2+x1
    mpz_out_str(stdout,10,x1);  // write to stdout in base 10
    cout << " + ";
    mpz_out_str(stdout,10,x2);
    cout << " = ";
    mpz_out_str(stdout,10,x3);
    cout << endl;

    mpz_sub(x3, x1, x2);        // x3 = x2-x1
    mpz_out_str(stdout,10,x1);  // write to stdout in base 10
    cout << " - ";
    mpz_out_str(stdout,10,x2);
    cout << " = ";
    mpz_out_str(stdout,10,x3);
    cout << endl;


    // Ex B
    //   x3 = MPZ( 15 ) * MPZ( 100 )
    // multipying two MPZ to get an MPZ
    mpz_init_set_ui(x1,15);     // initialize each MPZ using an unsigned integer 15
    mpz_init_set_ui(x2,100);    
    mpz_mul(x3, x1, x2);        // x3 = x2*x1
    mpz_out_str(stdout,10,x1);  // write to stdout in base 10
    cout << " * ";
    mpz_out_str(stdout,10,x2);
    cout << " = ";
    mpz_out_str(stdout,10,x3); 
    cout << endl;


    // Ex C
    //   x1 = MPZ( 15 )
    //   x1 = x1 * 200
    // multiply an MPZ by an unsigned integer
    mpz_init_set_ui(x1,15);
    mpz_mul_ui(x1, x1, 200);
    cout << "15 * 200 = ";
    mpz_out_str(stdout,10,x1);
    cout << endl;


    // Ex D
    //   x1 = x2^100
    // using an unsigned integer as an exponent
    mpz_init_set_ui(x2,3);
    mpz_pow_ui(x1, x2, 4);
    cout << "3^4 = ";
    mpz_out_str(stdout,10,x1);
    cout << endl;


    // Ex E
    //   x1 = MPZ( 109! )
    // using an unsigned integer and doing the factorial
    n1 = 109;
    mpz_fac_ui(x1, n1);         // factorial from unsigned int, x1 = (n1)!
    printf("%lu!  =  ", n1);
    mpz_out_str(stdout,10,x1);
    cout << endl;


    // Ex F
    //   x3 = MPZ( 109! ) / MPZ( 108! )
    n2 = 108;
    mpz_fac_ui(x1, n1);
    mpz_fac_ui(x2, n2);
    mpz_tdiv_q(x3, x1, x2);     // gives quotient (rounded down)
    printf("%lu! / %lu!  =  ", n1, n2);
    mpz_out_str(stdout,10,x3);
    cout << endl;


    // Ex G
    //   size_t a = log(2. 188!)
    // Getting the log of an MPZ in base 2
    mpz_init_set_ui(x1,16);
    cout << "log 16 in base 2 is " << mpz_sizeinbase(x1, 2) << endl;
    mpz_fac_ui(x1, 188);
    cout << "log 188! in base 2 is " << mpz_sizeinbase(x1, 2) << endl;;

   
    // Test: using your comb and perm
    cout << "\nThis code should work once you've completed src/util.hpp" << endl;

    n1 = 9999999; n2 = 45;
    printf("C(%lu,%lu)  =  ", n1, n2);
    comb(x3, n1, n2);
    mpz_out_str(stdout,10,x3);
    printf("\n    should be  =  8358785666781787383027567745412200582794780928634011932670511566731835205329959283126695256251368705932010431043837308163831959501693846451065712094963571275388477790898070494164404649853047016967599446507722049429249378620402031762152805033776172830280087499");
    cout << endl;

    printf("P(%lu,%lu)  =  ", n1, n2);
    perm(x3, n1, n2);
    mpz_out_str(stdout,10,x3);
    printf("\n    should be  =  999896505198981107513798294405336427752771158628742308252086368042526331375966530826808769308251424494466577380685101004620157722891457036895606486255870859834280457157879914598949519445840734943000822020084671585734297846398436577809826177171936581913031778278020174177514782528168237690903604765120266240000000000");
    cout << endl;

    // clear (free) all the MPZ variables, now that we are done
    mpz_clear(x1); mpz_clear(x2); mpz_clear(x3);

    return 0;
}


