#include <iostream>
#include "lib.cpp"


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
