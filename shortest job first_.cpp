#include<iostream>
#include<algorithm>
#include<cstring>

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
    
};

bool compare(Process p1, Process p2) {
    return p1.burst_time < p2.burst_time;
}

void sjf(Process processes[], int n) {
    sort(processes, processes + n, compare);
    
    int totalTAT =0;
    int total_waiting_time = 0;
    int waiting_time[n];
    waiting_time[0] = 0;
    processes[0].waiting_time = waiting_time[0];
    processes[0].allocation_time = 0;
	

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1].burst_time;
        processes[i].waiting_time = waiting_time[i];
        
        total_waiting_time += waiting_time[i];
        
    }



    float average_waiting_time = (float)total_waiting_time / n;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"gantt chart: "<<endl;
    int countr=0;
    for(int k=0;k<n;k++)
    {
    	
        cout<<"process "<<k+1<<": "<<" time " <<countr<<" unit to "<<countr+processes[k].burst_time<<" unit"<<endl;
    	countr+=processes[k].burst_time;
    	processes[k].completion_time = countr;
    	processes[k+1].allocation_time = countr;
    	processes[k].turn_around_time = processes[k].completion_time - processes[k].arrival_time;
    	processes[k].response_time = processes[k].allocation_time - processes[k].arrival_time;
    }
    cout<<"----------------------------------------"<<endl;
    	for(int j =0; j<n ;j++)
	{
		totalTAT += processes[j].turn_around_time;
	}
 cout<< "--------------------------------------"<<endl;
    cout << "name\tarrival\tburst\tcompletion\tTAT\tWT\tRT\n";
   
    for (int i = 0; i < n; i++) {
        cout << processes[i].pname << "\t" << processes[i].arrival_time 
			 << "\t" << processes[i].burst_time <<"\t"
			 << "\t" << processes[i].completion_time <<"\t"<< processes[i].turn_around_time
			 << "\t" << processes[i].waiting_time << "\t" << processes[i].response_time <<endl;
    }
    cout<<"---------------------------------------"<<endl;
    cout<<endl;
    cout << "Average Waiting Time: " << average_waiting_time << endl<<endl;
    cout << totalTAT;
    cout<< " Average turn around time: "<< (float)totalTAT/n <<endl<<endl;
    cout<<"---------------------------------------"<<endl;
    
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];
    
    for (int i = 0; i < n; i++) {
    cout << "Enter details of process "<<i+1<<": "<<endl;
        processes[i].id = i + 1;
        cout<<"enter process name: ";
        cin>>processes[i].pname;
        cout<<"Enter burst time: ";
        cin >> processes[i].burst_time;
        cout<<"Enter arrival time: ";
        cin>>processes[i].arrival_time;
        
    }

    sjf(processes, n);

    return 0;
}
