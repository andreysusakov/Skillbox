#include <iostream>
#include <cmath>
//9.7 Homework. 1. Travel time

int main() {

    std::string timeDeparture;
    std::string timeArrival;

    std::cout << "Set the departure time of the train in HH:MM format:" << std::endl;
    std::cin >> timeDeparture;
    std::cout << "Set the arrival time of the train in HH:MM format:" << std::endl;
    std::cin >> timeArrival;

    if ((timeDeparture.length() != 5 || timeDeparture[2] != ':' || timeDeparture[0] < '0' || timeDeparture[0] > '9'
         || timeDeparture[1] < '0' || timeDeparture[1] > '9' || timeDeparture[3] < '0' || timeDeparture[3] > '9'
         || timeDeparture[4] < '0' || timeDeparture[4] > '9') || (timeArrival.length() != 5 || timeArrival[2] != ':'
                                                                  || timeArrival[0] < '0' || timeArrival[0] > '9' || timeArrival[1] < '0' || timeArrival[1] > '9'
                                                                  || timeArrival[3] < '0' || timeArrival[3] > '9' || timeArrival[4] < '0' || timeArrival[4] > '9')) {

        std::cout << "Error!" << std::endl;
    } else {
        int hoursDeparture = 10 * (timeDeparture[0] - '0') + (timeDeparture[1] - '0');
        int minutesDeparture = 10 * (timeDeparture[3] -'0') + (timeDeparture[4] - '0');
        int hoursArrival = 10 * (timeArrival[0] - '0') + (timeArrival[1] - '0');
        int minutesArrival = 10 * (timeArrival[3] -'0') + (timeArrival[4] - '0');

        if (hoursDeparture > 23 || minutesDeparture > 59 || hoursArrival > 23 || minutesArrival >59) {
            std::cout << "Error!" << std::endl;
        } else if (hoursDeparture < hoursArrival || (hoursDeparture == hoursArrival
                && minutesDeparture < minutesArrival)) {
            int hours = hoursArrival - hoursDeparture;
            int minutes = minutesArrival - minutesDeparture;
            std::cout << "Travel time: " << hours << ":" << minutes << std::endl;
        } else{
            float (hours);
            int minutes;
            hours = float (hoursArrival) + ((24 - float (hoursDeparture)) - float (minutesDeparture) / 60);
            minutes = minutesArrival + (60 - minutesDeparture);
            if (minutes == 60) {
                hours++;
                minutes = 0;
            }
            std::cout << "Travel time: " << floor (hours) << " hours, " << minutes << " minutes" << std::endl;
        }
    }
    return 0;
}
