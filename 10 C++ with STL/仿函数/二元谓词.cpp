#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
//返回bool的仿函数称为谓词
//operator()接受二个参数，叫二元谓词

void print(vector<int>&v)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
class cmp
{
	public:
		bool operator()(int a,int b)  //二元体现两个参数 
		{
			return a>b;
		}
};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	sort(v.begin(),v.end());
	print(v);
	
	sort(v.begin(),v.end(),cmp());  //不能写cmp 
	print(v);
}
int main()
{
	test01();
}
