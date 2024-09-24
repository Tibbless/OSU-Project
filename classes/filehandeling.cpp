#include "filehandeling.hpp"
#include <filesystem>
#include <cstdlib>

namespace fs = filesystem;

fileHandeling::fileHandeling() {

    cout << "fileHandleing made. fileMap is empty" << endl;
}

void fileHandeling::displayFileNamesBulk() {
    // checks if our file map is empty if so display that and return
    if (files.empty()) {
        cout << "fileHandeling::displayFileNamesBulk() called. ";
        cout << "The file map is empty" << endl;
        return;
    }
    // instantiates our iterator to look through and list our files
    map<string, string>::iterator it = files.begin();
    // iterates through every item in file map
    while (it != files.end()) {
        cout << it->first << ", ";
        it++;
    }

    cout << endl;
    cout << "All files above" << endl;

    return;
}

// Displays all file names one by one on the command line
void fileHandeling::displayFileNamesSingle() {
    // checks if our file map is empty if so display that and return
    if (files.empty()) {
        cout << "fileHandeling::displayFileNamesSingle() called. ";
        cout << "The file map is empty" << endl;
        return;
    }
    // instantiates our iterator to look through and list our files
    map<string, string>::iterator it = files.begin();
    // iterates through every item in file map
    while (it != files.end()) {
        cout << it->first << endl;
        it++;
    }

    cout << endl;
    cout << "All files above" << endl;

    return;
}

// Get a single file name based on its index
string fileHandeling::getFileName(int index) {
    // checks if our file map is empty if so display that and return
    if (files.empty()) {
        cout << "fileHandeling::displayFileNamesSingle() called. ";
        cout << "The file map is empty" << endl;
        return;
    }
    // checks if our index is out of bounds if so display that and return
    if (files.size() <= index || index < 0)
    {
        cout << "fileHandeling::displayFileNamesSingle() called. ";
        cout << "The file map does not contain that indci" << endl;
        return;
    }
    // instantates our iterator to go to a specific index
    map<string, string>::iterator it = files.begin();
    // goes to our specific index
    advance(it, index);

    return it->first;
}

// Check if a file exists based on a name given. 0 for no 1 for yes
bool fileHandeling::fileExists(string file_name) {
    // checks if our file map is empty if so display that and return
    if (files.empty()) {
    cout << "fileHandeling::fileExists(string file_name) called. ";
    cout << "The file map is empty" << endl;
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
bool fileHandeling::addFile(string file_name, string file_path) {
    // checks to see if the given file name exists so we dont add duplicates
    if (files.find(file_name) != files.end())
    {
        cout << "The file " << file_name << " already exists." << endl;
        return 0;
    }
    // makes a new file path to the destination
    string destination = "../Holding/" + file_name;
    // attempts to move file, if it doesnt prints error in error console
    try {
        // moves the file to the holding folder
        fs::rename(file_path, destination);
        cout << "File moved to holding folder " << destination << endl;
        // inserts the file_name and new destination in holding folder into the map
        files.insert({file_name, destination});
        // if move is uncessessfull prints error
    } catch (const fs::filesystem_error& e) {
        cerr << "Error moving file: " << e.what() << endl;
        return 0;
    }

    return 1;
}

bool fileHandeling::unzipFolder(string folder_name, string folder_path) {
    // checks to see if the given folder exists so we dont add duplicates
    if (files.find(folder_name) != files.end())
    {
        cout << "The file " << folder_name << " already exists." << endl;
        return 0;
    }
    // sets destination folder
    string destination = "../Holding/";
    // creates unzip command
    string unzip_command = "unzip " + folder_path + " -d " + destination;
    // stores whether or not the file unzip successfully.
    int result = system(unzip_command.c_str());
    // Says if folder unziped correctly or not
    if (result == 0) {
        cout << "Successfully unzipped: " << folder_path << " to " << destination << endl;
        return 1;
    }
    else {
        cerr << "Failed to unzip: " << folder_path << ", fileHandeling::unzipFolder" << endl;
        return 0;
    }

    return 0;
}

bool folderContnetMove(string folder_path) {

    
    return 0;
}