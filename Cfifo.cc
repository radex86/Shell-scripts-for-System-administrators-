//includes package ...
#include <string>
#include <iostream>
#include<fstream>
#include <pwd.h>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

// Help
void help() {
    std::cout << "NAME " << std::endl;
    std::cout << "   " << "Cfifo - create files using options" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "   " << "This command will either create a file or a folder based on the provided option. ";
    std::cout << "   " << "It was custom created by MANAR for studying purposes" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Options" << std::endl;
    std::cout << "   " << "-f --file " <<std::endl;
    std::cout << "   " << "    "<< "Create a file with the provided file name" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "   " << "-d --directory " <<std::endl;
    std::cout << "   " << "    "<< "Create a directory with the provided file name" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "   " << "-h --help " <<std::endl;
    std::cout << "   " << "    "<< "read about command execution and options" << std::endl;


}

// simple main ..

int main(int argc, char* argv[] )
//argv contain the list of the arguments
//similar to char * argv[]
//argv[0] command name 
// argv[1] options
//argv[2]  file/foldername
   {
    std::string option(argv[1]); //convert the arguments into string

    if (option == "" || option =="-f" || option == "--file")
    {
        std::string fname(argv[2]); //convert the file name

        if (fname == "") { std::cout << "error" << std::endl; return 1;}
          
          //Create and open a text file
          std::ofstream Cfifo(fname);

          // Write to the file
          Cfifo << "";

          // Close the file
          Cfifo.close();
          std::cout << "The request " << *(argv+2) << " is Created!" << std::endl;
    } 

    else if (option =="-d" || option == "--directory")
    {
        mkdir(argv[2],0777);
        std::cout << "The request: " << *(argv+2) << " is Created!" << std::endl;
    } 
    else if (option =="-h" || option == "--help")
    {
        help();
    } 

    else { std::cout << "error in execution "; return 1; }      
    return 0;
   }


