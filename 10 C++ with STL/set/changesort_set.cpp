#include <iostream>
#include <set>
using namespace std;

void print(set<int>&s)
{
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}

class cmp   //仿函数 
{
	public:
		bool operator()(int v1,int v2)//指定数据类型int 
		{
			return v1>v2;
		}
};
void test()
{
	set<int>s;       //默认规则从小到大插入 
	s.insert(1);
	s.insert(10);
	s.insert(6);
	s.insert(156);
	s.insert(64);
	print(s);
	
	set<int,cmp>s1;  //指定规则从大到小插入 
	s1.insert(1);
	s1.insert(10);
	s1.insert(10);
	s1.insert(6);
	s1.insert(156);
	s1.insert(64);
	for(set<int,cmp>::iterator it=s1.begin();it!=s1.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
 
int main()
{
	test();
}
