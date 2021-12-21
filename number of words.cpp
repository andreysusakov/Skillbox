#include <iostream>

int main() {

    std::string str;
    int sum = 0;

    std::cout << "Enter the text:" << std::endl;
    std::getline(std::cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ' && (str[i + 1] == ' ' || (i + 1) == (str.length() - 1))){
            sum ++;
        }
    }
    std::cout << "Number of words: " << sum << std::endl;
}
