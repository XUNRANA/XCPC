#include <vector>
#include <iostream>
using namespace std;
void print(vector<int>&v)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void create()
{
	vector<int>v;   //默认构造 
	for(int i=0;i<10;i++) v.push_back(i+1);
	print(v);
	vector<int>v1(v.begin(),v.end());
	print(v1);
	vector<int>v2(10,100);   //构造容器10个100 
	print(v2);
}
int main()
{
	create();
}
