#include <iostream>
#include <list>
using namespace std;
void print(list<int>&L)
{
	for(list<int>::iterator it=L.begin();it!=L.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void create()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	print(L);
	
	list<int>L1(L.begin(),L.end());  //区间 
	print(L1);
	
	list<int>L2(10,100);             //10个100 
	print(L2);
	
	list<int>L3(L2);                 //拷贝构造 
	print(L3);
}
int main()
{
	create();
} 
