#ifndef EXHIBITION_H
#define EXHIBITION_H

#include "List.h"
#include "Cat.h"
#include <string>

class Exhibition : public List<Cat> {
public:
    void addCat(const Cat &cat);

    void readFromFile(const std::string &filename);

    void writeToFile(const std::string &filename) const;

    void updateCat(const std::string &name, const Cat &updatedCat);

    void deleteCat(const std::string &name);
};

#endif
