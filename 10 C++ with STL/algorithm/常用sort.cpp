#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)  
{
	return a>b;
}
void print(int a)
{
	cout<<a<<" ";
}
void test()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	
	sort(v.begin(),v.end());
	for_each(v.begin(),v.end(),print);
	cout<<endl;
	
	sort(v.begin(),v.end(),cmp); 
	for_each(v.begin(),v.end(),print);
	cout<<endl;
	// greater<int>()为内置  等价cmp 
	sort(v.begin(),v.end(),greater<int>());
	for_each(v.begin(),v.end(),print);
	cout<<endl;
}
int main()
{
	test();
}
