#ifndef CALENDAR_H
#define CALENDAR_H


class calendar {
public:
    calendar();
    void cal();
    int cur_start_date(int day, int month, int year);
    int number_of_days(int month, int year);
    std::string month_name(int month);
};

#endif // CALENDAR_H
