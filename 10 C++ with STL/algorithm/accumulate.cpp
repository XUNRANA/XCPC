#include <bits/stdc++.h>
using namespace std;
void print(int a)
{
	cout<<a<<" ";
}
void test()
{
	vector<int>v;
	for(int i=1;i<=100;i++) v.push_back(i);
	
	int total=accumulate(v.begin(),v.end(),0);
	//#include <numeric> м╥нд╪Ч
	cout<<total; 
}
int main()
{
	test();
}
