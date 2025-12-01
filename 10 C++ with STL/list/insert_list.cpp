#include <iostream>
#include <list>
using namespace std;
void print(list<int>&L)
{
	for(list<int>::iterator it=L.begin();it!=L.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void insert()
{
	list<int>L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_front(5);
	L.push_front(6);
	L.push_front(7);
	print(L);
	
	L.pop_back();
	print(L);
	
	L.pop_front();
	print(L);
	
	list<int>::iterator it=L.begin();
	L.insert(++it,1000);  //插入在++it所指的5之前 
	print(L);
	
	L.erase(it);   //删除it所指5 
	print(L);
	
	L.push_front(999);
	L.push_front(999);
	L.push_back(999);
	L.push_back(999);
	print(L);
	
	L.remove(999); //删除所有999 
	print(L);
	
	L.clear();     //删除所有 
	print(L);
}
int main()
{
	insert();
}
