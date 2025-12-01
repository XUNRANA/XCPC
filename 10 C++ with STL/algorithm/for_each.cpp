#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int val)  //simple function
{
	cout<<val<<" ";
}

class print1         //仿函数 
{
	public:
		void operator()(int val)
		{
			cout<<val<<" ";
		}	
};
void test()
{
	vector<int>v;
	for(int i=0;i<10;i++)
	v.push_back(i+1);
	for_each(v.begin(),v.end(),print); //函数名 
	cout<<endl;
	for_each(v.begin(),v.end(),print1()); //仿函数 要加（） 
}
int main()
{
	test();
}
