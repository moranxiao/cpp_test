#pragma once
#include <iostream>
#include <cstring>

class Student{
public:
    Student(int reg = -1,const char* name = "",int math = -1,int eng = -1,int cs = -1)
    :_reg(reg)
    {
        strncpy(_name,name,9);
        _name[9] = '\0';
    }
    int sum()
    {
        return _math + _eng + _cs;
    }
    void printf()
    {
        std::cout << "Name:" << _name << "  "\
        << "Reg:" << _reg << "  " \
        << "Math Grade:" << _math << "  "\
        << "English Grade:" << _eng << "  "\
        << "Computer Grade:" << _cs << "  " << std::endl;
    }
    int get_reg_num()
    {
        return _reg;
    }
    void set_stu_inf(int reg,const char* name,int math,int eng,int cs)
    {
        _reg = reg;
        strncpy(_name,name,10);
        _math = math;
        _eng = eng;
        _cs = cs;
    }
    bool operator==(int reg)
    {
        return _reg == reg;
    }
private:
    int _reg;
    char _name[10];
    int _math;
    int _eng;
    int _cs;
};