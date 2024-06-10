#include "Cat.h"

// Konstruktoriai
Cat::Cat() : name(""), breed(""), gender(""), weight(0.0), age(0) {}

Cat::Cat(std::string n, std::string b, std::string g, double w, int a)
        : name(n), breed(b), gender(g), weight(w), age(a) {}

// Set ir Get metodai
void Cat::setName(const std::string &n) { name = n; }

std::string Cat::getName() const { return name; }

void Cat::setBreed(const std::string &b) { breed = b; }

std::string Cat::getBreed() const { return breed; }

void Cat::setGender(const std::string &g) { gender = g; }

std::string Cat::getGender() const { return gender; }

void Cat::setWeight(double w) { weight = w; }

double Cat::getWeight() const { return weight; }

void Cat::setAge(int a) { age = a; }

int Cat::getAge() const { return age; }

// Išvesties operatorius <<
std::ostream &operator<<(std::ostream &os, const Cat &cat) {
    os << cat.name << " " << cat.breed << " "
       << cat.gender << " " << cat.weight
       << " " << cat.age;
    return os;
}

// Įvesties operatorius >>
std::istream &operator>>(std::istream &is, Cat &cat) {
    is >> cat.name >> cat.breed >> cat.gender >> cat.weight >> cat.age;
    return is;
}
