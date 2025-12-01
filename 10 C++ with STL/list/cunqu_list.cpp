#include <iostream>
#include <list>
using namespace std;
void print(list<int>&L)
{
	for(list<int>::iterator it=L.begin();it!=L.end();it++) //不能写it+=1 
	cout<<*it<<" ";
	cout<<endl;
}
void cunqu()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	print(L);
	//不能用[] at.() 随机访问 
	cout<<"first: "<<L.front()<<endl;
	cout<<"last: "<<L.back()<<endl;
}
int main()
{
	cunqu();
} 
