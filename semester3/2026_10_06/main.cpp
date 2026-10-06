#include <iostream>
#include <lib.hpp>

#define SUCCESS 0
#define ERROR (-1)






school_type get_school(int school_index) {
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


day_of_the_week_type get_day_of_the_week(int day_of_the_week_index) {
    day_of_the_week_type result;
    switch (day_of_the_week_index) {
        case 0:
            result = day_off;
            break;
        case 1:
            result = school_day;
            break;
        case 2:
            result = holiday;
            break;
        default:
            result = holiday;
            break;
    }
    return result;
}


class MSU_student
{
private:
    static unsigned int scholarship;
    static day_of_the_week_type current_day;
    school_type school;
    float average_grade;
public:
    MSU_student();
    MSU_student(school_type school, float average_grade);
    const school_type get_student_school();
    const float get_average_grade();

    static void rise_scholarship( unsigned int addition);
    static void set_current_day(int current_day);
    static float get_scholarship();
    static day_of_the_week_type get_current_day();

    void change_school(int school_index);
    void update_grades(float new_grades);
};


 unsigned int MSU_student::scholarship = 0;
day_of_the_week_type MSU_student::current_day = day_off;


MSU_student::MSU_student() {
    this->school = None;
    this->average_grade = 0;
}


MSU_student::MSU_student(school_type school, float average_grade) {
    this->school = school;
    this->average_grade = average_grade;
}


const school_type MSU_student::get_student_school() {
    return school;
}


const float MSU_student::get_average_grade() {
    return average_grade;
}


void MSU_student::rise_scholarship(unsigned int addition) {
    scholarship += addition;
}


float MSU_student::get_scholarship() {
    return scholarship;
}


void MSU_student::set_current_day(int new_current_day_index) {
    current_day = get_day_of_the_week(new_current_day_index);
}


day_of_the_week_type MSU_student::get_current_day() {
    return current_day;
}


void MSU_student::change_school(int school_index) {
    this->school = get_school(school_index);
}


void MSU_student::update_grades(float new_grade) {
    this->average_grade = new_grade;
}


int main() {
    int command;
     unsigned int scholarship_addition;
    int current_day_index;
    int school_index;
    float average_grade;
    int student_index;
    int students_amount;
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
                        std::cout << " School: " << students[i]->get_student_school();
                        std::cout << " Average_grade: " << students[i]->get_average_grade() << "\n";
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
                    students[student_index] = new MSU_student(get_school(school_index), average_grade);
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
                    students[student_index]->change_school(school_index);
                    std::cout << "School changed. \n";
                }
                break;
            case 6:
                std::cout << "Enter student index: ";
                std::cin >> student_index;
                if (students[student_index] == nullptr) {
                    std::cout << "Error: student doesn't exist. \n";
                } else {
                    std::cout << "Enter average grade: ";
                    std::cin >> average_grade;
                    students[student_index]->update_grades(average_grade);
                    std::cout << "Grades updated. \n";
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
