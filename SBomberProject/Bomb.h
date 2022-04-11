#pragma once
#include <memory>
#include <vector>

#include "DynamicObject.h"
#include "MyTools.h"
#include "DestroyableGroundObject.h"

class LogVisitor;

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;
	void __fastcall Accept(LogVisitor& v, std::shared_ptr<MyTools::ILogger> logger);
	//void __fastcall Accept(std::unique_ptr<LogVisitor> v, std::shared_ptr<MyTools::ILogger> logger);
	
	std::vector<DestroyableGroundObject*> CheckDestoyableObjects();
	void AddObserver(std::shared_ptr<DestroyableGroundObject> newObserver);

private:
	std::vector<std::shared_ptr<DestroyableGroundObject>> observers_;
};

