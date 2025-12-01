#include <iostream>
#include <deque>
using namespace std;

void print(deque<int>&d)
{
	for(deque<int>::iterator it=d.begin();it!=d.end();it++) 
	cout<<*it<<" ";
	cout<<endl;
}
void size()
{
	deque<int>d;
	for(int i=0;i<10;i++) d.push_back(i+1);
	print(d);
	
	if(d.empty()) cout<<"empty"<<endl;
	else cout<<"size: "<<d.size()<<endl;
	
	d.resize(15,100);
	cout<<"size: "<<d.size()<<endl;
	print(d);
	
	d.resize(5);
	cout<<"size: "<<d.size()<<endl;
	print(d);
}
int main()
{
	size();
}
