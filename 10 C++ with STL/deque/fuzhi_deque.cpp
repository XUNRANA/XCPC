#include <iostream>
#include <deque>
using namespace std;
void print(const deque<int>&d)
{
	for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void fuzhi()
{
	deque<int>d;
	for(int i=0;i<10;i++) d.push_back(i+1);
	print(d);
	 
	deque<int>d1;
	d1=d;
	print(d1);
	
	deque<int>d2;
	d2.assign(d.begin(),d.end());
	print(d2);
	
	deque<int>d3;
	d3.assign(10,100);
	print(d3);
}
int main()
{
	fuzhi();
} 
