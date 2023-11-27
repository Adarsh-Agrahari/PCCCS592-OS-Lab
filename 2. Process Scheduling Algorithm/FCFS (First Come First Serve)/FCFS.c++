#include <bits/stdc++.h>
using namespace std;

struct Job {
    string p;
    float at,bt,st,ct,tat,wt,rt;
};

bool comp(Job x, Job y) {
    return x.at < y.at;
}

int main() {
    // Taking User Input
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    struct Job arr[n];
    cout << "Enter process arrival time and burst time" << endl;
    for(int i=0;i<n;i++) cin >> arr[i].p >> arr[i].at >> arr[i].bt;

    // Sorting
    sort(arr, arr + n, comp);

    // Calculate start time and completion time
    int t=0;
    for(int i=0;i<n;i++){
        if(t<arr[i].at) t = arr[i].at;
        arr[i].st=t;
        t+=arr[i].bt;
        arr[i].ct=t;
    }

    // Calculate tat, at, bt
    for(int i=0;i<n;i++){
        arr[i].tat=arr[i].ct-arr[i].at;
        arr[i].wt=arr[i].tat-arr[i].bt;
        arr[i].rt=arr[i].st-arr[i].at;
    }

    // Calculate totals
    float tat=0,wt=0,rt=0;
    for(int i=0;i<n;i++){
        tat+=arr[i].tat;
        wt+=arr[i].wt;
        rt+=arr[i].rt;
    }
    
    // Print Table
    cout << "Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tT.A.T\tW.T\tR.T" << endl;
    for(int i=0;i<n;i++) cout << arr[i].p << "\t"<< arr[i].at << "\t\t"<< arr[i].bt << "\t\t" << arr[i].st << "\t\t" << arr[i].ct << "\t\t" << arr[i].tat << "\t" << arr[i].wt << "\t" << arr[i].rt << endl;

    // Print Averages
    cout << "Average turn around time: " << tat/n << endl;
    cout << "Average waiting time: " << wt/n << endl;
    cout << "Average response time: " << rt/n << endl;
    return 0;
}
