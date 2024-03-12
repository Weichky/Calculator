#ifndef HIGH_PRECI_CALC_H
#define HIGH_PRECI_CALC_H

#include "Dependence.h"

class HighPreciCalc
{   
    struct signedNub
    {
        int sign;//true for +,false for -
        string nub;
    };

    public:

    string* output(const int);
    void show(string*,bool);
    void show(void);
    void setOperand(string);
    void setOperand(string,int);
    void setOperand(string,int,int);
    void test(void);
    void free();

    string unsigned_add(void);
    signedNub* signed_add(void);
    signedNub* power(void);
    private:

    bool isOne;
    signedNub HExpression{0,"\0"};

    char char_sign(int);
    void rm_zero(char*&);
    string* pWeighter(string&,string&);
    int weight(string&);
    int sign_of_nub_bigger(signedNub&,signedNub&);
    string int_to_string(int);

    signedNub HSignedNub1{0,"\0"};
    signedNub HSignedNub2{0,"\0"};
    string& HUnsignedNub1 = HSignedNub1.nub;
    string& HUnsignedNub2 = HSignedNub2.nub;

    char* globalCharPtr = NULL;
    string* globalStringPtr = NULL;
    string globalString;
    int globalInt = 1;

 /*   
    string mul(string&,string&);
    string div(string&,string&);

    string sprt(string&,string&);
    string factorial(string&);
    string accumulate(string&);
    string sin(string&);
    string cos(string&);
*/
};

#endif