#ifndef LINE_H
#define LINE_H

#include <string>

using namespace std;

class ILine
{
public:
    virtual string createLine() = 0;
    virtual ~ILine() = 0;
};

class Line: public ILine
{
public:
     string createLine() override;
};

#endif // LINE_H


