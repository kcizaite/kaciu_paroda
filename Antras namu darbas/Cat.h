#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>

class Cat {
private:
    std::string name;
    std::string breed;
    std::string gender;
    double weight;
    int age;

public:
    Cat();

    Cat(std::string n, std::string b, std::string g, double w, int a);

    void setName(const std::string &n);

    std::string getName() const;

    void setBreed(const std::string &b);

    std::string getBreed() const;

    void setGender(const std::string &g);

    std::string getGender() const;

    void setWeight(double w);

    double getWeight() const;

    void setAge(int a);

    int getAge() const;

    friend std::ostream &operator<<(std::ostream &os, const Cat &cat);

    friend std::istream &operator>>(std::istream &is, Cat &cat);
};

#endif // CAT_H
