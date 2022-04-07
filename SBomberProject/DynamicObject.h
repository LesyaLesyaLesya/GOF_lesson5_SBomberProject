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

/*1. ���������� �������� ������������
������ : ������� ����������� ������������ �������� � ������� �������� ������������.
� ��� ���� ����� ������������ ������ : DynamicObject.������������ ����� ������
�������� Bomb � Plane.������������ ���� �������� �������� ��, ��� ��� ����� �������
Move � ����� ������������.������� � ����� DynamicObject ������� - ������� : GetSpeed �
GetDirection.����� ��� ����� ���������� ��� ���������� �� ������ ���������� ��������,
������� �� ����� GetX � GetY, �� � ������ ��������, � ��������.������� � ������ Bomb �
Plane ������� Accept :
void __fastcall Bomb::Accept(const Visitor& v)
{
    v.log(*this);
}
void __fastcall Plane::Accept(const Visitor& v)
{
    v.log(*this);
}
����� �������� �������� ������� ���������� : ������� ������������ ����� � �����
��������� ��� ����������� Bomb � Plane.� ��������� �� � ���������� LogVisitor, �������
����� ��������� ����������� ���������� �������� � ������� ��������� �������������
������� : MyTools::WriteToLog.�������� ���������� �� �������� �� ������ �����
��������� �������.
���� ���� �������� ����������(������� Accept) ����� �������� �� ����� ��
������������ �������� � ������� : SBomber::MoveObjects().������ ������ LogVisitor
����� �������� � ����� SBomber ��� ��������� �����������.
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