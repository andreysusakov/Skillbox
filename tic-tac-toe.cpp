#include <iostream>

std::string win (std::string str) {
    int sum_x = 0;
    int sum_o = 0;
    std::string answer;
    for (int i = 0; i < 3; i++ ){
        char field = str [i];
        if (field == 'X') {
            sum_x ++;
        }else if (field == 'O') {
            sum_o ++;
        }else {
            answer = 'N';
        }
    }
    if (sum_x == 3) {
        answer = 'X';
    }else if (sum_o == 3) {
        answer = 'O';
    }
    return answer;
}


std::string field_c (std::string str_1, std::string str_2, std::string str_3, int i) {
    std::string field;

    std::string field_c;
    for (int j = 0; j < 3; j++) {
        if (j == 0) {
            field = str_1[i];
        }
        if (j == 1) {
            field = str_2[i];
        }
        if (j == 2) {
            field = str_3[i];
        }
        field_c += field;
    }

    return field_c;
}


std::string diagonal_1 (std::string str_1, std::string str_2, std::string str_3) {
    std::string field;
    std::string field_d;
    for (int j = 0; j < 3; j++) {
        if (j == 0) {
            field = str_1[j];
        }
        if (j == 1) {
            field = str_2[j];
        }
        if (j == 2) {
            field = str_3[j];
        }
        field_d += field;
    }

    return field_d;
}

std::string diagonal_2 (std::string str_1, std::string str_2, std::string str_3) {
    std::string field;
    std::string field_d;
    for (int j = 0; j < 3; j++) {
        if (j == 0) {
            field = str_1[2 - j];
        }
        if (j == 1) {
            field = str_2[2 - j];
        }
        if (j == 2) {
            field = str_3[2 - j];
        }
        field_d += field;
    }

    return field_d;
}

int sum (std::string str_1, std::string str_2, std::string str_3, char simbol) {
    int sum = 0;
    int sum_1 = 0;
    int sum_2 = 0;
    int sum_3 = 0;

    for (int i = 0; i < 3; ++i) {
        if (str_1 [i] == simbol) {
            sum_1++;
        }
        if (str_2 [i] == simbol) {
            sum_2++;
        }
        if (str_3 [i] == simbol) {
            sum_3++;
        }
    }
    return sum = (sum_1 + sum_2 + sum_3);
}


std::string winer (int sum_x, int sum_o, std::string win_1, std::string win_2, std::string win_3, std::string win_4,
                   std::string win_5, std::string win_6, std::string win_7, std::string win_8, bool ok = true) {
    std::string str;
    str = win_1 + win_2 + win_3 + win_4 + win_5 + win_6 + win_7 + win_8;
    int number_1 = 0;
    int number_2 = 0;
    int number_3 = 0;
    std::string winer;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'X') {
            number_1++;
        } else if (str[i] == 'O') {
            number_2++;
        }else if (str [i] == 'I') {
            number_3++;
        }
    }
    if (!ok || number_3 >= 1 || number_1 > 1 || number_2 > 1 || sum_o > sum_x || (number_1 == 1 && number_2 == 1) ||
              (number_1 == 1 && sum_o >= sum_x) || (number_2 == 1 && sum_x > sum_o)) {
        winer = "Incorrect!\n";
    } else if (number_1 == 1) {
        winer = "Petya won!\n";
    } else if (number_2 == 1) {
        winer = "Vasy won!\n";
    } else {
        winer = "Nobody.\n";
    }
    return winer;
}



bool correctness (std::string str_1, std::string str_2, std::string str_3) {
    bool ok = true;
    for (int i = 0; i < str_1.length(); ++i) {
        if (str_1 [i] != 'X' && str_1 [i] != 'O' && str_1 [i] != '.') {
            ok = false;
            break;
        }
    }
        for (int i = 0; i < str_2.length(); ++i) {
            if (str_2[i] != 'X' && str_2[i] != 'O' && str_2[i] != '.') {
                ok = false;
                break;
            }
        }
            for (int i = 0; i < str_3.length(); ++i) {
                if (str_3[i] != 'X' && str_3[i] != 'O' && str_3[i] != '.') {
                    ok = false;
                    break;
                }
            }

    return ok;
}


int main() {

    bool ok;
    std::string line_1, line_2, line_3;
    std::string answer;

    std::cout << "Enter the first line\n";
    std::cin >> line_1;
    std::cout << "Enter the second line\n";
    std::cin >> line_2;
    std::cout << "Enter the third line\n";
    std::cin >> line_3;

    int sum_x = sum(line_1, line_2, line_3, 'X');
    int sum_o = sum(line_1, line_2, line_3, 'O');
    ok = correctness(line_1, line_2, line_3);


    answer = winer(sum_x, sum_o, win (line_1), win (line_2),win (line_3),
                   win (field_c(line_1, line_2, line_3, 0)),
                   win (field_c(line_1, line_2, line_3, 1)),
                   win (field_c(line_1, line_2, line_3, 2)),
                   win (diagonal_1(line_1, line_2, line_3)),
                   win (diagonal_2(line_1, line_2, line_3)), ok);

    std::cout << answer << std::endl;
    return 0;
}

