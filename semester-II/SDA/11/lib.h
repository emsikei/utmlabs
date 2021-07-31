#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

struct node
{
    std::string key{""};
    node *left{nullptr};
    node *right{nullptr};
};

void buildParseTree(node *&root, const std::string &expr);
void print(node *root);
float parseTreeEvalution(node *root);
void free(node *&root);