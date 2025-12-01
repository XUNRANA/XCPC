#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void print(list<int>&L)
{
	for(list<int>::iterator it=L.begin();it!=L.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void reverse()
{
	list<int>L;
	L.push_back(10);
	L.push_back(200);
	L.push_back(3);
	L.push_back(40);
	L.push_back(5);
	cout<<"反转前\n";
	print(L);
	
	L.reverse();
	cout<<"反转后\n";
	print(L);
	
}
bool myCompare(int v1,int v2)
{
	return v1>v2;
}
void sort1()
{
	list<int>L;
	L.push_back(10);
	L.push_back(200);
	L.push_back(3);
	L.push_back(40);
	L.push_back(5);
	cout<<"排序前\n";
	print(L);
	
	//所有不支持随机访问迭代器的容器，不可以用标准算法 
	//不支持随机访问迭代器的容器，内部会提供对应算法 
	L.sort();   //成员函数 从小到大 不可用sort(L.begin(),L.end()); 
	cout<<"排序后\n";
	print(L);
	
	L.sort(myCompare);
	print(L);
}
int main()
{
	reverse();
	sort1();
}
