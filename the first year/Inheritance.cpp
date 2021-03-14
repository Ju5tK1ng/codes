#include<bits/stdc++.h>
using namespace std;

class Person{
public:
	Person(string s,int i):name(s),age(i){
		cout<<"Person::Person()"<<endl;
	}
	~Person(){
		cout<<"Person::~Person()"<<endl;
	}
	void move(){
		cout<<name<<" is moving!"<<endl;
	}
	void say(){
		cout<<"I'm "<<name<<", my age is "<<age<<"."<<endl;
	}
protected:
	string name;
	int age;
};

class Student:public Person{
public:
	Student(string name,int age,string s):Person(name,age),studentNo(s){
		cout<<"Student::Student()"<<endl;
	}
	~Student(){
		cout<<"Student::~Student()"<<endl;
	}
	void study(){
		cout<<name<<" (studentNo:"<<studentNo<<") is studying!"<<endl;
	}
private:
	string studentNo;
};

class Teacher:public Person{
public:
	Teacher(string name,int age,string s):Person(name,age),teacherNo(s){
		cout<<"Teacher::Teacher()"<<endl;
	}
	~Teacher(){
		cout<<"Teacher::~Teacher()"<<endl;
	}
	void teach(){
		cout<<name<<" (teacherNo:"<<teacherNo<<") is teaching!"<<endl;
	}
private:
	string teacherNo;	
};

int main(){
	Person LiHua("LiHua",18);
	Student XiaoMing("XiaoMing",8,"S007");
	Teacher MissLi("MissLi",28,"T008");
	LiHua.say();
	LiHua.move();
	XiaoMing.say();
	XiaoMing.study();
	MissLi.say();
	MissLi.teach();
	return 0;
}
