#include <iostream>
#include <list>
using namespace std;

class Person
{
public:
	Person(string name,int age,int height)
	{
		this->m_Name=name;
		this->m_Height=height;
		this->m_Age=age;
	}
	string m_Name;
	int m_Age;
	int m_Height;	
};
void print(list<Person>&L)
{
	for(list<Person>::iterator it=L.begin();it!=L.end();it++)
	cout<<"Name: "<<(*it).m_Name<<" Age: "<<(*it).m_Age<<" Height "<<(*it).m_Height<<endl;
}
bool cmp(Person &p1,Person &p2)
{
	if(p1.m_Age==p2.m_Age)
	{
		return p1.m_Height>p2.m_Height;
	}
	else return p1.m_Age>p2.m_Age;
}
void test()
{
	list<Person>L;
	Person p1("Áõ±¸",35,175);
	Person p2("²Ü²Ù",45,180);
	Person p3("ËïÈ¨",40,170);
	Person p4("ÕÔÔÆ",25,190);
	Person p5("ÕÅ·É",35,160);
	Person p6("¹ØÓğ",35,200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	cout<<"Before sort: \n";
	print(L);
	
	cout<<"After sort: \n";
	L.sort(cmp);
	print(L);
} 
int main()
{
	test();
} 
