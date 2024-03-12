//test main

#define SUCCESS 0

#include "Dependence.h"
#include "HighPreciCalc.h"
#include "MaxandMin.h"

int main(){
    
//test
    string test1 = "123456789123456789";
    string test2 = "010";
    HighPreciCalc a;

    a.setOperand(test1,1,1);
    a.setOperand(test2,-1,2);

    a.setOperand(a.unsigned_add());

    a.show(a.output(UNSIGNED),true);
    a.show();

    cout<<"\nCALCULATOR CORE EXITED SUCCESSFULLY!";
    return SUCCESS;
}