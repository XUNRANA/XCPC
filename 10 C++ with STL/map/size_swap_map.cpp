#include <iostream>
#include <map>
using namespace std;

void print(map<int,int>&m)
{
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	cout<<"Key = "<<it->first<<" Value = "<<it->second<<endl;
}
void test()
{
	map<int,int>m;
	if(m.empty()) cout<<"Empty\n";
	else cout<<"size: "<<m.size()<<endl;
 	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(3,30));
	m.insert(pair<int,int>(4,40));
	if(m.empty()) cout<<"Empty\n";
	else cout<<"size: "<<m.size()<<endl;
	
	map<int,int>m1;
	m1.insert(pair<int,int>(5,100));
	m1.insert(pair<int,int>(6,200));
	m1.insert(pair<int,int>(7,300));
	m1.insert(pair<int,int>(8,400));
	cout<<"Before swap:\n";
	print(m);
	print(m1);
	
	cout<<"After swap:\n";
	m.swap(m1);  //mºÍm1»¥»» 
	print(m);
	print(m1);
} 

int main()
{
	test();
}
