#include <iostream>


std::string part_1 (std::string str, char symbol) {
    std::string part_1 = "";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != symbol) {
            part_1 += str[i];
        } else {
            break;
        }
    }
    return part_1;
}

std::string part_2 (std::string str, char symbol) {
    std::string part_2 = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == symbol) {
            int point = i;
            for (int j = point + 1; j < str.length(); j++) {
                part_2 += str[j];
            }
            break;
        }
    }
    return part_2 ;
}


bool library_1 (std::string str, bool point = true) {
    bool ok = point;
    for (int i = 0; i < str.length() ; ++i) {

        if (str.length() < 1 || str.length() > 3 || (str.length() > 1 && str [0] == '0') || (str.length() == 3 &&
            (str [0] > '2' || (str [0] == '2' && str [1] > '5') || (str [0] == '2' && str[1] == '5' && str [2] > '5')) || str [i] < '0' || str [i] > '9')) {
            ok = false;
        }
    }
    return ok;
}

bool point (std::string str, char symbol) {
    int dot;
    bool ok = true;
    for (int j = 0; j < str.length(); ++j) {
        if (str[j] == symbol) {
            dot = j;
        }
    }
    ok = !(str[dot - 1] == symbol || str[dot + 1] == symbol || str[0] == symbol || str[str.length() - 1] == symbol);
    return ok;
}



int main() {

    std::string str;
    bool p_1 = true;
    bool p_2 = true;
    bool p_3 = true;
    bool p_4 = true;
    std::string number_1;
    std::string number_2;

    do {
        std::cout << "Please enter a valid IP-address:\n";
        std::getline(std::cin, str);
        p_1 = library_1 (part_1 (str, '.'), point(str, '.'));
        number_1 = part_2 (str, '.');
        p_2 = library_1 (part_1 (number_1, '.'), point(str, '.'));
        number_2 = part_2 (number_1, '.');
        p_3 = library_1 (part_1 (number_2, '.'), point(str, '.'));
        p_4 = library_1 (part_2 (number_2, '.'), point(str, '.'));

        std::cout << (p_1 && p_2 && p_3 && p_4 ? "Yes!\n" : "No!\n");

    }while (!p_1 || !p_2 || !p_3 || !p_4);
}