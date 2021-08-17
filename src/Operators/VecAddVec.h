#pragma once
#include "OperatorsInterface.h"

class VecAddVec : public Operators
{
public:
	void OperatorImplement(std::vector<std::vector<double>>*& p_v1, std::vector<std::vector<double>>* p_v2)
	{
		for (int i = 0; i < p_v1->size(); i++)
		{
			for (int j = 0; j < (&p_v1->at(i))->size(); j++)
			{
				(p_v1->at(i)).at(j) += (p_v2->at(i)).at(j);
			}
		}
	};
};
