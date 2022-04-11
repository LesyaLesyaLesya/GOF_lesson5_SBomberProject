
#include <iostream>
#include <algorithm>

#include "Visitor.h"
#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}
void __fastcall Bomb::Accept(LogVisitor& v, std::shared_ptr<MyTools::ILogger> logger)
//void __fastcall Bomb::Accept(std::unique_ptr<LogVisitor> v, std::shared_ptr<MyTools::ILogger> logger)
{
    v.log(this, logger);
}
void Bomb::AddObserver(std::shared_ptr<DestroyableGroundObject> newObserver)
{
    observers_.push_back(newObserver);
}

std::vector<DestroyableGroundObject*>  Bomb::CheckDestoyableObjects()
{
    std::vector<DestroyableGroundObject*> objectsForDelete;
    //vector<DestroyableGroundObject*> vecDestoyableObjects = FindDestoyableGroundObjects();
    const double size = this->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < observers_.size(); i++)
    {
        const double x1 = this->GetX() - size_2;
        const double x2 = x1 + size;
        
        std::for_each(observers_.begin(), observers_.end(), [&objectsForDelete, x1, x2](std::shared_ptr<DestroyableGroundObject> el){
            auto temp = el->HandleInsideCheck(x1, x2);
            if (temp)
            {
                objectsForDelete.push_back(temp);
            }
            ;});

        return objectsForDelete;
        /*if (observers_[i]->isInside(x1, x2))
        {
            score += vecDestoyableObjects[i]->GetScore();
            DeleteStaticObj(vecDestoyableObjects[i]);
            observers_[i]->HandleInsideCheck();
        }*/
    }
}