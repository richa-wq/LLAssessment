#include <iostream>
#include <string>
#include <algorithm> // Include this header for the reverse function
#include <vector>

std::string shortestPalindrome(const std::string& s) {
    std::string revS = s;
    std::reverse(revS.begin(), revS.end());

    std::string newString = s + "#" + revS;

    // Build KMP table
    std::vector<int> kmpTable(newString.size(), 0);
    for (int i = 1, j = 0; i < newString.size(); ) {
        if (newString[i] == newString[j]) {
            kmpTable[i++] = ++j;
        } else {
            if (j > 0) {
                j = kmpTable[j - 1];
            } else {
                kmpTable[i++] = 0;
            }
        }
    }

    // The length of the longest palindrome suffix in the combined string
    int longestPalindromeLength = kmpTable.back();

    // Build the result by adding the reversed remaining part of the string
    return revS.substr(0, s.size() - longestPalindromeLength) + s;
}

int main() {
    std::string inputString;
    
    // Get input from the user
    std::cout << "Enter a string: ";
    std::cin >> inputString;

    std::string result = shortestPalindrome(inputString);

    std::cout << "Shortest Palindrome: " << result << std::endl;

    return 0;
}
