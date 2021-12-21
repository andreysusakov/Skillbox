#include <iostream>

std::string encrypt_caesar (std::string text, int shift) {
    for (int i = 0; i < text.length(); i++) {
        if (((text[i] >= 'A' && text[i] <= 'Z') && (text[i] + shift < 'A' || text[i] + shift > 'Z')) ||
            ((text[i] >= 'a' && text[i] <= 'z') && (text[i] + shift < 'a' || text[i] + shift > 'z'))) {
            text[i] += shift - 26;
            }
        else if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')){
            text[i] += shift;
        }
    }
    return text;
}

std::string decrypt_caesar (std::string text, int shift) {
    encrypt_caesar(text, -shift);

    return text;
}


int main() {

//    11.6 Homework Task 1. Implementation of the Caesar cipher

    std::string text;

    int shift;
    std::cout << "Enter the text" << std::endl;
    std::getline(std::cin, text);
    std::cout << "Enter the shift" << std::endl;
    std::cin >> shift;

    std::cout << encrypt_caesar(text, shift) << std::endl;

    std::cout << decrypt_caesar (text, shift) << std::endl;
}