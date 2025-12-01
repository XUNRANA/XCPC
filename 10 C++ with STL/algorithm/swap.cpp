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
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
	}
	
	for_each(v1.begin(),v1.end(),print);
	cout<<endl;
	for_each(v2.begin(),v2.end(),print);
	cout<<endl;
	cout<<endl;
	swap(v1,v2);
	for_each(v1.begin(),v1.end(),print);
	cout<<endl;
	for_each(v2.begin(),v2.end(),print);
	cout<<endl;
}

int main()
{
	test();
	
} 
