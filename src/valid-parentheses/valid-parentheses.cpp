#include <algorithm.hpp>
#include <stack>

bool ValidParentheses::isValid(string s)
{
    // For every character in s,
    // For a "open" bracket, push it to the stack
    // For a "close" bracket,
    // Return false if stack is empty
    // Return false it doesn't match the top bracket
    // Pop the top bracket
    // Return true if stack is empty if reach the end of s

    string openBrackets = "({[";
    string closeBrackets = ")}]";

    stack<char> check;

    for (int i = 0; i < s.length(); i++)
    {
        char current = s[i];

        size_t find = closeBrackets.find(current);

        if (find == string::npos)
        {
            check.push(current);
        }
        else
        {
            if (check.empty())
                return false;

            if (check.top() != openBrackets[find])
            {
                return false;
            }

            check.pop();
        }
    }

    return check.size() == 0;
}