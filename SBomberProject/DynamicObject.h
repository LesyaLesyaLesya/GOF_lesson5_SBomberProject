#pragma once

#include <stdint.h>

#include "GameObject.h"
#include "MyTools.h"

class LogVisitor;

class DynamicObject:public GameObject
{
public:
    DynamicObject() : speed(0.0), xDirction(0.0), yDirection(0) { }

    inline void SetSpeed(double sp) { speed = sp; }
    inline void SetDirection(double dx, double dy) { xDirction = dx; yDirection = dy; }

    virtual void Move(uint16_t time) { x += xDirction * speed * time * 0.001; y += yDirection * speed * time * 0.001; };
    double GetSpeed() const { return speed; }
    double GetDirection() const { return sqrt(pow(xDirction - x, 2) + pow(yDirection + y, 2)); }
    //virtual void __fastcall Accept(std::unique_ptr<LogVisitor> v, std::shared_ptr<MyTools::ILogger> logger){}
    virtual void __fastcall Accept(LogVisitor& v, std::shared_ptr<MyTools::ILogger> logger) {}

protected:
    double speed;
    double xDirction, yDirection;
};
