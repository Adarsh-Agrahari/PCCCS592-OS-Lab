#include <bits/stdc++.h>
using namespace std;

struct Job {
    string p;
    int at, bt, st, ct, tat, wt, rt, ind;
};

int main() {
    // Taking User Input
    int n, time_quantum;
    cout << "Enter number of jobs: ";
    cin >> n;
    cout << "Enter process arrival time and burst time:" << endl;

    vector<Job> jobs(n);
    int total_time = 0;

    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].p >> jobs[i].at >> jobs[i].bt;
        jobs[i].st = 100;
        jobs[i].ct = 0;
        jobs[i].ind = i;
        total_time += jobs[i].bt;
    }

    cout << "Enter time quantum: ";
    cin >> time_quantum;

    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.at < b.at;
    });

    int cur_time = 0;
    vector<bool> completed(n, false);
    vector<Job> arrived;
    vector<Job> back;

    while (cur_time <= total_time) {
        // Check for newly arrived processes
        for (int i = 0; i < n; ++i) {
            if (!completed[i] && jobs[i].at <= cur_time) {
                arrived.push_back(jobs[i]);
                completed[i] = true;
            }
        }

        // Append the jobs from 'back' to 'arrived'
        arrived.insert(arrived.end(), back.begin(), back.end());
        back.clear();

        if (!arrived.empty()) {
            int min_bt = min(time_quantum, arrived[0].bt);
            arrived[0].bt -= min_bt;

            // Use the ind field to update the start time and completion time in the original array
            jobs[arrived[0].ind].st = min(cur_time, jobs[arrived[0].ind].st);
            jobs[arrived[0].ind].ct = cur_time + min_bt;

            if (arrived[0].bt != 0) back.push_back(arrived[0]);
            arrived.erase(arrived.begin());
            cur_time += min_bt;
        } else {
            cur_time += 1;
        }
    }

    // Calculate turnaround time, waiting time, and response time
    for (int i = 0; i < n; ++i) {
        jobs[i].tat = jobs[i].ct - jobs[i].at;
        jobs[i].wt = jobs[i].tat - jobs[i].bt;
        jobs[i].rt = jobs[i].st - jobs[i].at;
    }

    // Print Table
    cout << "Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tT.A.T\tW.T\tR.T" << endl;
    for (int i = 0; i < n; ++i) {
        cout << jobs[i].p << "\t\t" << jobs[i].at << "\t\t" << jobs[i].bt << "\t\t" << jobs[i].st << "\t\t"
                  << jobs[i].ct << "\t" << jobs[i].tat << "\t" << jobs[i].wt << "\t" << jobs[i].rt << endl;
    }

    // Calculate Averages
    float avg_tat = 0, avg_wt = 0, avg_rt = 0;
    for (int i = 0; i < n; ++i) {
        avg_tat += jobs[i].tat;
        avg_wt += jobs[i].wt;
        avg_rt += jobs[i].rt;
    }

    avg_tat /= n;
    avg_wt /= n;
    avg_rt /= n;

    cout << "Average turn around time: " << avg_tat << endl;
    cout << "Average waiting time: " << avg_wt << endl;
    cout << "Average response time: " << avg_rt << endl;

    return 0;
}
