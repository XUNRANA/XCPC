#include <bits/stdc++.h>
using namespace std;
void print(int a)
{
	cout<<a<<" ";
}
void test()
{
	vector<int>v;
	v.resize(10);
	for_each(v.begin(),v.end(),print);
	cout<<endl;
	
	fill(v.begin(),v.end(),100); //ºóÆÚÌî³ä 
	
	for_each(v.begin(),v.end(),print);
}
int main()
{
	test();
}
