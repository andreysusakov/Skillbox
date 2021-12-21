#include <iostream>

int main() {

    std::string number;
    int sum = 0;
    bool good = true;
    std::cout << "Enter a real number:" << std::endl;
    std::cin >> number;

    for (int i = 0; i < number.length(); i++){
        if (number == "-." || number[i] == 'e' || (number[i] < '-' || number[i] > '9')){
            good = false;
        }
    }

    for (int i = 0; i < number.length(); i++){
        if (number[i] == '.'){
            sum++;
        }
    }
    if (number == "."){
        std::cout << "0.\n" << "Yes!\n";
    }
    else if (sum == 1 && good){
        std::cout << "Yes!\n";
    }
    else{
        std::cout << "No!\n";
    }
    return 0;
}
