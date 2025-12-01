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
/*
bool Greater104(int a)
{
	return a>104;
}*/     
//µÈ¼ÛµÄ 
class Greater104
{
	public:
		bool operator()(int a)
		{
			return a>104;
		}
};
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(60);
	v.push_back(190);
	v.push_back(110);
	v.push_back(100);
	v.push_back(104);
	v.push_back(160);
	v.push_back(105);
	
	for_each(v.begin(),v.end(),print());
	cout<<endl;
	
	replace_if(v.begin(),v.end(),Greater104(),500);
	for_each(v.begin(),v.end(),print());
	cout<<endl;
}
int main()
{
	test();
}
