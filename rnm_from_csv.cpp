#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

string buildCommand(string oldName, string newName) {
    string command = "rename \"" + oldName + "\" \"" + newName + "\"";
    return command;
}

int main(int argc, char *argv[]) {

    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    if(argc == 1) return 0;

    string oldName, newName;
    fstream csv;

    map<string, string> database;

    csv.open(argv[1], ios::in);
    
    while (!csv.eof()) {
        getline(csv, oldName, ';');
        getline(csv, newName);
        database.insert(std::pair<string, string>(oldName, newName));
    }
    
    for(const auto& line : database) {
        system(buildCommand(line.first, line.second).c_str());
    }
}