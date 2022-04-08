#include "Visitor.h"


//class Bomb
//class Plane

void LogVisitor::log(Bomb* e, std::shared_ptr<MyTools::ILogger> logger)
//void LogVisitor::log(Bomb* e)
{
	logger->WriteToLog("Coord x ", e->GetX());
	logger->WriteToLog("Coord y ", e->GetY());
	logger->WriteToLog("Speed ", e->GetSpeed());
	logger->WriteToLog("Direction ", e->GetDirection());
}

void LogVisitor::log(Plane* e, std::shared_ptr<MyTools::ILogger> logger)
//void LogVisitor::log(Plane* e)
{
	//cout << "the doctor treats the patient in " + e->fun1() << '\n';
	logger->WriteToLog("Coord x ", e->GetX());
	logger->WriteToLog("Coord y ", e->GetY());
	logger->WriteToLog("Speed ", e->GetSpeed());
	logger->WriteToLog("Direction ", e->GetDirection());
}
