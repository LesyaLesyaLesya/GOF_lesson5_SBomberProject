#pragma once
#include "DynamicObject.h"
#include "MyTools.h"
//#include "Visitor.h"

class LogVisitor;

class Plane:public DynamicObject
{
public:

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }
    void __fastcall Accept(LogVisitor& v, std::shared_ptr<MyTools::ILogger> logger);
    //void __fastcall Accept(std::unique_ptr<LogVisitor> v, std::shared_ptr<MyTools::ILogger> logger);
private:

};

