
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	MyTools::SetColor(CC_Yellow);
	GotoXY(x, y - 5);
	cout << "  ########  ";
	GotoXY(x, y - 4);
	cout << "##        ##";
	GotoXY(x, y - 3);
	cout << "############";
	GotoXY(x, y - 2);
	cout << "#          #";
	GotoXY(x, y - 1);
	cout << "#          #";
	GotoXY(x, y);
	cout << "############";
}

DestroyableGroundObject* House::HandleInsideCheck(const double x1, const double x2)
{
	if (this->isInside(x1, x2))
	{
		return this;
		//score += vecDestoyableObjects[i]->GetScore();
		//DeleteStaticObj(vecDestoyableObjects[i]);
		//observers_[i]->HandleInsideCheck();
	}
	else
	{
		return nullptr;
	}
}