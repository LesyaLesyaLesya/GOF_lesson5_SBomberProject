#pragma once

#include <stdint.h>

#include "GameObject.h"

class DynamicObject : public GameObject 
{
public:

    DynamicObject() : speed(0.0), xDirction(0.0), yDirection(0) { }

    inline void SetSpeed(double sp) { speed = sp; }
    inline void SetDirection(double dx, double dy) { xDirction = dx; yDirection = dy; }
    
    virtual void Move(uint16_t time) { x += xDirction * speed * time * 0.001; y += yDirection * speed * time * 0.001; };

protected:

    double speed;
    double xDirction, yDirection;

};

/*1. Применение паттерна «Посетитель»
Задача : сделать логирование динамических объектов с помощью паттерна «Посетитель».
У нас есть класс динамический объект : DynamicObject.Наследниками этого класса
являются Bomb и Plane.Особенностью этих объектов является то, что они имеют функцию
Move и могут перемещаться.Добавим в класс DynamicObject функции - геттеры : GetSpeed и
GetDirection.Чтобы наш класс посетителя мог логировать не только координаты объектов,
получая их через GetX и GetY, но и вектор движения, и скорость.Добавив в классы Bomb и
Plane функции Accept :
void __fastcall Bomb::Accept(const Visitor& v)
{
    v.log(*this);
}
void __fastcall Plane::Accept(const Visitor& v)
{
    v.log(*this);
}
Также создадим иерархию классов посетителя : базовый интерфейсный класс с двумя
функциями для логирования Bomb и Plane.И реализуем их в наследнике LogVisitor, который
будет выполнять логирование полученных объектов с помощью семейства перегруженных
функций : MyTools::WriteToLog.Получать информацию из объектов он должен через
имеющиеся геттеры.
Сами акты принятия посетителя(функция Accept) можно вызывать из цикла по
динамическим объектам в функции : SBomber::MoveObjects().Объект класса LogVisitor
можно включить в класс SBomber или создавать динамически.
void SBomber::MoveObjects()
{
    WriteToLog(string(__FUNCTION__) + " was invoked");
    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        if (vecDynamicObj[i] != nullptr)
        {
            vecDynamicObj[i]->Move(deltaTime);
        }
    }
}*/