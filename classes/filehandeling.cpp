#include "filehandeling.hpp"
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

fileHandeling::fileHandeling() {

    std::cout << "fileHandleing made. fileMap is empty\n";
}

void fileHandeling::displayFileNamesBulk() {
    // checks if our file map is empty if so display that and return
    if (files.empty()) {
        std::cout << "fileHandeling::displayFileNamesBulk() called. ";
                     "The file map is empty.\n";
        return;
    }
    // instantiates our iterator to look through and list our files
    std::map<std::string, std::string>::iterator it = files.begin();
    // iterates through every item in file map
    while (it != files.end()) {
        std::cout << it->first << ", ";
        it++;
    }

    std::cout << "\n";
                 "All files above\n";

    return;
}

// Displays all file names one by one on the command line
void fileHandeling::displayFileNamesSingle() {
    // checks if our file map is empty if so display that and return
    if (files.empty()) {
        std::cout << "fileHandeling::displayFileNamesSingle() called. ";
                     "The file map is empty.\n";
        return;
    }
    // instantiates our iterator to look through and list our files
    std::map<std::string, std::string>::iterator it = files.begin();
    // iterates through every item in file map
    while (it != files.end()) {
        std::cout << it->first << std::endl;
        it++;
    }

    std::cout << "\n";
                 "All files above.\n";

    return;
}

// Get a single file name based on its index
std::string fileHandeling::getFileName(int index) {
    // checks if our file map is empty if so display that and return
    if (files.empty()) {
        std::cout << "fileHandeling::displayFileNamesSingle() called. ";
                     "The file map is empty.\n";
        return;
    }
    // checks if our index is out of bounds if so display that and return
    if (files.size() <= index || index < 0)
    {
        std::cout << "fileHandeling::displayFileNamesSingle() called. ";
                     "The file map does not contain that indci.\n";
        return;
    }
    // instantates our iterator to go to a specific index
    std::map<std::string, std::string>::iterator it = files.begin();
    // goes to our specific index
    advance(it, index);

    return it->first;
}

// Check if a file exists based on a name given. 0 for no 1 for yes
bool fileHandeling::fileExists(std::string file_name) {
    // checks if our file map is empty if so display that and return
    if (files.empty()) {
    std::cout << "fileHandeling::fileExists(string file_name) called. "
                 "The file map is empty.\n";
    return 0;
    }
    // checks to see if the given file name exists
    if (files.find(file_name) != files.end())
    {
        return 1;
    }
    
    return 0;
}

// Adds a file given the path and file name, returns 1 if adds returns 0 if it doesnt
bool fileHandeling::addFile(std::string file_name, std::string file_path) {
    // checks to see if the given file name exists so we dont add duplicates
    if (files.find(file_name) != files.end())
    {
        std::cout << "The file " << file_name << " already exists.\n";
        return 0;
    }
    // makes a new file path to the destination
    std::string destination = "../Holding/" + file_name;
    // attempts to move file, if it doesnt prints error in error console
    try {
        // moves the file to the holding folder
        fs::rename(file_path, destination);
        std::cout << "File moved to holding folder " << destination << "\n";
        // inserts the file_name and new destination in holding folder into the map
        files.insert({file_name, destination});
        // if move is uncessessfull prints error
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error moving file: " << e.what() << "\n";
        return 0;
    }

    return 1;
}

// Unzips a folder to a given folder path
bool fileHandeling::unzipFolder(std::string folder_name, std::string folder_path) {
    // checks to see if the given folder exists so we dont add duplicates
    if (files.find(folder_name) != files.end())
    {
        std::cout << "The file " << folder_name << " already exists.\n";
        return 0;
    }
    // sets destination folder
    std::string destination = "../Holding/";
    // creates unzip command
    std::string unzip_command = "unzip " + folder_path + " -d " + destination;
    // stores whether or not the file unzip successfully.
    int result = system(unzip_command.c_str());
    // Says if folder unziped correctly or not
    if (result == 0) {
        std::cout << "Successfully unzipped: " << folder_path << " to " << destination << "\n";
        return 1;
    }
    else {
        std::cerr << "Failed to unzip: " << folder_path << ", fileHandeling::unzipFolder" << "\n";
        return 0;
    }

    return 0;
}

// Moves the contents of a folder to a given folder path
bool folderContnetMove(std::string current_path) {

    fs::path fs_current_path = current_path;
    // fs::path fs_move_path = move_path;

    try {

    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what () << "\n";
        return false;
    }

    return 0;
}