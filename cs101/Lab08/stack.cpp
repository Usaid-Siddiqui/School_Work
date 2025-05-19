#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>');
}

bool isLeftSymbol(char c) {
    return c == '(' || c == '[' || c == '{' || c == '<';
}

bool isRightSymbol(char c) {
    return c == ')' || c == ']' || c == '}' || c == '>';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: ./stack \"<string>\"" << endl;
        return 1;
    }

    string input = argv[1];
    vector<char> stack;

    cout << "Stack:" << endl;
    for (char c : input) {
        cout << "Character: " << c << endl;
        if (isLeftSymbol(c)) {
            stack.push_back(c);
            cout << "Push" << endl;
        } else if (isRightSymbol(c)) {
            if (stack.empty()) {
                cout << "Error: unmatched right symbol " << c << endl;
                return 1;
            }
            char top = stack.back();
            stack.pop_back();
            if (!isMatchingPair(top, c)) {
                cout << "Error: mismatched pair " << top << " and " << c << endl;
                return 1;
            }
            cout << "Matching " << top << " and " << c << "\nPop" << endl;
        } else {
            cout << "Error: invalid character " << c << endl;
            return 1;
        }
        
        cout << "Stack: ";
        for (char s : stack) cout << s << " ";
        cout << endl;
    }

    cout << "Reached end of string" << endl;
    if (stack.empty()) {
        cout << "String is properly balanced" << endl;
    } else {
        cout << "Error: unmatched left symbol " << stack.back() << endl;
        return 1;
    }

    return 0;
}
