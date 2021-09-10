#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <algorithm>

#include "words_generator.hpp"

void WordsGenerator::parseRules(const std::vector<std::string> &rules)
{
    fillLetterSets(rules, Vn, Vt);

    for (size_t i = 0; i < Vn.size(); ++i)
    {
        parsedRules.emplace(Vn[i], std::vector<int>());
    }

    for (size_t i = 0; i < rules.size(); ++i)
    {
        for (auto &p : parsedRules)
        {
            if (p.first == rules[i][0])
            {
                p.second.push_back(i);
            }
        }
    }
}

std::unordered_set<std::string> WordsGenerator::generateString(int numberOfWords)
{
    parseRules(rules);
    // To be sure that we get random values every time we start the program
    std::srand(std::time(nullptr));

    // Container for unique generated words
    std::unordered_set<std::string> generatedStrings;

    while (generatedStrings.size() < numberOfWords)
    {

        // The string which will store the final word
        std::string str;

        // Starting point
        char start = 'S';

        // Vector-value of corresponding key to 'start' key in the parsedRules map
        std::vector<int> tmp = parsedRules[start];

        // Get random rule from initial list
        int randomRule = tmp[rand() % tmp.size()];
        str += rules[randomRule][1];

        while (true)
        {
            // Reassign start to the nominal letter in the rule (e.g. S -> aA - start = A)
            start = rules[randomRule][2];

            tmp = parsedRules[start];

            // If rules has no nominal symbol - break and add the word to the result
            // P.S the if statement is placed before randomRule calculation in that case if our words consists of only 1 letter
            if (rules[randomRule][2] == char(0))
            {
                if (!generatedStrings.count(str))
                {
                    generatedStrings.insert(str);
                }
                break;
            }

            randomRule = tmp[rand() % tmp.size()];

            str += rules[randomRule][1];
        }
    }
    return generatedStrings;
}

void WordsGenerator::printRules()
{
    std::cout << "  P = { ";
    for (size_t i = 0; i < rules.size(); ++i)
    {
        if (i != 0)
        {
            std::cout << "\t";
        }
        std::cout << i + 1 << ". " << rules[i][0] << " -> ";

        if (rules[i].length() == 3)
        {
            std::cout << rules[i][1] << rules[i][2];
        }
        else if (rules[i].length() == 2)
        {
            std::cout << rules[i][1];
        }
        if (i != rules.size() - 1)
        {
            std::cout << std::endl;
        }
    }
    std::cout << " }";
}

void WordsGenerator::fillLetterSets(const std::vector<std::string> &rules, std::vector<char> &Vn, std::vector<char> &Vt)
{
    for (size_t i = 0; i < rules.size(); ++i)
    {
        char nominalLetter = rules[i][0];
        char terminalLetter = rules[i][1];
        checkForDublicates(Vn, nominalLetter);
        checkForDublicates(Vt, terminalLetter);
    }
}

void WordsGenerator::checkForDublicates(std::vector<char> &vec, char key)
{
    if (std::find(vec.begin(), vec.end(), key) == vec.end())
    {
        vec.push_back(key);
    }
}