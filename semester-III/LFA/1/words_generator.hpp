#pragma once
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class WordsGenerator
{
public:
    WordsGenerator(std::vector<std::string> _rules) : rules(_rules) {}
    void printRules();
    std::unordered_set<std::string> generateStrings(int numberOfWords);

private:
    void parseRules(const std::vector<std::string> &rules);
    void fillLetterSets(const std::vector<std::string> &rules, std::vector<char> &Vn, std::vector<char> &Vt);
    void checkForDublicates(std::vector<char> &vec, char key);

    std::vector<std::string> rules;
    std::unordered_map<char, std::vector<int>> parsedRules;
    std::vector<char> Vn;
    std::vector<char> Vt;
};