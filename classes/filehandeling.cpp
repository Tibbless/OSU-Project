#include "filehandeling.hpp"

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