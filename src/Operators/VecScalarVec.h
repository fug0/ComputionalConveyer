#pragma once
#include "OperatorsInterface.h"

class VecScalarVec : public Operators
{
public:
	void OperatorImplement(std::vector<std::vector<double>>*& p_v1, std::vector<std::vector<double>>* p_v2)
	{
		double scalar_res = 0;
		for (int i = 0; i < p_v1->size(); i++)
		{
			for (int j = 0; j < (p_v1->at(i)).size(); j++)
			{
				scalar_res += (p_v1->at(i)).at(j) * (p_v2->at(i)).at(j);
			}
			(p_v1->at(i)).clear();
		}
		p_v1->at(0).push_back(scalar_res);
	};
};