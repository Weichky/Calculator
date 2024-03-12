#include "Calculator.h"

Calculator::Calculator(void){
    pImp = new CalcImp;
}

Calculator::~Calculator(void){
    if (pImp)
        delete pImp;
}

string Calculator::getExpression() const{
    return pImp->expression;
}

void Calculator::setExpression(string strExpression){
    pImp->expression = strExpression;
}

void Calculator::show() const{
    cout<<pImp->expression;
}

void Calculator::calc(string& getExpression){

}