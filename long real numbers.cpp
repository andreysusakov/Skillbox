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


bool examination_1 (std::string str, bool point = true) {
    bool ok = point;
    bool minus = str.length() > 0 && str [0] == '-';
    int start_pos = minus ? 1 : 0;
    for (int i = start_pos; i < str.length() ; ++i) {
        if (str [i] < '0' || str [i] > '9') {
            ok = false;
        }
    }
    return ok;
}


bool examination_2 (std::string str, bool point = true) {
    bool ok = point;
    for (int i = 0; i < str.length() ; ++i) {
        if (str [i] < '0' || str [i] > '9') {
            ok = false;
        }
    }
    return ok;
}


std::string examination_3 (std::string str_1, std::string str_2, std::string str_3, std::string str_4) {
    std::string answer;
    if (str_1 == str_2 && str_3 == str_4) {
        answer = "Equal";
    }else {
        answer = str_1 > str_2 || (str_1 == str_2 && str_3 > str_4) || (str_1.length() > str_2.length() && str_1 [0] != '-') ? "More" : "Less";
    }
    return answer;
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

    std::string str_1;
    std::string str_2;
    std::string answer;
    bool p_1 = true;
    bool p_2 = true;
    bool p_3 = true;
    bool p_4 = true;
    std::string whole_1;
    std::string whole_2;
    std::string fractional_1;
    std::string fractional_2;


        std::cout << "Please enter the first number:\n";
        std::getline(std::cin, str_1);
        std::cout << "Please enter the second number:\n";
        std::getline(std::cin, str_2);

        whole_1 = part_1(str_1, '.');
        fractional_1 = part_2(str_1, '.');
        whole_2 = part_1(str_2, '.');
        fractional_2 = part_2(str_2, '.');

        p_1 = examination_1(whole_1,point(whole_1, '.'));
        p_2 = examination_2(fractional_1, point(fractional_1, '.'));
        p_3 = examination_1(whole_2, point(whole_2, '.'));
        p_4 = examination_2(fractional_2, point(fractional_2, '.'));


    if (!p_1 || !p_2 || !p_3 || !p_4 || str_1 == "." || str_2 == "." || str_1 == "-." || str_2 == "-.") {
        std::cout << "Incorrect writing of a real number!\n";
    }else {
        answer = examination_3(whole_1, whole_2, fractional_1, fractional_2);
        std::cout << answer << std::endl;
    }
}
