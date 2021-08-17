# CMakeList.txt : CMake project for ComputionalConveyer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ComputionalConveyer")

# Add source to this project's executable.
add_executable (ComputionalConveyer "ComputionalConveyer.cpp" "ComputionalConveyer.h" "Operators/OperatorsInterface.h" "Operators/MatMulVec.h" "Operators/MatMulMat.h" "Operators/VecAddVec.h" "Operators/VecScalarVec.h" "Pipeline/Pipeline.h")

# TODO: Add tests and install targets if needed.
