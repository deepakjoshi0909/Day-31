#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    std::string decodeString(const std::string& s) {
        std::stack<std::pair<std::string, int>> stk;
        std::string currentString = "";
        int currentNum = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                currentNum = currentNum * 10 + (ch - '0');
            } else if (ch == '[') {
                stk.push({currentString, currentNum});
                currentString = "";  
                currentNum = 0;      
            } else if (ch == ']') {
                auto [prevString, repeatCount] = stk.top();
                stk.pop();
                std::string tempString = currentString;
                currentString = prevString;

                for (int i = 0; i < repeatCount; ++i) {
                    currentString += tempString;
                }
            } else {
                currentString += ch;
            }
        }

        return currentString;
    }
};
