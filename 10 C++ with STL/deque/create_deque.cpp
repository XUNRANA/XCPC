#include <iostream>
#include <deque>
using namespace std;
void print(deque<int>&d)
{                  // 只读叠加器不可修改 
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++) 
	cout<<*it<<" ";
	cout<<endl;
}
void create()
{
	deque<int>d;
	for(int i=0;i<10;i++) d.push_back(i+1);
	print(d);
	
	deque<int>d1(d.begin(),d.end());
	print(d1);
	
	deque<int>d2(10,100);
	print(d2);
	
	deque<int>d3(d2);
	print(d3);
	
}
int main()
{
	create();
}
