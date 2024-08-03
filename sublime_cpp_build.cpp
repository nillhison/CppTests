#include <iostream>
#include <string>
#include <cstdlib>
#include <filesystem>

int main(int argc, char** argv) {
	// argv[1] is expected to be the file_name
	// argv[2] is expected to be the file_base_name

	std::string compile_task = "cl.exe /EHs /std:c++20 ";
	compile_task.append(argv[1]);

	std::string run_task = argv[2];
	run_task.append(".exe");

	const char* compile = compile_task.c_str();
	const char* run = run_task.c_str();

	int compile_result = system(compile);
    if (compile_result != 0) {
        std::cout << "Compilation Errors. Verify them above" << std::endl;
        return 0;
    }

	system("cls");
	system(run);

	return 0;
	
}