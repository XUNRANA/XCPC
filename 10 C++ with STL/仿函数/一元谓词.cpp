#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
//返回bool的仿函数称为谓词
//operator()接受一个参数，叫一元谓词

class GreaterFive
{
	public:
		bool operator()(int val)  //一元体现在一个参数 
		{
			return val>5;
		}
};
void test01()
{
	vector<int>v;
	for(int i=0;i<10;i++) v.push_back(i+1);
	vector<int>::iterator it=find_if(v.begin(),v.end(),GreaterFive());
	if(it!=v.end()) cout<<"Find: "<<*it<<endl;
	else cout<<"Not Find!\n";
}
int main()
{
	test01();
} 
