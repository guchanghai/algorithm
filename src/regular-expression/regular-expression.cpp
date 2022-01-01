#include <algorithm.hpp>
#include <string>

bool RegularExpression::isMatch(string s, string p) {
    // Iterator pattern p

    // For current pattern letter

    // Iterator string s from last position

    /* Cases:
        a-z :
            1. Update it as the current-match-character
            2. Compare current-match-character with current character of s
                - if different, then return false
                - if true:
                    - Move to next position of both s and p
        * :
            1. Compare current-match-character with current character of s
                - if different, then return false
                - if true:
                    - Move to next position of s

        . :
            1. Update current character of s as current-match-character
                - Move to next position of s
    */

    // return true if reach the end

    char currentMatchChar = '-';
    int checkedPos = 0;

    // Iterator pattern p
    int i = 0, j =0;

    for( ; i < p.length(); i++){

        if( checkedPos == s.length() ){
            return false;
        }

        char checkingPatternChar = p[i];

        // Iterator string s from last position
        for(j = checkedPos ; j < s.length(); j++ ){
            char charToCompare = s[j];
            bool checkNextPattern = false;

            switch (checkingPatternChar){
                case '.':
                    currentMatchChar = charToCompare;
                    break;

                case '*':
                    if( currentMatchChar != charToCompare ){
                        return false;
                    }
                    break;

                default:
                    currentMatchChar = charToCompare;
                    if( checkingPatternChar != charToCompare ){
                        return false;
                    }

                    checkNextPattern = true;
            }

            // check next checkNextPattern
            if( checkNextPattern ){
                checkedPos = j+1;
                break;
            }
        }
    }

    return j == s.length() && i == p.length();
};