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


bool library_1 (std::string str, bool point = true, bool sum = true) {
    bool ok = point && sum;
    for (int i = 0; i < str.length() ; ++i) {
        if (str.length() < 1 || str.length() > 64 || str [i] == 32 || str [i] == 34 || str [i] == 40 || str [i] == 41 || str [i] == 58 || str [i] == 59
            || str [i] == 60 || str [i] == 62 || str [i] == 64 || str [i] == 91 || str [i] == 92 || str [i] == 93 || str [i] == 94
            || str [i] == 96 || str [i] == 127) {
            ok = false;
        }
    }
    return ok;
}

bool library_2 (std::string str, bool point = true, bool sum = true) {
    bool ok = point && sum;
    for (int i = 0; i < str.length() ; ++i) {
        if (str.length() < 1 || str.length() > 65 || (str [i] >= 32 && str [i] <= 44) || str [i] == 47 ||str [i] == 58 || str [i] == 59
            || (str [i] >= 60 && str [i] == 64) || (str [i] >= 91 && str [i] <= 96)
            || (str [i] >= 123 && str [i] <= 127)) {
            ok = false;
        }
    }
    return ok;
}


bool sum (std::string str) {
    int sum = 0;
    bool ok = true;
    for ( int i = 0; i < str.length(); ++i) {
        if (str [i] == '@'){
            sum++;
        }
    }
    if (sum != 1){
        ok = false;
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



    do {
        std::string str;std::cout << "Please enter a valid email address:\n";
        std::getline(std::cin, str);
        p_1 = library_1 (part_1 (str, '@'), point (part_1 (str, '@') , '.'), sum (str));
        p_2 = library_2 (part_2 (str, '@'), point (part_2 (str, '@') , '.'), sum (str));
        std::cout << (p_1 && p_2 ? "Yes!\n" : "No!\n");

    }while (!p_1 || !p_2);
}