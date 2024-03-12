#include "HighPreciCalc.h"
#include "MaxandMin.h"

void HighPreciCalc::test(void){
    cout<<"Hello World!";
}

void HighPreciCalc::show(string* waittoShow,bool isShowZero){
    if(isShowZero)
        cout<<*waittoShow<<endl;
    else 
        {
        char* tmpChar = &(*waittoShow)[0];
        rm_zero(tmpChar);
        cout<<tmpChar<<endl;
        }

}

void HighPreciCalc::show(void){
        HighPreciCalc::signedNub& expression = this->HExpression;
        char* tmpChar = &(expression.nub[0]);
        rm_zero(tmpChar);
        cout<<tmpChar<<endl;
}

void HighPreciCalc::rm_zero(char*& expression){
    int i = 0;
    bool isRun = true;
    while (isRun){
        if ((expression[i] == '0')&&(expression[i+1] != '\0')){
            expression+=1;
            i++;
            }
        else 
            isRun = false;
    };
}

int HighPreciCalc::weight(string& expression){
    int weight = 0;
    int j = 1;
    const int Length = expression.length();
    for(int i = Length-1;i >= 0;i--){
        weight+=j*(expression[i] - '0');
        j*=10;
    }
    return weight;
}

string* HighPreciCalc::pWeighter(string& operand1,string& operand2){
    int maxLength1 = operand1.length();
    int maxLength2 = operand2.length();

    bool isEqual = (maxLength1 == maxLength2);

    if(isEqual)
        return NULL;
    else if(maxLength1 > maxLength2)
        return &operand1;
    else
        return &operand2;
}

int HighPreciCalc::sign_of_nub_bigger(HighPreciCalc::signedNub& operand1,HighPreciCalc::signedNub& operand2){
    int maxLength1 = operand1.nub.length();
    int maxLength2 = operand2.nub.length();

    bool isEqual = (maxLength1 == maxLength2);

    if(isEqual)
        return 0;
    else if(maxLength1 > maxLength2)
        return operand1.sign;
    else
        return operand2.sign;
}

string HighPreciCalc::int_to_string(int nub){
    int count = 0;
    int tmp = nub;
    string tmpString;
    for(;tmp/10 != 0;){
        count ++;
        tmp /= 10;
    }

    tmp = nub;

    for(int i = count;i  >= 0;i--)
        for(int j = count; j > 0 ;j--)
            tmp /= 10;
}

char HighPreciCalc::char_sign(int tmpSign){
switch (tmpSign)
{
case -1:
    return '-';
    break;
case 1:
    return '+';
    break;
}
return '0';
}

string* HighPreciCalc::output(const int ctrl){
    switch (ctrl)
    {
    case UNSIGNED:
        return &HExpression.nub;
        break;
    case SIGNED:
        globalString = char_sign(HExpression.sign)+HExpression.nub;
        return &globalString;
        break;
    }
    cout<<"\n!output error!\n";
    return NULL;
}

void HighPreciCalc::setOperand(string stringTmp){
    HExpression.nub = stringTmp;
}

void HighPreciCalc::setOperand(string stringTemp,int ctrl){
    if (ctrl == 1)
    HUnsignedNub1 = stringTemp;
    if (ctrl == 2)
    HUnsignedNub2 = stringTemp;
}

void HighPreciCalc::setOperand(string stringTemp,int sign,int ctrl){
    if (ctrl == 1){
        HSignedNub1.nub = stringTemp;
        HSignedNub1.sign = sign;
    }
    if (ctrl == 2){
    HSignedNub2.nub = stringTemp;
    HSignedNub2.sign = sign;
    }
}

void HighPreciCalc::free() {
    if (globalCharPtr)
        delete [] globalCharPtr;
    globalCharPtr = NULL;
    if (globalStringPtr)
        delete globalCharPtr;
    globalStringPtr = NULL;
}

string HighPreciCalc::unsigned_add(){

    string& operand1 = HUnsignedNub1;
    string& operand2 = HUnsignedNub2;
    bool isCarry = false;
    const int MaxLength = max(operand1.length(),operand2.length());
    const int MinLength = min(operand1.length(),operand2.length());

    char* expression = new char[MaxLength+2]{'0'};
    expression[MaxLength+1] = '\0';
    
    if (MaxLength == operand1.length()){
        operand2.insert(0,MaxLength-MinLength,'0');
    }
    else{
        operand1.insert(0,MaxLength-MinLength,'0');
    }

    for (int i = MaxLength-1;i >= 0;i--){
        if ((operand1[i]+operand2[i]+isCarry-'0')>='0'&&(operand1[i]+operand2[i]+isCarry-'0')<='9'){
            expression[i+1] = operand1[i] + operand2[i] + isCarry - '0';
            isCarry = false;
        }
        else{
            expression[i+1] = operand1[i] + operand2[i] + isCarry - 58;
            isCarry = true;
        }
    }

    globalCharPtr = expression;

    if (isCarry == true)
        expression[0] = 1;
    else if((expression[0] == '0')&&(expression[1] != '\0'))
        expression+=1;

    return expression;
}


HighPreciCalc::signedNub* HighPreciCalc::signed_add(void){
    signedNub& operand1 = HSignedNub1;
    signedNub& operand2 = HSignedNub2;
    HighPreciCalc::signedNub* expression;
    bool isBorrow = false;

    if(operand1.sign + operand2.sign){
        setOperand(HSignedNub1.nub,1);
        setOperand(HSignedNub2.nub,2);
        expression->nub = unsigned_add();
        this->free();
        expression->sign = (bool(operand1.sign) >= bool(operand2.sign)?operand1.sign:operand2.sign);
        
        HExpression = *expression;
        return expression;
    }

    else if(operand1.nub == operand2.nub){
        expression->nub = "0";
        expression->sign = 0;

        HExpression = *expression;
        return expression;
    }
    
    int tmpSign = 0;
    


    expression->sign = sign_of_nub_bigger(operand1,operand2);

        return expression;
    

}

HighPreciCalc::signedNub* HighPreciCalc::power(void){
    signedNub& operand1 = HSignedNub1;
    signedNub& operand2 = HSignedNub2;
    HighPreciCalc::signedNub* expression;

    if(operand1.sign = -1){
        if((operand1.nub[operand1.nub.length()-1] - '0')%2 == 0)
            expression->sign = 1;
        else
            expression->sign = -1;
    }
    else
        expression->sign = operand1.sign;

    if((operand1.nub == "0")||(operand1.nub == "1"))
        expression->nub = operand1.nub;
    else{
        int i = weight(operand2.nub);
        for(;i!= 0;i--)
            expression->nub *= expression->nub;
    }
    //write here
}