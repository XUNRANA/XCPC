#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findneizhi()
{
	vector<int>v;
	for(int i=0;i<10;i++) v.push_back(i+1);
	vector<int>::iterator it=find(v.begin(),v.end(),50);
	if(it==v.end()) cout<<"Not find";
	else cout<<"Find: "<<*it;
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
	//重载== 底层find知道如何对比person数据类型 
	bool operator==(const Person &p)
	{
		if(this->m_Name==p.m_Name&&this->m_Age==p.m_Age) return true;
		else return false;
	}

};
void finddiy()
{
	vector<Person>v;
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	
	Person p5("ddd",41);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	
	vector<Person>::iterator it=find(v.begin(),v.end(),p5); 
	
	if(it==v.end()) cout<<"Not Find ";
	else cout<<"Find!"<<endl<<"Name "<<it->m_Name<<" Age: "<<it->m_Age; 
}
int main()
{
	//findneizhi();
	finddiy();
} 
