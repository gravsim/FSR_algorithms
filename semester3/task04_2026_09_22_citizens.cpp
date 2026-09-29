#include <iostream>

#define SUCCESS 0
#define ERROR (-1)
#define QUEUE_FULL 1



enum school {
    None,
    Faculty_of_Space_Research,
    Faculty_of_Mechanics_and_Mathematics,
    Faculty_of_Computational_Mathematics_and_Cybernetics,
    Faculty_of_Physics,
    Faculty_of_Chemistry,
    Faculty_of_Biology,
    Faculty_of_Geology
};


enum day_of_the_week {
    day_off,
    school_day,
    holyday
};


class MSU_student
{
private:
    static float scholarship;
    static day_of_the_week current_day;
    school school;
    float average_grade;
public:
    MSU_student();
    MSU_student(enum school school, float average_grade);
    static void rise_scholarship(float addition);
    static void set_day_of_week(enum day_of_the_week current_day);
};

float MSU_student::scholarship;


MSU_student::MSU_student() {
    this->school = None;
    this->average_grade = 0;
}


MSU_student::MSU_student(enum school school, float average_grade) {
    this->school = school;
    this->average_grade = average_grade;
}

void MSU_student::rise_scholarship(float addition) {
    scholarship += addition;
}

void MSU_student::set_day_of_week(day_of_the_week new_current_day) {
    current_day = new_current_day;
}


int main() {
    int command;
    int value;
    int max_size;
    std::cout << "Enter maximum size of queue (0 for unlimited): ";
    std::cin >> max_size;
    MSU_student students[10];

    do {
        std::cin >> command;
        switch (command) {
            case 1:
                std::cin >> value;
                queue.push(value);
                break;
            case 2:
                if (queue.is_empty()) {
                    std::cout << "Queue is empty" << "\n";
                } else {
                    queue.top(value);
                    std::cout << "Top value: "  << value << "\n";
                }
                break;
            case 3:
                if (queue.is_empty()) {
                    std::cout << "Queue is empty" << "\n";
                } else {
                    queue.top(value, true);
                    std::cout << "Popped value: " << value << "\n";
                }
                break;
            case 4:
                if (queue.is_empty()) {
                    std::cout << "Queue is empty" << "\n";
                } else {
                    std::cout << "Queue is not empty" << "\n";
                }
                break;
            case 5:
                std::cout << "Queue size: " << queue.get_size() << "\n";
                break;
            case 6:
                queue.clear();
                std::cout << "Queue cleared." << "\n";
                break;
            case 7:
                queue.clear(true);
                std::cout << "Queue filled with zeros." << "\n";
                break;
            default:
                break;
        }
    } while (command != 0);
    Queue queue_copy(queue);
    std::cout << "Queue copied." << "\n";
    Queue queue_moved(std::move(queue_copy));
    std::cout << "Queue moved." << "\n";
    return 0;
}
