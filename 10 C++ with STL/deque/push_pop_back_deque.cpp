#include <iostream>
#include <deque>
using namespace std;
void print(deque<int>&d)
{
	for(deque<int>::iterator it=d.begin();it!=d.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void push_pop()
{
	deque<int>d;
	//尾插 
	d.push_back(10);
	d.push_back(20);
	print(d);
	//头插 
	d.push_front(100);
	d.push_front(200);
	print(d);
	//尾删 
	d.pop_back();
	print(d);
	//头删 
	d.pop_front();
	print(d);
}
void insert()
{
	deque<int>d;
	//尾插 
	d.push_back(10);
	d.push_back(20);
	print(d);
	//头插 
	d.push_front(100);
	d.push_front(200);
	print(d);
	
	d.insert(d.begin(),1000);
	d.insert(d.begin(),2,10000);
	print(d);
	
	//按照区间进行插入
	deque<int>d1;
	d1.push_back(1); 
	d1.push_back(2); 
	d1.push_back(3); 
	d1.push_back(4);
	d.insert(d.begin(),d1.begin(),d1.end());
	print(d);
}
void erase()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	
	deque<int>::iterator it=d.begin();
	it++;
	d.erase(it);
	print(d);
	
	d.erase(d.begin(),d.end());
	print(d);      //全删 等价于d.clear(); 
}
int main()
{
	//push_pop();
	//insert();
	erase();
}
