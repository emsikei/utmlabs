#pragma once
#include <string>
#include <vector>

struct CARS
{
    std::string name{""};
    std::string model{""};
    std::string country{""};
    int year{0};
    int hp{0};
    int price{0};

    void print();
};

void open_file(std::ifstream &file, std::vector<CARS> &cars);
void find_name(std::string str, std::vector<CARS> cars);
void find_model(std::string str, std::vector<CARS> cars);
void find_country(std::string str, std::vector<CARS> cars);
void find_year(int year, std::vector<CARS> cars);
void find_hp(int hp, std::vector<CARS> cars);
void find_price(int price, std::vector<CARS> cars);
void sortMenu(std::vector<CARS> &cars);
bool cmpByNameUp(const CARS &a, const CARS &b);
bool cmpByNameDown(const CARS &a, const CARS &b);
bool cmpByModelUp(const CARS &a, const CARS &b);
bool cmpByModelDown(const CARS &a, const CARS &b);
bool cmpByCountryUp(const CARS &a, const CARS &b);
bool cmpByCountryDown(const CARS &a, const CARS &b);
bool cmpByYearUp(const CARS &a, const CARS &b);
bool cmpByYearDown(const CARS &a, const CARS &b);
bool cmpByHpUp(const CARS &a, const CARS &b);
bool cmpByHpDown(const CARS &a, const CARS &b);
bool cmpByPriceUp(const CARS &a, const CARS &b);
bool cmpByPriceDown(const CARS &a, const CARS &b);
void changeElement(size_t pos, std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price);
void pushElement(std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price);
void deleteElement(size_t pos, std::vector<CARS> &cars);
void insertElement(size_t pos, std::vector<CARS> &cars, std::string name, std::string model, std::string country, int year, int hp, int price);
void writeToFile(std::ofstream &write_file, std::string name, std::string model, std::string country, int year, int hp, int price);
