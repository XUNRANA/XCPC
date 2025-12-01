#include <iostream>
#include <vector>
#include <string> 
#include <ctime>
#include <algorithm>
#include <map>
#define PLAN 0
#define ART 1
#define INOVATION 2
using namespace std;
class Worker
{
	public:
		string m_Name;
		int m_Salary;
};

void createWorker(vector<Worker>&v)
{
	string nameSeed="ABCDEFGHIJ";
	for(int i=0;i<10;i++)
	{
		Worker worker;
		worker.m_Name="Ô±¹¤";
		worker.m_Name+=nameSeed[i];
		worker.m_Salary=rand()%10000+10000;//10000-19999
		v.push_back(worker);
	}
}
void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
	for(vector<Worker>::iterator it=v.begin();it!=v.end();it++)
	{
		int deptId=rand()%3;
		m.insert(make_pair(deptId,*it));
	}
}
void showWorkByGroup(multimap<int,Worker>&m)
{
	cout<<"PLAN: "<<endl;
	multimap<int,Worker>::iterator pos=m.find(PLAN);
	int count=m.count(PLAN);
	int index=0;
	for(;pos!=m.end()&&index<count;pos++,index++)
	cout<<"Name: "<<pos->second.m_Name<<" Salary "<<pos->second.m_Salary<<endl;
    
	cout<<"ART: "<<endl;
	pos=m.find(ART);
	count=m.count(ART);
	index=0;
	for(;pos!=m.end()&&index<count;pos++,index++)
	cout<<"Name: "<<pos->second.m_Name<<" Salary "<<pos->second.m_Salary<<endl;
	
	cout<<"INOVATION: "<<endl;
	pos=m.find(INOVATION);
	count=m.count(INOVATION);
	index=0;
	for(;pos!=m.end()&&index<count;pos++,index++)
	cout<<"Name: "<<pos->second.m_Name<<" Salary "<<pos->second.m_Salary<<endl;
	cout<<endl;
}
void print(vector<Worker>&v)
{
	for(vector<Worker>::iterator it=v.begin();it!=v.end();it++)
	cout<<"Name: "<<it->m_Name<<" Salary = "<<it->m_Salary<<endl;
}
int main()
{
	srand((unsigned int)time(NULL));
	vector<Worker>v;
	createWorker(v);
	
	multimap<int,Worker>m;
	setGroup(v,m);
	
	showWorkByGroup(m);
	
	print(v);
	
}
