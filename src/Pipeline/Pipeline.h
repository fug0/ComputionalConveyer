#pragma once
#include "..\Operators\OperatorsInterface.h"

class Pipeline
{
public:
	std::map<std::string, Operators*> mp;

	Pipeline() {};

	void process(std::ifstream& cfg, std::ifstream& cfg_matrix, std::ifstream& inp_matrix, std::ofstream& out, std::string conveyer_folder_path)
	{
		std::vector<std::vector<double>> m1; // input_matrix operand
		//input_matrix operand string to vector conversion
		while (!inp_matrix.eof())
		{
			m1.push_back(std::vector<double>());

			while (inp_matrix.peek() != '\n' && !inp_matrix.eof())
			{
				m1[m1.size() - 1].push_back(0);
				inp_matrix >> m1[m1.size() - 1][m1[m1.size() - 1].size() - 1];
			}

			inp_matrix.get();
		}

		std::vector<std::vector<double>>* p_m1 = &m1; //pointer to m1 matrix

		// execution of transformations according to config file
		while (!cfg.eof())
		{

			std::string cfg_matrix_file_path = conveyer_folder_path;
			std::string cfg_matrix_file_name = "";
			std::string op_name = "";

			cfg >> op_name;
			cfg >> cfg_matrix_file_name;

			cfg_matrix_file_path += cfg_matrix_file_name;


			std::vector<std::vector<double>> m2; // right operand

			//right operand string to vector conversion
			cfg_matrix.open(cfg_matrix_file_path);
			while (!cfg_matrix.eof())
			{
				m2.push_back(std::vector<double>());

				while (cfg_matrix.peek() != '\n' && !cfg_matrix.eof())
				{
					m2[m2.size() - 1].push_back(0);
					cfg_matrix >> m2[m2.size() - 1][m2[m2.size() - 1].size() - 1];
				}

				cfg_matrix.get();
			}
			cfg_matrix.close();

			// application of operator
			(mp[op_name])->OperatorImplement(p_m1, &m2);
		}

		// Output in file
		for (int i = 0; i < p_m1->size(); i++)
		{
			for (int j = 0; j < (p_m1->at(i)).size(); j++)
			{
				if (j != (p_m1->at(i)).size() - 1)
				{
					out << (p_m1->at(i)).at(j) << ' ';
				}
				else
				{
					out << (p_m1->at(i)).at(j) << '\n';
				}

			}
		}

	}

};