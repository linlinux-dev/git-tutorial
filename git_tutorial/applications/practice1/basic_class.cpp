#include<iostream>

class student
{
private:
    std::string name;
    int rollno;

public:
    student(std::string a, int b)
    {
        name = a;
        rollno = b;
    }
    void printdetails()
    {
        std::cout << name << std::endl;
        std::cout << rollno << std::endl;
    }
};
int main()
{
    student mydet("jenishlin", 25);
    mydet.printdetails();
    printf("");
    printf("version 3");
}