#include <iostream>
#include <string>
#include <sstream>

int lengthOfLastWord(const std::string& s) {
    std::istringstream iss(s);
    std::string word;

    // Extract words from the string
    while (iss >> word) {
        // The last word will be stored in 'word' after the loop
    }

    // Return the length of the last word
    return word.length();
}

int main() {
    std::string inputString;

    // Get input from the user
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    int result = lengthOfLastWord(inputString);

    std::cout << "Length of the last word: " << result << std::endl;

    return 0;
}
