#pragma once
#include "OperatorsInterface.h"

class MatMulVec : public Operators
{
public:
	void OperatorImplement(std::vector<std::vector<double>>*& p_v, std::vector<std::vector<double>>* p_m)
	{

		for (int i = 0; i < p_v->size(); i++)
		{
			for (int j = 0; j < (p_v->at(0)).size(); j++)
			{
				double temp_value = 0;
				for (int k = 0; k < (p_m->at(0)).size(); k++)
				{
					temp_value += ((p_v->at(i)).at(j)) * ((p_m->at(i)).at(k));
				}
				if ((p_v->at(i)).size() > 1)
				{
					(p_v->at(i)).clear();
					(p_v->at(i)).push_back(0);
				}
				(p_v->at(i)).at(j) = temp_value;
			}
		}
	};
};