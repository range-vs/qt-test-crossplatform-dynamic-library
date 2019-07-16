#include "line.h"

string Line::createLine()
{
    return "Your generated number: " + to_string(0 + rand() % 1996);
}

ILine::~ILine(){}
