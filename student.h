#pragma once // header guard
#include <iostream>
#include <string>
namespace hongyejin2649058
{
    class student
    {
        std::string name{};
        int id{};
        int score{};
        char grade{};

        void testId()
        {
            if (id < 1000000 || id > 9999999) {
                std::cout << "Illegal score value!" << std::endl;
                std::exit(1);
            }
        }
        void testScore()
        {
            if (score < 0 || score > 100) {
                std::cout << "Illegal score value!" << std::endl;
                std::exit(1);
            }
        }
       void calGrade()
       {
        if (score >= 90) grade = 'A';
        else if (score >= 80) grade = 'B';
        else if (score >= 70) grade = 'C';
        else if (score >= 60) grade = 'D';
        else grade = 'F';
       }
    public:
    //constructor: 모든 멤버변수 초기화, 기본값 설정, test함수들 호출
        student(const std::string& n = "no name yet", int d = 1234567, int s = 0)
            :name{n}, id{d}, score{s}
        {
            testId(); testScore(); calGrade();
        }
        // -input: 매개변수를 std::istream&로, 기본값은 std::cin으로
        // -입력연산자>>: input함수를 이용
        // student s; s.input(std::cin);
        void input(std::istream& is = std::cin)
        {//std::cin --> is
            std::cout << "Enter name: ";
            std::getline(is >> std::ws, name);
            std::cout << "Enter id: ";
            is >> id; 
            testId();
            std::cout << "Enter score: ";
            is >> score; 
            testScore();
            calGrade();
        }
         //-프렌드함수로서 입력연산자 >>, 출력연산자 <<, 이항연산자 ==, 이항연산자 + 정의
        friend std::istream& operator>>(std::istream& is, student& s)
        {
            s.input(is);
            return is;
        }

        friend std::ostream& operator<<(std::ostream& os, const student& s)
        {//print(): std::cout --> os
            s.print(os);
            return os;
        }

        void setName(const std::string& n) {name = n;}
        void setId(int d) {id = d; testId();}
        void setScore(int s) {score = s; testScore();}
        void setGrade(char g) {grade = g;}
        //const 멤버함수
        void print(std::ostream& os = std::cout) const 
        {
            os << name << " (" << id << "): ";
            os.width(3); os.fill('0');
            os << score << " (" << grade << ")\n";
        }
        
        const std::string& getName() const {return name;}
        int getId() const {return id;}
        int getScore() const {return score;}
        char getGrade() const {return grade;}
        student& operator+=(int s)
        {
            score += s;
            if (score > 100)
                score = 100;
            calGrade();
            return *this;
        }
    //-멤버함수로 전위증가연산자, 후위증가연산자 정의
        student& operator++()
        {
            ++score; calGrade(); 
            return *this;;
        }

        student operator++(int)
        {
            student temp{*this};
            ++(*this);
            return temp; 

        }

        friend bool operator==(const student& s1, const student& s2)
        {
            return s1.id == s2.id;
        }
        friend int operator+(const student& s1, const student& s2)
        {
            return s1.score + s2.score;
        }
    };
}



