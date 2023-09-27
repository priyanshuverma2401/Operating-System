//implementing SRTF algorithm
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

class Process {
	public: 
	string pname;
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int response_time;
    int allocation_time;
    int remaining_time;
    
};

bool compare(Process p1, Process p2) {
    return p1.arrival_time < p2.arrival_time;
}

int main()
{
	int n,total_waiting_time=0,totalTAT=0;
	
	cout<<"Enter the total number of process : ";
	cin>>n;
	vector<Process>processes(n);
	int allocation[n]={-1};
	int waiting_time[n];
	for (int i = 0; i < n; i++) {
    cout << "Enter details of process "<<i+1<<": "<<endl;
        processes[i].id = i + 1;
        cout<<"enter process name: ";
        cin>>processes[i].pname;
        cout<<"Enter burst time: ";
        cin >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
        cout<<"Enter arrival time: ";
        cin>>processes[i].arrival_time;
        cout<<endl;
        cout<<"---------------------------------------------------------"<<endl;
    }
    
    sort(processes.begin(),processes.end(),compare);
    
	
    int current_time =0 ;
    int completed = 0 ;
    cout<<endl<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"gantt chart: "<<endl;
    while(completed < n)
    {
    	int shortest_index = -1;
    	int shortest_time =INT_MAX;
    	
    	for(int i=0; i<n;i++)
    	{
    		if(processes[i].arrival_time <= current_time &&processes[i].remaining_time < shortest_time && processes[i].remaining_time > 0)
    		{
    			shortest_index = i;
    			shortest_time = processes[i].remaining_time;
			}
		}
		
		
		if(shortest_index==-1)
		{
			current_time++;
		}else{
			processes[shortest_index].remaining_time--;
//			if(allocation[shortest_index] == -1)
//		{
//			allocation[shortest_index]= current_time;
//			processes[shortest_index].allocation_time=current_time;
//		}
			current_time++;
			cout<<"P"<<processes[shortest_index].id<<"("<<current_time<<") ";
			processes[shortest_index].completion_time = current_time;
			if(processes[shortest_index].remaining_time == 0)
		{
			completed ++;
			processes[shortest_index].remaining_time = INT_MAX;//MARK AS COMPLETED;
		}
		}
		
	}
	
	for(int i =0;i<n;i++)
	{
		processes[i].turn_around_time = processes[i].completion_time - processes[i].arrival_time;
		processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;
		processes[i].response_time = processes[i].allocation_time - processes[i].arrival_time;
	}
	
    
    for(int j =0; j<n ;j++)
	{
		totalTAT += processes[j].turn_around_time;
		total_waiting_time += processes[j].waiting_time;
	}
	cout<<endl<<endl;
	cout<< "--------------------------------------"<<endl;
    cout << "name\tarrival\tburst\tcompletion\tTAT\tWT\n";
   
    for (int i = 0; i < n; i++) {
        cout << processes[i].pname << "\t" << processes[i].arrival_time 
			 << "\t" << processes[i].burst_time <<"\t"
			 << "\t" << processes[i].completion_time <<"\t"<< processes[i].turn_around_time
			 << "\t" << processes[i].waiting_time << endl;
    }
    cout<<"---------------------------------------"<<endl;
    cout<<endl<<endl;
    
	cout<<"---------------------------------------"<<endl;
    cout<<endl;
    cout << "Average Waiting Time: " << (float)total_waiting_time/n << endl<<endl;
    cout << totalTAT;
    cout<< " Average turn around time: "<< (float)totalTAT/n <<endl<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<endl;
    
	return 0;
}
