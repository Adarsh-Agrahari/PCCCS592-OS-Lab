#include <bits/stdc++.h>
using namespace std;

struct Job {
    string p;
    float at, bt, st, ct, tat, wt, rt;
};

bool comp(Job x, Job y) {
    // Sort by burst time
    return x.bt < y.bt;
}

int main() {
    // Taking User Input
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    vector<Job> arr(n);
    cout << "Enter process arrival time and burst time" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i].p >> arr[i].at >> arr[i].bt;

    int t = 0; // Current time
    int c = 0; // Number of completed processes
    vector<bool> done(n, false);

    // Store arrived processes
    vector<Job> arrived;

    while (c < n) {
        // Add arrived processes to the queue
        for (int i = 0; i < n; i++) {
            if (!done[i] && arr[i].at <= t) {
                arrived.push_back(arr[i]);
                done[i] = true;
            }
        }

        // If no process arrived yet, increment time
        if (arrived.empty()) {t++; continue;}

        // Sort the arrived processes by burst time
        sort(arrived.begin(), arrived.end(), comp);

        // Execute the process with the shortest burst time

        arr[c] = arrived[0];
        arrived.erase(arrived.begin());

        arr[c].st = t;
        t += arr[c].bt;
        arr[c].ct = t;
        arr[c].tat = arr[c].ct - arr[c].at;
        arr[c].wt = arr[c].tat - arr[c].bt;
        arr[c].rt = arr[c].st - arr[c].at;

        c++;
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
