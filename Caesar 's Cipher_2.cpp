#include <iostream>


std::string decrypt_caesar (std::string text, int shift) {
    for (int i = 0; i < text.length(); i++)  {
        if  (text [i] - shift < 32){
            text [i] = int (text [i] - shift) + 128 - ' ';
        }
        else if (text [i] >= ' ' && text [i] <= '~'){
            text [i] -= shift;
        }
    }
    return text;
}

int main() {

//    11.6 Homework Task 1. Implementation of the Caesar cipher

    std::string text;
    std::string encrypt_text;
    int shift;

    std::cout << "Enter the encrypt text" << std::endl;
    std::getline(std::cin, encrypt_text);
    std::cout << "Enter the shift" << std::endl;
    std::cin >> shift;

    std::cout << decrypt_caesar (encrypt_text, shift) << std::endl;
    return 0;
}
