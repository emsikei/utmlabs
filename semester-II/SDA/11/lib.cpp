#include "lib.h"

void buildParseTree(node *&root, const std::string &expr)
{
    if (!root)
    {
        root = new node();
    }
    node *cur = root;
    std::stack<node *> S;
    S.push(root);

    for (size_t i = 0; i < expr.length(); ++i)
    {
        if (expr[i] == '(')
        {
            cur->left = new node();
            S.push(cur);
            cur = cur->left;
            continue;
        }
        if (isdigit(expr[i]))
        {
            cur->key += expr[i];
            continue;
        }

        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '/' || expr[i] == '*' || expr[i] == '^')
        {
            S.top()->key = expr[i];
            S.top()->right = new node();
            cur = S.top()->right;
            continue;
        }
        if (expr[i] == ')')
        {
            S.pop();
            if (!S.empty())
            {
                cur = S.top();
            }
        }
    }
}

float parseTreeEvalution(node *root)
{
    if (!root)
    {
        return 0;
    }

    if (root->key == "+")
    {
        return parseTreeEvalution(root->left) + parseTreeEvalution(root->right);
    }
    else if (root->key == "-")
    {
        return parseTreeEvalution(root->left) - parseTreeEvalution(root->right);
    }
    else if (root->key == "/")
    {
        if (parseTreeEvalution(root->right) == 0)
        {
            std::cout << "\nError!" << std::endl;
            exit(1);
        }
        return parseTreeEvalution(root->left) / parseTreeEvalution(root->right);
    }
    else if (root->key == "*")
    {
        return parseTreeEvalution(root->left) * parseTreeEvalution(root->right);
    }
    else if (root->key == "^")
    {
        if (parseTreeEvalution(root->left) == 0)
        {
            std::cout << "\nError!" << std::endl;
            exit(1);
        }
        return pow(parseTreeEvalution(root->left), parseTreeEvalution(root->right));
    }
    else
    {
        return atof(root->key.c_str());
    }
}

void print(node *root)
{
    if (!root)
        return;
    print(root->left);
    std::cout << root->key << " ";
    print(root->right);
}

void free(node *&root)
{
    if (!root)
    {
        return;
    }
    free(root->left);
    free(root->right);
    delete root;
    root = nullptr;
}

