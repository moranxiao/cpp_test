#pragma once
#include <iostream>

class Time{
public:
    Time(int hour = 0,int minute = 0,int second = 0)
    :_hour(hour),
    _minute(minute),
    _second(second)
    {}
    bool set_hour(int hour)
    {
        if(hour >= 0 && hour < 24)
        {
            _hour = hour;
            return true;
        }
        return false;
    }
    bool set_minute(int minute)
    {
        if(minute >= 0 && minute < 60)
        {
            _minute = minute;
            return true;
        }
        return false;
    }
    bool set_second(int second)
    {
        if(second >= 0 && second < 60)
        {
            _second = second;
            return true;
        }
        return false;
    }
    bool set(int hour,int minute,int second)
    {
        if(set_hour(hour) && set_minute(minute) && set_second(second))
            return true;
        return false;
    }
    int get_hour()
    {
        return _hour;
    }
    int get_minute()
    {
        return _minute;
    }
    int get_second()
    {
        return _second;
    }
private:
    int _hour;
    int _minute;
    int _second;
};