#include <iostream>
#include <algorithm>
#include <functional>
#include <vector> 
using namespace std;
class cmp
{
	public:
		bool operator ()(int a,int b)
		{
			return a>b;
		}
};
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);
	
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	cout<<*it<<" ";
	cout<<endl;
	
	//sort(v.begin(),v.end(),cmp());
	sort(v.begin(),v.end(),greater<int>());//greater()内建的函数对象 
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	cout<<*it<<" ";
	cout<<endl;
} 
int main()
{
	test();
}
