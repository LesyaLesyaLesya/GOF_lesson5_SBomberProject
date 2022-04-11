#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	DestroyableGroundObject* HandleInsideCheck(const double x1, const double x2) override;
private:

	const uint16_t score = 30;
};

