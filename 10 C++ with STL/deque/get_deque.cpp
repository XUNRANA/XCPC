#include <iostream>
#include <deque>
using namespace std;

void get()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);
	d.push_back(50);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	for(int i=0;i<d.size();i++) cout<<d[i]<<" ";
	cout<<endl;
	for(int i=0;i<d.size();i++) cout<<d.at(i)<<" ";
	cout<<endl;
	cout<<"front: "<<d.front()<<endl;
	cout<<"back: "<<d.back()<<endl;
}
int main()
{
	get();
}
