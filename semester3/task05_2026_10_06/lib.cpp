#include "lib.hpp"


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
