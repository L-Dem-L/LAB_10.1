#include <iostream>
#include <fstream>
#include <string>

bool hasTripleStars(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) { 
        size_t found = line.find("***");
        if (found != std::string::npos) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

int main() {
    std::string filename;
    std::cout << "Enter the filename to search for triple stars: ";
    std::cin >> filename;
    if (hasTripleStars(filename)) {
        std::cout << "The file contains a group of three consecutive stars." << std::endl;
    }
    else {
        std::cout << "The file does not contain a group of three consecutive stars." << std::endl;
    }

    return 0;
}
