#include "count.hpp"
#include "time.hpp"
#include "student.hpp"

#include <iostream>

using namespace std;

void test_count()
{
    Count count;
    for(int i = 0; i < 10; i++)
        count++;
    cout << count.get() << endl;
    count--;
    cout << count.get() << endl;
}
void test_time()
{
    Time time;
    time.set(17,18,12);
    cout << "hour:" << time.get_hour() \
    << ",minute:" << time.get_minute() \
    << ",second:" << time.get_second() << endl;
}
void test_student()
{ 
    Student students[10];  
    int n;  
    // 输入学生数量  
    std::cin >> n;  
  
    // 输入并设置每个学生的信息  
    for (int i = 0; i < n; ++i) {  
        int reg;  
        char name[10];  
        int math, eng, cs;  
        std::cout << "Enter information for student " << (i + 1) << ":" << std::endl;  
        std::cout << "Reg number: ";  
        std::cin >> reg;  
        std::cout << "Name: ";  
        std::cin >> name;  
        std::cout << "Math grade: ";  
        std::cin >> math;  
        std::cout << "English grade: ";  
        std::cin >> eng;  
        std::cout << "Computer Science grade: ";  
        std::cin >> cs;  
  
        // 设置学生信息  
        students[i].set_stu_inf(reg, name, math, eng, cs);  
    }  
    // 计算每个学生的总成绩和全班学生总成绩最高分  
    int totalScores[10];  
    int max = 0;  
    for (int i = 0; i < n; ++i) {  
        totalScores[i] = students[i].sum();  
        if (totalScores[i] > max) {  
            max = totalScores[i];  
        }  
    }  
    // 计算全班学生总平均分  
    double totalAverageScore = 0.0;  
    for (int i = 0; i < n; ++i) {  
        totalAverageScore += (double)totalScores[i];  
    }  
    totalAverageScore /= n;  
  
    // 输出每个学生的总成绩和全班学生总成绩最高分、全班学生总平均分  
    std::cout << "Student Information:" << std::endl;  
    std::cout << "Name\tReg\tMath\tEnglish\tCS\tTotal\n";  
    for (int i = 0; i < n; ++i) {  
        students[i].printf();  
        std::cout << "\t" << totalScores[i] << std::endl;  
    }  
    std::cout << "Highest total score: " << max << std::endl;  
    std::cout << "Average total score: " << totalAverageScore << std::endl;  
  
    // 输入一个注册号，输出该学生的全部数据信息  
    int searchReg;  
    std::cout << "Enter registration number to search: ";  
    std::cin >> searchReg;  
    bool found = false;  
    for (int i = 0; i < n; ++i) {  
        if (students[i] == searchReg) {  
            found = true;  
            std::cout << "Information for student with registration number " << searchReg << ":" << std::endl;  
            students[i].printf();  
            std::cout << "Total score: " << totalScores[i] << std::endl;  
            break;  
        }  
    }  
    if (!found) {  
        std::cout << "No student found" << searchReg << std::endl;  
    }  
}
int main()
{
    test_count();
    test_time();
    test_student();
    return 0;
}