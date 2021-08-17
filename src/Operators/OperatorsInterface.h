#pragma once

class Operators
{
protected:
	Operators() {};
public:
	virtual void OperatorImplement(std::vector<std::vector<double>>*& p1, std::vector<std::vector<double>>* p2) = 0;
};