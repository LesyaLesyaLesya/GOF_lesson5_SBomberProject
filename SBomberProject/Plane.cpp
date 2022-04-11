
#include <iostream>

#include "Visitor.h"
#include "Plane.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Plane::Draw() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x, y);
    cout << "=========>";
    GotoXY(x - 2, y - 1);
    cout << "===";
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";
}
void __fastcall Plane::Accept(LogVisitor& v, std::shared_ptr<MyTools::ILogger> logger)
//void __fastcall Plane::Accept(std::unique_ptr<LogVisitor> v, std::shared_ptr<MyTools::ILogger> logger)
{
    v.log(this,logger);
}
