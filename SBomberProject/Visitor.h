#pragma once
#include <memory>

#include "MyTools.h"
#include "Bomb.h"
#include "Plane.h"


class Bomb;
class Plane;

class Visitor
{
public:
	Visitor() = default;
	virtual ~Visitor()=default;

	virtual void log(Bomb* e, std::shared_ptr<MyTools::ILogger> logger) = 0;
	virtual void log(Plane* e, std::shared_ptr<MyTools::ILogger> logger) = 0;
	//virtual void log(Bomb* e) = 0;
	//virtual void log(Plane* e) = 0;

};

class LogVisitor : public Visitor // Доктор
{
public:
	LogVisitor() = default;

	void log(Bomb* e, std::shared_ptr<MyTools::ILogger> logger) override;
	void log(Plane* e, std::shared_ptr<MyTools::ILogger> logger) override;

	//void log(Bomb* e) override;
	//void log(Plane* e) override;
};