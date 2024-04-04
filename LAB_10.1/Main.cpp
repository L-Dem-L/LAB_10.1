#include <iostream>
#include <fstream>
#include <string>

bool hasTripleStars(const std::string& filename) {
    std::ifstream file(filename); // Open file for reading
    if (!file.is_open()) {
        std::cerr << "Failed to open the file " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) { // Read file line by line
        size_t found = line.find("***"); // Search for a group of three asterisks
        if (found != std::string::npos) {
            file.close(); // Close the file
            return true; // Return true if the group is found
        }
    }

    file.close(); // Close the file
    return false; // Return false if the group is not found
}

int main() {
    std::string filename;
    std::cout << "Enter the filename to search for triple stars: ";
    std::cin >> filename; // Input the filename
    if (hasTripleStars(filename)) {
        std::cout << "The file contains a group of three consecutive stars." << std::endl;
    }
    else {
        std::cout << "The file does not contain a group of three consecutive stars." << std::endl;
    }

    return 0;
}
