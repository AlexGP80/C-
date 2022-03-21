#include<string>

class Student{
public:
	Student(std::string);
	virtual void display();
private:
	std::string name;
};
