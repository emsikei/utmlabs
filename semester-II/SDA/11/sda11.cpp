#include "lib.h"

int main()
{
    std::string expr = "((1+((2+3)*(4+(5/6))))+((2*3)*(4-6)))";
    node *root = nullptr;
    buildParseTree(root, expr);
    std::cout << "Expression: " << expr << "\n";
    std::cout << "Inorder Tree Traversal: ";
    print(root);
    float res = parseTreeEvalution(root);
    std::cout << "\nThe result is: " << res << "\n";
    free(root);
    return 0;
}

