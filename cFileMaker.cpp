/*
 *   Creator: Ernest M Duckworth IV
 *   Date: Wed Aug 25 09:24:51 2021
 *   For: Creates a C basic C file
 *   Description: Creates header and basic C program
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "Colors.hpp"

using namespace std;

//Protos
bool checkFile(const string &);
void buildFile(const string &);

//Creates a file based of arguments and if it is possible
int main(int argc, const char *argv[]){
    Colors c;
    string file = (argc > 1) ? argv[1] : "main";

    //Forces you to give a file name that wont erase currently existing one
    while(!checkFile(file+".c")){
       cout << c.red << "File already exists (\"" << file << "\")\n";
       cout << c.yellow << "New file name: " << c.pink;
       cin >> file;
    }

    file = file + ".c";
    buildFile(file);

    cout << c.green << "Successfully created file: " << c.pink << file << '\n';
    return 0;
}

//Returns true if there is not a file
bool checkFile(const string &f){
    ifstream check(f);
    return !check;
}

//Builds basic C program
void buildFile(const string &file){
   auto t = time(0);
   auto now = ctime(&t);
   ofstream out(file);
   out << "/*\n"
       << " *   Creator: Ernest M Duckworth IV\n"
       << " *   Date: " << now
       << " *   For: \n"
       << " *   Description: \n"
       << "*/\n"
       << "#include <stdio.h>\n"
       << "#include <stdlib.h>\n\n"
       << "int main(int argc, char *argv[]){\n"
       << "    printf(\"Hello World!\");\n"
       << "    return 0;\n"
       << "}\n";
}


