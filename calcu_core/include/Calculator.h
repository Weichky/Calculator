#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "CalcImp.h"

class Calculator{
public:
    Calculator(void);
    ~Calculator(void);

    string getExpression() const;
    void setExpression(string strExpression);

    void calc(string& Expression);

    void show() const;
private:
    CalcImp* pImp;

};

#endif