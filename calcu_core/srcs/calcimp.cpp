#include "CalcImp.h"

CalcImp::CalcImp()
{
    expression = "null";
    count += 1;
}

CalcImp::~CalcImp()
{
    count -=1 ;
}