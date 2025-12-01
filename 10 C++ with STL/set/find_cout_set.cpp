#include <iostream>
#include <set>
using namespace std;

void print(set<int>&s)
{
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void find()
{
	set<int>s;
	for(int i=100;i>=0;i-=10) s.insert(i+1);
	print(s);
	set<int>::iterator pos=s.find(31); //返回迭代器 
	if(pos!=s.end()) cout<<"找到元素： "<<*pos<<endl;
	else cout<<"not find!!\n";
}
void count()
{
	set<int>s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(30);
	s.insert(30);
	s.insert(30);//集合没有重复 
	s.insert(40);
	print(s);
	
	int num=s.count(30);//set的count=0or1 
	cout<<"num = "<<num<<endl;
}
int main()
{
	find();
	count();
}
