#ifndef FILEHANDELING_HPP
#define FILEHANDELING_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class fileHandeling {

    private: 
        std::map<std::string, std::string> files;

    public:
        // Constructor
        fileHandeling();

        // Displays all file names in one large text block
        void displayFileNamesBulk();
    
        // Displays all file names one by one on the command line
        void displayFileNamesSingle();

        // Get a single file name based on its indici
        std::string getFileName(int);
        
        // Check if a file exists based on a name given. true for exists false for doesnt exist
        bool fileExists(std::string);

        // Adds a file given the path and file name
        bool addFile(std::string, std::string);

        // unzips a given folder
        bool unzipFolder(std::string, std::string);

        // moves content of a folder
        bool folderContnetMove(std::string);
    
};  


#endif // FILEHANDELING_HPP