#include <bits/stdc++.h>
using namespace std;

void print(int a)
{
	cout<<a<<" ";
} 
void test()
{
	vector<int>v1;
	vector<int>v2;
	for(int i=0;i<10;i++) v1.push_back(i);
	for(int i=5;i<15;i++) v2.push_back(i);
	
	vector<int>v3;
	v3.resize(min(v1.size(),v2.size()));
	
	vector<int>::iterator it=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	//º¯Êý·µ»Ø ==v3.end()
	for_each(v3.begin(),it,print);
	
}
int main()
{
	test();
}
