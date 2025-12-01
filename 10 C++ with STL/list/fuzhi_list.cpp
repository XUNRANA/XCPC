#include <iostream>
#include <list>
using namespace std;
void print(list<int>&L)
{
	for(list<int>::iterator it=L.begin();it!=L.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void fuzhi()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	print(L1);
	
	list<int>L2;
	L2=L1;
	print(L2);
	
	list<int>L3;
	L3.assign(L2.begin(),L2.end());
	print(L3);
	
	list<int>L4;
	L4.assign(10,1000);
	print(L4);
}
void jiaohuan()
{
	cout<<"交换前:"<<endl; 
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	cout<<"L1: ";
	print(L1);
	
	list<int>L2;
	L2.push_back(40);
	L2.push_back(30);
	L2.push_back(20);
	L2.push_back(10);
	cout<<"L2: ";
	print(L2);
	
	cout<<"交换后:"<<endl; 
	L1.swap(L2);
	cout<<"L1: ";
	print(L1);
	cout<<"L2: ";
	print(L2); 
}
int main()
{
	//fuzhi();
	jiaohuan();
} 
