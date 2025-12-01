#include <bits/stdc++.h>
using namespace std;
void print(int a)
{
	cout<<a<<" ";
}
void test()
{
	vector<int>v1;
	for(int i=0;i<10;i++) v1.push_back(i);
	
	vector<int>v2;
	v2.resize(10,5);
	for_each(v2.begin(),v2.end(),print);
	cout<<endl;
	copy(v1.begin(),v1.end(),v2.begin());
    for_each(v2.begin(),v2.end(),print);
}
int main()
{
	test();
}
