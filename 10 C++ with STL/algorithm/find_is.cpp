#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GreateFive
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
	vector<int>::iterator it=find_if(v.begin(),v.end(),GreateFive());
    if(it==v.end()) cout<<"Not find";
    else cout<<"Find!"<<endl<<*it<<endl;
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
class Greate20
{
	public:
		bool operator()(Person &p)
		{
			return p.m_Age>20;
		}
};
void test2()
{
	vector<Person>v;
	
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	
	vector<Person>::iterator it=find_if(v.begin(),v.end(),Greate20());
    if(it==v.end()) cout<<"Not find";
    else cout<<"Find!\n"
	<<"Name:"<<it->m_Name<<endl
	<<"Age:"<<it->m_Age<<endl;
}
int main()
{
	test1();
	cout<<endl;
	test2();	
}
