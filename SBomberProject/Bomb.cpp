
#include <iostream>

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