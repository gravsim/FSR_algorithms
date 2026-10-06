#include <iostream>


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


enum day_of_the_week_type {
    day_off,
    school_day,
    holiday
};


school_type get_school(int school_index);
day_of_the_week_type get_day_of_the_week(int day_of_the_week_index);


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

