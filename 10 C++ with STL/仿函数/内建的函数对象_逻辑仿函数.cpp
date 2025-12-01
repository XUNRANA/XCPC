#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
void print(vector<bool>&v)
{
	for(vector<bool>::iterator it=v.begin();it!=v.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void test()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	v.push_back(true);
	print(v);
	
	vector<bool>v2;
	v2.resize(v.size());                 //Âß¼­·Ç 
	transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
	print(v2);
	
}
int main()
{
	test();
}
