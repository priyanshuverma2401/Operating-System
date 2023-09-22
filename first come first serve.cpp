//implementing fcfs algorithm

#include<bits/stdc++.h>

using namespace std;

int countr;
class process{
	public:
		string Pname;
		int pid;
		int burstTime;
		int arrivalTime;
		int turnAroundTime;
		int completionTime;
		int waitingTime;
		int responseTime;
		int marked;
		
	process(string Pname ,int pid, int arrivalTime, int burstTime)
	{
		this->Pname = Pname;
		this->pid=pid;
		this->arrivalTime = arrivalTime;
		this->burstTime =burstTime;
		marked=0;
	}
};

vector<process>vec;

void fcfs(int p){
	    
	int i=p,k=0;
	float totalTAT=0,totalRTime=0,totalWT=0;
	vector<process>vec2;
	int count=0;

	for(int j=0;j<i;j++)
	{
		string gantt[i];
		countr=0;
		int min = vec[0].arrivalTime;
		for(int k=0;k<i;k++)
		{
			if(vec[k].marked == 0 && min>vec[k].arrivalTime)
			{
				min=vec[k].arrivalTime;
				countr++;
			}
		}
		vec[countr].marked==1;
		
		//vec2[j]=vec[countr];
		
		vec[j].completionTime = count+vec[j].burstTime;
		vec[j].turnAroundTime = vec[j].completionTime - vec[j].arrivalTime;
		vec[j].waitingTime = vec[j].turnAroundTime - vec[j].burstTime;
		vec[j].responseTime =vec[j].waitingTime;
		count = vec[j].completionTime;
		
	}
	
    for (int a=0;a<i;a++)
    {
    	totalTAT+=vec[a].turnAroundTime;
		totalWT+=vec[a].waitingTime;
		totalRTime+=vec[a].responseTime;
	}
	cout<<endl;
	
float avgTat =  totalTAT/p;
float avgWT =  totalWT/p;
float avgRT =  totalRTime/p;
cout<<"average turn around time: "<<avgTat<<endl;;
cout<<"average waiting time: " <<avgWT<<endl;
cout<<"average respose time: "<<avgRT<<endl;

cout<<"----------------------------------------------------------------------------"<<endl;
cout<<"\t"<<"name"<<"\t"<<"pid"<<"\t"<<"AT"<<"\t"
		<<"CT"<<"\t"<<"TAT"<<"\t"<<"WT"<<"\t"<<"RT"<<endl;
	while(k<i)
	{
		cout<<"\t"<<vec[k].Pname<<"\t"<<vec[k].pid<<"\t"<<vec[k].arrivalTime<<"\t"
			<<vec[k].completionTime<<"\t"<<vec[k].turnAroundTime<<"\t"
			<<vec[k].waitingTime<<"\t"<<vec[k].responseTime<<endl;
			k++;
	}
cout<<"------------------------------------------------------------------------------"<<endl;



}

int main()
{
	string Pname;
	int pid,at,bt;
	cout<<"provide process details: "<<endl;
	int i=0;
	while(true)
	{
		cout<<"Process name: ";
		cin>>Pname;
		cout<<"Arrival time: ";
		cin>>at;
			if(at<0) break;
		cout<<"burst time: ";
		cin>>bt;
			if(bt<0) break;
		process* newProcess = new process(Pname,100+i,at,bt);
		vec.push_back(*newProcess);
		i++;
	}
    cout<<"err1";
	fcfs(i+1);
	
	return 0;
}
