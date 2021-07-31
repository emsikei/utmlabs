#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "lib.h"

void CARS::print()
{
    std::cout << this->name << " " << this->model << " " << this->country << " " << this->year << " " << this->hp << " " << this->price << std::endl;
}

void open_file(std::ifstream &read_file, std::vector<CARS> &cars)
{
    if (read_file.is_open())
    {
        std::string buf;
        while (getline(read_file, buf, '\n'))
        {
            char line[100];
            strcpy(line, buf.c_str());
            const char *delim = ",\"\n";
            char *token = strtok(line, delim);

            if (!strcmp(token, "Name"))
                continue;

            CARS tmp;

            while (token)
            {
                if (tmp.name == "")
                {
                    tmp.name = token;
                }
                else if (tmp.model == "")
                {
                    tmp.model = token;
                }
                else if (tmp.country == "")
                {
                    tmp.country = token;
                }
                else if (tmp.year == 0)
                {
                    tmp.year = atoi(token);
                }
                else if (tmp.hp == 0)
                {
                    tmp.hp = atoi(token);
                }
                else if (tmp.price == 0)
                {
                    tmp.price = atoi(token);
                }
                token = strtok(NULL, delim);
            }
            cars.push_back(tmp);
        }
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

void find_name(std::string str, std::vector<CARS> cars)
{
    for (size_t i = 0; i < cars.size(); ++i)
    {
        if (str == cars[i].name)
        {
            cars[i].print();
        }
    }
};

void find_model(std::string str, std::vector<CARS> cars)
{
    for (size_t i = 0; i < cars.size(); ++i)
    {
        if (str == cars[i].model)
        {
            cars[i].print();
        }
    }
};

void find_country(std::string str, std::vector<CARS> cars)
{
    for (size_t i = 0; i < cars.size(); ++i)
    {
        if (str == cars[i].country)
        {
            cars[i].print();
        }
    }
};

void find_year(int year, std::vector<CARS> cars)
{
    for (size_t i = 0; i < cars.size(); ++i)
    {
        if (year == cars[i].year)
        {
            cars[i].print();
        }
    }
};

void find_hp(int hp, std::vector<CARS> cars)
{
    for (size_t i = 0; i < cars.size(); ++i)
    {
        if (hp == cars[i].hp)
        {
            cars[i].print();
        }
    }
};

void find_price(int price, std::vector<CARS> cars)
{
    for (size_t i = 0; i < cars.size(); ++i)
    {
        if (price == cars[i].price)
        {
            cars[i].print();
        }
    }
};

bool cmpByNameUp(const CARS &a, const CARS &b)
{
    return a.name[0] < b.name[0];
}

bool cmpByNameDown(const CARS &a, const CARS &b)
{
    return a.name[0] > b.name[0];
}

bool cmpByModelUp(const CARS &a, const CARS &b)
{
    return a.model[0] < b.model[0];
}

bool cmpByModelDown(const CARS &a, const CARS &b)
{
    return a.model[0] > b.model[0];
}

bool cmpByCountryUp(const CARS &a, const CARS &b)
{
    return a.country[0] < b.country[0];
}

bool cmpByCountryDown(const CARS &a, const CARS &b)
{
    return a.country[0] > b.country[0];
}

bool cmpByYearUp(const CARS &a, const CARS &b)
{
    return a.year < b.year;
}

bool cmpByYearDown(const CARS &a, const CARS &b)
{
    return a.year > b.year;
}

bool cmpByHpUp(const CARS &a, const CARS &b)
{
    return a.hp < b.hp;
}

bool cmpByHpDown(const CARS &a, const CARS &b)
{
    return a.hp > b.hp;
}

bool cmpByPriceUp(const CARS &a, const CARS &b)
{
    return a.price < b.price;
}

bool cmpByPriceDown(const CARS &a, const CARS &b)
{
    return a.price > b.price;
}

void sortMenu(std::vector<CARS> &cars)
{
    std::cout << "1. Sort by Name Down" << std::endl;
    std::cout << "2. Sort by Name Up" << std::endl;
    std::cout << "3. Sort by Model Down" << std::endl;
    std::cout << "4. Sort by Model Up" << std::endl;
    std::cout << "5. Sort by Country Down" << std::endl;
    std::cout << "6. Sort by Country Up" << std::endl;
    std::cout << "7. Sort by Year Down" << std::endl;
    std::cout << "8. Sort by Year Up" << std::endl;
    std::cout << "9. Sort by Hp Down" << std::endl;
    std::cout << "10. Sort by Hp Up" << std::endl;
    std::cout << "11. Sort by Price Down" << std::endl;
    std::cout << "12. Sort by Price Up" << std::endl;

    size_t choice = 0;
    std::cout << "How do you want to sort your list? ";
    std::cin >> choice;
    std::cout << std::endl;
    if (choice == 1)
    {
        std::sort(cars.begin(), cars.end(), cmpByNameDown);
    }
    if (choice == 2)
    {
        std::sort(cars.begin(), cars.end(), cmpByNameUp);
    }
    if (choice == 3)
    {
        std::sort(cars.begin(), cars.end(), cmpByModelDown);
    }
    if (choice == 4)
    {
        std::sort(cars.begin(), cars.end(), cmpByModelUp);
    }
    if (choice == 5)
    {
        std::sort(cars.begin(), cars.end(), cmpByCountryDown);
    }
    if (choice == 6)
    {
        std::sort(cars.begin(), cars.end(), cmpByCountryUp);
    }
    if (choice == 7)
    {
        std::sort(cars.begin(), cars.end(), cmpByYearDown);
    }
    if (choice == 8)
    {
        std::sort(cars.begin(), cars.end(), cmpByYearUp);
    }
    if (choice == 9)
    {
        std::sort(cars.begin(), cars.end(), cmpByHpDown);
    }
    if (choice == 10)
    {
        std::sort(cars.begin(), cars.end(), cmpByHpUp);
    }
    if (choice == 11)
    {
        std::sort(cars.begin(), cars.end(), cmpByPriceDown);
    }
    if (choice == 12)
    {
        std::sort(cars.begin(), cars.end(), cmpByPriceUp);
    }
}

void changeElement(size_t pos, std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price)
{
    size_t len = cars.size();
    if (pos > len || pos <= 0)
    {
        std::cout << "Incorrect index" << std::endl;
    }
    else
    {
        cars[pos - 1].name = name;
        cars[pos - 1].model = model;
        cars[pos - 1].country = country;
        cars[pos - 1].year = year;
        cars[pos - 1].hp = hp;
        cars[pos - 1].price = price;
    }
}

void pushElement(std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price)
{
    CARS tmp;
    tmp.name = name;
    tmp.model = model;
    tmp.country = country;
    tmp.year = year;
    tmp.hp = hp;
    tmp.price = price;
    cars.push_back(tmp);
}

void deleteElement(size_t pos, std::vector<CARS> &cars)
{
    size_t len = cars.size();
    if (pos > len || pos <= 0)
    {
        std::cout << "Incorrect index" << std::endl;
    }
    else
    {
        cars.erase(cars.begin() + (pos - 1));
    }
}

void insertElement(size_t pos, std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price)
{
    size_t len = cars.size();
    if (pos > len || pos <= 0)
    {
        std::cout << "Incorrect index" << std::endl;
    }
    else
    {
        CARS tmp;
        tmp.name = name;
        tmp.model = model;
        tmp.country = country;
        tmp.year = year;
        tmp.hp = hp;
        tmp.price = price;
        cars.insert(cars.begin() + (pos - 1), tmp);
    }
}

void writeToFile(std::ofstream &write_file, std::string name, std::string model, std::string country, int year, int hp, int price)
{
    write_file << name << "," << model << "," << country << "," << year << "," << hp << "," << price << std::endl;
}