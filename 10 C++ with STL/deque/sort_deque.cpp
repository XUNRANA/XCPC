#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
void print(deque<int>&d)
{
	for(deque<int>::iterator it=d.begin();it!=d.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
int main()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	print(d);                 
	sort(d.begin(),d.end()); 
	//排序 从小到大     (数组 vector)
	//对于支持随机访问的迭代器的容器都可以 
	print(d);
}
