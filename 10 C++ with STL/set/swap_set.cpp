#include <iostream>
#include <set>
using namespace std;
void print(set<int>&s)
{
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void test()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	print(s1);
	if(s1.empty()) cout<<"empty\n";
	else 
	{
		cout<<"not empty\n";
		cout<<"size: "<<s1.size()<<endl;
	}
	
	set<int>s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);
	
	cout<<"Before swap:\n";
	print(s1);
	print(s2);
	
	cout<<"After swap:\n";
	s1.swap(s2);
	print(s1);
	print(s2);
}
int main()
{
	test();
}
