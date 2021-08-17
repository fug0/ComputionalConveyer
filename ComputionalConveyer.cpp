// ComputionalConveyer.cpp : Defines the entry point for the application.
//

#include "ComputionalConveyer.h"

int main()
{
	// Accessible operators

	MatMulMat op1;
	MatMulVec op2;
	VecAddVec op3;
	VecScalarVec op4;
	
	//

	// First conveyer
	Pipeline f1;

	f1.mp["mat_mul_mat"] = &op1;
	f1.mp["mat_mul_vec"] = &op2;
	f1.mp["vec_add_vec"] = &op3;
	f1.mp["vec_scalar_vec"] = &op4;

	std::string f1_conveyer_folder_path = "C:/Разработка/Проекты/ComputionalConveyer/src/f1_conveyer/";

	std::string f1_config_str;
	std::cin >> f1_config_str;
	std::ifstream f1_config(f1_conveyer_folder_path + f1_config_str);

	std::ifstream f1_config_matrix;

	std::string f1_input_matrix_str;
	std::cin >> f1_input_matrix_str;
	std::ifstream f1_input_matrix(f1_conveyer_folder_path + f1_input_matrix_str);

	std::string f1_output_file_str;
	std::cin >> f1_output_file_str;
	std::ofstream f1_output_file(f1_conveyer_folder_path + f1_output_file_str);

	f1.process(f1_config, f1_config_matrix, f1_input_matrix, f1_output_file, f1_conveyer_folder_path);

	f1_config.close();
	f1_input_matrix.close();
	f1_output_file.close();

	//
	
	//Second conveyer
	Pipeline f2;

	f2.mp["mat_mul_mat"] = &op1;
	f2.mp["mat_mul_vec"] = &op2;
	f2.mp["vec_add_vec"] = &op3;
	f2.mp["vec_scalar_vec"] = &op4;

	std::string f2_conveyer_folder_path = "C:/Разработка/Проекты/ComputionalConveyer/src/f2_conveyer/";

	std::string f2_config_str;
	std::cin >> f2_config_str;
	std::ifstream f2_config(f2_conveyer_folder_path + f2_config_str);

	std::ifstream f2_config_matrix;

	std::string f2_input_matrix_str;
	std::cin >> f2_input_matrix_str;
	std::ifstream input_matrix(f2_conveyer_folder_path + f2_input_matrix_str);

	std::string f2_output_file_str;
	std::cin >> f2_output_file_str;
	std::ofstream f2_output_file(f2_conveyer_folder_path + f2_output_file_str);


	f2.process(f2_config, f2_config_matrix, input_matrix, f2_output_file, f2_conveyer_folder_path);

	f2_config.close();
	input_matrix.close();
	f2_output_file.close();

	//
	
}