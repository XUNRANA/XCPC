#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int>v;
	v.reserve(100000);   //预留空间 之后不会开辟多次 
	int *p=NULL;
	int num=0;
	for(int i=0;i<100000;i++) 
	{
		v.push_back(i+1);
		if(p!=&v[0])
		{
			p=&v[0];
			num++;     //统计开辟的空间次数 
		}
	}
	cout<<"num = "<<num<<endl;
}
