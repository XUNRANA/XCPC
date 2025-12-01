#include <bits/stdc++.h>
using namespace std;

class Greater20
{
	public:
		bool operator()(int val)
		{
			return val>5;
		}
};
void test1()
{
	vector<int>v;
	for(int i=0;i<10;i++) v.push_back(i+1);
	int cnt=count_if(v.begin(),v.end(),Greater20());
	cout<<cnt;
}

class Person
{
	public:
		Person(string name,int age)
		{
			this->m_Name=name;
			this->m_Age=age;
		}
		string m_Name;
		int m_Age;
};

class AgeGreater20
{
	public:
		bool operator()(const Person &p)
		{
			return p.m_Age>20;
		}
};
void test2()
{
	vector<Person>v;
	Person p1("¡ı±∏",35);
	Person p2("πÿ”",35);
	Person p3("’≈∑…",20);
	Person p4("≤‹≤Ÿ",40);
	Person p5("’‘‘∆",20);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	int cnt=count_if(v.begin(),v.end(),AgeGreater20());
	cout<<cnt;
}
int main()
{
	//test1();
	test2();
	
}
