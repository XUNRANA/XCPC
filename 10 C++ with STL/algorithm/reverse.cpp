#include <bits/stdc++.h>
using namespace std;

void print(int a)
{
	cout<<a<<" ";
}
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	v.push_back(10);
	
	for_each(v.begin(),v.end(),print);
	reverse(v.begin(),v.end());
	cout<<endl;
	for_each(v.begin(),v.end(),print);
}
int main()
{
	test();
}
