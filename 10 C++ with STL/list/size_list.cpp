#include <iostream>
#include <list>
using namespace std;
void print(list<int>&L)
{
	for(list<int>::iterator it=L.begin();it!=L.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void size()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	print(L);
	
	if(L.empty()) cout<<"empty";
	else cout<<"size: "<<L.size()<<endl;
	
	L.resize(10);
	print(L);
	
	L.resize(11,10);
	print(L);
	
	L.resize(2);
	print(L);
}
int main()
{
	size();
}
