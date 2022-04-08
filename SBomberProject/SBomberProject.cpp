
#include <conio.h>
#include <stdlib.h>
#include <memory>

#include "SBomber.h"
#include "MyTools.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    auto logger = std::make_shared<MyTools::ProxyLogger>(MyTools::FileLoggerSingleton::getInstance());
    auto logVisitor = std::make_unique<LogVisitor>();
    //std::unique_ptr<LogVisitor> logVisitor(std::move(new LogVisitor));

    logger->OpenLogFile("log.txt");

    SBomber game{logger, std::move(logVisitor)};
    //SBomber game{ logger};

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    logger->CloseLogFile();

    return 0;
}
