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
	for(int i=0;i<=10;i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
	}
	vector<int>vTarget;
	vTarget.resize(20);   //º«µ√…Í«Îø’º‰ 
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
	for_each(vTarget.begin(),vTarget.end(),print);
	cout<<endl;
}
int main()
{
	test();
}
