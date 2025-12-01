#include <bits/stdc++.h>
using namespace std;
class print
{
	public:
		void operator()(int a)
		{
			cout<<a<<" ";
		}
};
void test()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(20);
	v.push_back(20);
	v.push_back(20);
	
	
	for_each(v.begin(),v.end(),print());
	cout<<endl;
	
	replace(v.begin(),v.end(),20,200);
	for_each(v.begin(),v.end(),print());
}
int main()
{
	test();
}
