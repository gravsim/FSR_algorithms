#include <iostream>
#define COEFFICIENT 200

enum school_type {
    None,
    Faculty_of_Space_Research,
    Faculty_of_Mechanics_and_Mathematics,
    Faculty_of_Computational_Mathematics_and_Cybernetics,
    Faculty_of_Physics,
    Faculty_of_Chemistry,
    Faculty_of_Biology,
    Faculty_of_Geology
};


enum day {
    none,
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
};


school_type get_school_enum(int school_index) {
    school_type result;
    switch (school_index) {
        case 0:
            result = None;
            break;
        case 1:
            result = Faculty_of_Space_Research;
            break;
        case 2:
            result = Faculty_of_Mechanics_and_Mathematics;
            break;
        case 3:
            result = Faculty_of_Computational_Mathematics_and_Cybernetics;
            break;
        case 4:
            result = Faculty_of_Physics;
            break;
        case 5:
            result = Faculty_of_Chemistry;
            break;
        case 6:
            result = Faculty_of_Biology;
            break;
        case 7:
            result = Faculty_of_Geology;
            break;
        default:
            result = None;
            break;
    }
    return result;
}


day get_day(int day_index) {
    day result;
    switch (day_index) {
        case 0:
            result = none;
            break;
        case 1:
            result = sunday;
            break;
        case 2:
            result = monday;
            break;
        case 3:
            result = tuesday;
            break;
        case 4:
            result = wednesday;
            break;
        case 5:
            result = thursday;
            break;
        case 6:
            result = friday;
            break;
        case 7:
            result = saturday;
            break;
        default:
            result = none;
            break;
    }
    return result;
}


class MSU_student
{
private:
    static unsigned int scholarship;
    static day current_day;
    day day_off;
    school_type school;
    double average_grade;
    double income;
public:
    MSU_student();
    MSU_student(
        school_type school,
        double average_grade,
        day day_off,
        double income
    );
    void set_school(int school_index);
    school_type get_school() const;

    double get_average_grade() const;
    void study();

    void set_income(double new_income);
    double get_income();

    void set_day_off(int new_day_off);
    day get_day_off();

    double get_profit();

    static void rise_scholarship(unsigned int addition);
    static double get_scholarship();

    static void set_current_day(int current_day);
    static day get_current_day();



};


unsigned int MSU_student::scholarship = 0;
day MSU_student::current_day = none;


MSU_student::MSU_student() {
    this->school = None;
    this->average_grade = 0;
    this->day_off = none;
    this->income = 0;
}


MSU_student::MSU_student(school_type school,
    double average_grade,
    day day_off,
    double income
    ) {
    this->school = school;
    this->average_grade = average_grade;
    this->day_off = day_off;
    this->income = income;
}


school_type MSU_student::get_school() const {
    return school;
}


double MSU_student::get_average_grade() const {
    return average_grade;
}


void MSU_student::rise_scholarship(unsigned int addition) {
    scholarship += addition;
}


double MSU_student::get_scholarship() {
    return scholarship;
}


void MSU_student::set_current_day(int new__day_index) {
    current_day = get_day(new__day_index);
}


day MSU_student::get_current_day() {
    return current_day;
}


void MSU_student::set_school(int school_index) {
    this->school = get_school_enum(school_index);
}


void MSU_student::study() {
    if (average_grade < 4.9 && day_off != current_day) {
        average_grade += 0.1;
    }
}


void MSU_student::set_income(double new_income) {
    this->income = new_income;
}


double MSU_student::get_income() {
    return this->income;
}


void MSU_student::set_day_off(int new_day_off) {
    this->day_off = get_day(new_day_off);
}


day MSU_student::get_day_off() {
    return this->day_off;
}


double MSU_student::get_profit() {
    return scholarship + income - COEFFICIENT * school;
}


int main() {
    int command;
     unsigned int scholarship_addition;
    int current_day_index;
    int school_index;
    double average_grade;
    int student_index;
    int students_amount;
    int day_off_index;
    double income;
    std::cout << "Enter students amount: ";
    std::cin >> students_amount;
    MSU_student** students = new MSU_student*[students_amount];
    for (int i = 0; i < students_amount; i++) {
        students[i] = nullptr;
    }
    do {
        std::cout << "\nEnter command: ";
        std::cin >> command;
        switch (command) {
            case 1:
                for (int i = 0; i < students_amount; i++) {
                    std::cout << "Student #" << i;
                    if (students[i] == nullptr) {
                        std::cout << " None \n";
                    } else {
                        std::cout << " \n -School: " << students[i]->get_school() << "\n";
                        std::cout << " -Average_grade: " << students[i]->get_average_grade() << "\n";
                        std::cout << " -Day off: " << students[i]->get_day_off() << "\n";
                        std::cout << " -Income: " << students[i]->get_income() << "\n";
                        std::cout << " -Profit: " << students[i]->get_profit() << "\n";
                    }
                }
                std::cout << "Scholarship: " << MSU_student::get_scholarship() << " rubles. \n";
                std::cout << "Day of week: " << MSU_student::get_current_day() << "\n";
                break;
            case 2:
                std::cout << "Enter student index: ";
                std::cin >> student_index;
                if (students[student_index] != nullptr) {
                    std::cout << "Error: student already exists. \n";
                } else {
                    std::cout << "Enter school index: ";
                    std::cin >> school_index;

                    std::cout << "Enter average grade: ";
                    std::cin >> average_grade;

                    std::cout << "Enter day off: ";
                    std::cin >> day_off_index;

                    std::cout << "Enter income: ";
                    std::cin >> income;

                    students[student_index] = new MSU_student(
                        get_school_enum(school_index),
                        average_grade,
                        get_day(day_off_index),
                        income
                        );
                    std::cout << "Student added. \n";
                }
                break;
            case 3:
                std::cout << "Enter scholarship addition: ";
                std::cin >> scholarship_addition;
                MSU_student::rise_scholarship(scholarship_addition);
                std::cout << "Scholarship raised. \n";
                break;
            case 4:
                std::cout << "Enter current day index: ";
                std::cin >> current_day_index;
                MSU_student::set_current_day(current_day_index);
                std::cout << "Current day changed. \n";
                break;
            case 5:
                std::cout << "Enter student index: ";
                std::cin >> student_index;
                if (students[student_index] == nullptr) {
                    std::cout << "Error: student doesn't exist. \n";
                } else {
                    std::cout << "Enter school index: ";
                    std::cin >> school_index;
                    students[student_index]->set_school(school_index);
                    std::cout << "School changed. \n";
                }
                break;
            case 6:
                std::cout << "Enter student index: ";
                std::cin >> student_index;
                if (students[student_index] == nullptr) {
                    std::cout << "Error: student doesn't exist. \n";
                } else {
                    std::cout << "Enter day off index: ";
                    std::cin >> day_off_index;
                    students[student_index]->set_day_off(day_off_index);
                    std::cout << "Day off changed. \n";
                }
                break;
            case 7:
                std::cout << "Enter student index: ";
                std::cin >> student_index;
                if (students[student_index] == nullptr) {
                    std::cout << "Error: student doesn't exist. \n";
                } else {
                    std::cout << "Enter income: ";
                    std::cin >> income;
                    students[student_index]->set_income(income);
                    std::cout << "Income changed. \n";
                }
                break;
            case 8:
                std::cout << "Enter student index: ";
                std::cin >> student_index;
                if (students[student_index] == nullptr) {
                    std::cout << "Error: student doesn't exist. \n";
                } else {
                    students[student_index]->study();
                    std::cout << "Student studied. \n";
                }
                break;
            default:
                break;
        }
    } while (command != 0);
    for (int i = 0; i < students_amount; i++) {
        delete students[i];
    }
    delete[] students;
    return 0;
}
