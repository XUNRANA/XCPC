#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Transform
{
	public:
		int operator()(int v)
		{
			return -v;
		}
};
void print(int val)
{
	cout<<val<<" ";
}
void test()
{
	vector<int>v;
	for(int i=0;i<10;i++) v.push_back(i+1);
	for_each(v.begin(),v.end(),print);
	cout<<endl;
	
	vector<int>vTarget;
	vTarget.resize(10);   //必须要resize 不然就是硬塞 塞不进去 
	transform(v.begin(),v.end(),vTarget.begin(),Transform());
	for_each(vTarget.begin(),vTarget.end(),print);
	
}
int main()
{
	test();
} 
