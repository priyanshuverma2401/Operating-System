//first come first serve[FCFS] scheduling algorithm

#include<iostream>
#include<queue>

using namespace std;

class process{
	public:
		int pid;
		int arrivalTime;
		int burstTime;
			process(int pid,int arrivalTime,int burstTime){
				this->pid=pid;
				this->arrivalTime=arrivalTime;
				this->burstTime=burstTime;
			}
};

struct compare{
	bool operator()(const process & a, const process & b) const{
	return a.arrivalTime < b.arrivalTime;
	}
};

void fcfs(priority_queue<process,vector<process>,compare>& processes){
	int currentTime = 0;
	while(!processes.empty()){
		process currentProcess = processes.top();
		processes.pop();
		if(currentTime <= currentProcess.arrivalTime){
			currentTime = currentProcess.arrivalTime;
		}
		
		cout<<"executing process "<<currentProcess.pid<<" from time "<<currentTime;
		currentTime += currentProcess.burstTime;
		cout<<" to time "<<currentTime<<endl;
		
	}
}

int main(){
	priority_queue<process,vector<process>,compare> processes;
	int pid =0,arrivalTime,burstTime;
	cout<<"input: (pid arrivalTime burstTime) [enter -ve pid to exit loop]"<<endl;
	while(1){
		
		cin>>pid;
		if(pid<0) break;
		cin>>arrivalTime>>burstTime;
		
		processes.push(process(pid,arrivalTime,burstTime));	
		cout<<"saved!"<<endl;
	}
	fcfs(processes);
	
	
	return 0;
}
