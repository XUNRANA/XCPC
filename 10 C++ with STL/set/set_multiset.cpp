#include <iostream>
#include <set>
using namespace std;

void print(set<int>&s)
{
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void printm(multiset<int>&ms)
{
	for(multiset<int>::iterator it=ms.begin();it!=ms.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
//set.insert插入数据会返回是否成功（不允许插入重复数据） 
void test()
{
	set<int>s;
	pair<set<int>::iterator,bool> ret;
	ret=s.insert(10);
	if(ret.second) cout<<"first succeed!\n";
	else cout<<"first fail!\n";
	ret=s.insert(10);
	if(ret.second) cout<<"second succeed!\n";
	else cout<<"second fail!\n";
	print(s);
	
	
	multiset<int>ms;

    ms.insert(30);
	ms.insert(10);
	ms.insert(20);
	ms.insert(30);
	ms.insert(10);
	ms.insert(10);
	printm(ms);
	cout<<"size: "<<ms.size()<<endl;
} 
int main()
{
	test();
}
