#pragma once
#include "OperatorsInterface.h"

class MatMulMat : public Operators
{
public:
	void OperatorImplement(std::vector<std::vector<double>>*& p_mRight, std::vector<std::vector<double>>* p_mLeft)
	{
		std::vector<std::vector<double>> temp_matrix(p_mLeft->size(), std::vector<double>((p_mRight->at(0)).size(), 0));

		for (int i = 0; i < p_mLeft->size(); i++)
		{
			for (int j = 0; j < (p_mRight->at(0)).size(); j++)
			{
				for (int k = 0; k < p_mRight->size(); ++k)
				{
					(temp_matrix.at(i)).at(j) += (p_mLeft->at(i)).at(k) * (p_mRight->at(k)).at(j);
				}
			}
		}

		for (int i = 0; i < p_mRight->size(); i++)
		{
			(p_mRight->at(i)).clear();
		}
		p_mRight->clear();

		for (int i = 0; i < temp_matrix.size(); i++)
		{
			p_mRight->push_back(std::vector<double>());

			for (int j = 0; j < (temp_matrix.at(0)).size(); j++)
			{
				(p_mRight->at(i)).push_back((temp_matrix.at(i)).at(j));
			}
		}
	};
};
