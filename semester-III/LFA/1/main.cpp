#include <iostream>
#include <vector>
#include <unordered_set>

#include "words_generator.hpp"

void print(const std::unordered_set<std::string> &set)
{
    for (const auto &element : set)
    {
        std::cout << element << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> rules;

    rules.push_back("SaA");
    rules.push_back("AbB");
    rules.push_back("Ab");
    rules.push_back("BcB");
    rules.push_back("Bc");
    rules.push_back("BcS");

    WordsGenerator generator(rules);
    std::unordered_set<std::string> result = generator.generateStrings(15, 6);
    generator.printRules();
    std::cout << "\n";
    print(result);
}
