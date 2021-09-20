#include <iostream>
#include <vector>
#include <unordered_set>

#include "words_generator.hpp"

void print(const std::unordered_set<std::string> &set)
{
    int i = 1;
    for (const auto &element : set)
    {
        std::cout << i << "). " << element << std::endl;
        i++;
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
    std::unordered_set<std::string> result = generator.generateStrings(15, 5);
    generator.printRules();
    std::cout << "\n";
    print(result);
}
