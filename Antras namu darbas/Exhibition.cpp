#include "Exhibition.h"
#include <fstream>
#include <algorithm>
#include <sstream>

void Exhibition::addCat(const Cat &cat) {
    *this + cat;
}

void Exhibition::readFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            Cat cat;
            iss >> cat;
            *this + cat;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void Exhibition::writeToFile(const std::string &filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto &cat: items) {
            file << cat << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void Exhibition::updateCat(const std::string &name, const Cat &updatedCat) {
    auto it = std::find_if(items.begin(), items.end(),
                           [&](const Cat &cat) { return cat.getName() == name; });
    if (it != items.end()) {
        *it = updatedCat;
    }
}

void Exhibition::deleteCat(const std::string &name) {
    items.erase(std::remove_if(items.begin(), items.end(),
                               [&](const Cat &cat) { return cat.getName() == name; }), items.end());
}
