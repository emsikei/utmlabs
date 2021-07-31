#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    int count = 0;
    string str, word;
    char ch;
    ifstream file;
    file.open("lab5v10.txt");
    getline(file, str);
    string inaprop = "#!,.%?/\[&]{}^$'\"@~*|><+=)(;:0123456789";
    for (char c : inaprop)
    {
        str.erase(remove(str.begin(), str.end(), c), str.end());
    }
    cout << "Your string is: \n" << str << endl;
    cout << "Enter your letter: ";
    ch = getchar();
    putchar(ch);
    cout << "\n\n";
    stringstream words(str);
    while (words >> word)
    {
        if (tolower(word[0]) == tolower(ch))
        {
            count++;
            cout << "№" << count << ": " << word << endl;
        }
    }
    cout << "\nThe amount of words starting with the letter \'" << ch << "\' is: " << count << endl;
    system("pause");
    return 0;
}

