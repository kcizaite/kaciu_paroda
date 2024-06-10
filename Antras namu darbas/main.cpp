#include <iostream>
#include "Exhibition.h"

void displayMenu() {
    std::cout << "1. Prideti kate\n";
    std::cout << "2. Kaciu sarasas\n";
    std::cout << "3. Redaguoti kate\n";
    std::cout << "4. Istrinti kate\n";
    std::cout << "5. Issaugoti i faila\n";
    std::cout << "6. Programos pabaiga\n";
    std::cout << "Iveskite savo pasirinkima: ";
}

int main() {
    Exhibition exhibition;
    exhibition.readFromFile(
            "Cats.txt");

    int choice;
    std::string name, breed, gender;
    double weight;
    int age;
    Cat cat;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Iveskite kates duomenis (vardas, veisle, lytis, svoris, amzius): ";
                std::cin >> cat;
                exhibition.addCat(cat);
                break;
            case 2:
                std::cout << "Siuo metu parodoje dalyvaujancios kates:" << std::endl;
                exhibition.display();
                break;
            case 3:
                std::cout << "Iveskite norimos redaguoti kates varda: ";
                std::cin >> name;
                std::cout << "Iveskite naujus kates duomenis (vardas, veisle, lytis, svoris, amzius): ";
                std::cin >> cat;
                exhibition.updateCat(name, cat);
                break;
            case 4:
                std::cout << "Iveskite norimos istrinti kates varda: ";
                std::cin >> name;
                exhibition.deleteCat(name);
                break;
            case 5:
                exhibition.writeToFile("Cats.txt");
                std::cout << "Kate saugoma i faila." << std::endl;
                break;
            case 6:
                std::cout << "Programos pabaiga..." << std::endl;
                break;
            default:
                std::cout << "Neteisingas pasirinkimas. Meginkite dar karta." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
