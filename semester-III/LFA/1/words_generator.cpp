#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <algorithm>

#include "words_generator.hpp"

std::unordered_set<std::string> WordsGenerator::generateStrings(int numberOfWords, int minLength)
{
    // Get e.g a map  "S": {0}
    //                "A": {1, 2}
    //                "B": {3, 4, 5}
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

        // Add terminal symbol to resulting string (e.g S -> aA - str += "a")
        str += rules[randomRule][1];

        while (true)
        {
            // If rules has no nonterminal symbol - break and add the word to the result
            if (rules[randomRule][2] == char(0))
            {
                if (!generatedStrings.count(str) && str.length() >= minLength)
                {
                    generatedStrings.insert(str);
                }
                break;
            }

            // Reassign start to the nonterminal letter in the rule (e.g. S -> aA - start = A)
            start = rules[randomRule][2];

            tmp = parsedRules[start];

            randomRule = tmp[rand() % tmp.size()];

            str += rules[randomRule][1];
        }
    }
    return generatedStrings;
}

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
            // if the key in the map equals to the nonterminal symbol in the  rule than add rule's index to the key's value
            if (p.first == rules[i][0])
            {
                p.second.push_back(i);
            }
        }
    }
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
        char nonterminalLetter = rules[i][0];
        char terminalLetter = rules[i][1];
        checkForDublicates(Vn, nonterminalLetter);
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