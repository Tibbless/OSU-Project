#ifndef FILEHANDELING_HPP
#define FILEHANDELING_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class fileHandeling {

    private: 
        map<string, string> files;

    public:
        // Constructor
        fileHandeling();

        // Displays all file names in one large text block
        void displayFileNamesBulk();
    
        // Displays all file names one by one on the command line
        void displayFileNamesSingle();

        // Get a single file name based on its indici
        string getFileName(int);
        
        // Check if a file exists based on a name given. true for exists false for doesnt exist
        bool fileExists(string);


};  


#endif // FILEHANDELING_HPP