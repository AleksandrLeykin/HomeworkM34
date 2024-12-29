cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

set(PROJECT_NAME myConcept)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} 
        src/main.cpp
)
        
target_compile_features(${PROJECT_NAME} 
	PUBLIC cxx_std_20
)

set_target_properties(${PROJECT_NAME} 
	PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/
)