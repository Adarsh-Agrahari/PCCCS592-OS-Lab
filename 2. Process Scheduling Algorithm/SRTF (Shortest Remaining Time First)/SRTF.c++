#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

struct Job {
    string p;
    int at, bt, st, ct, tat, wt, rt;
};

int main() {
    // Taking User Input
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    cout << "Enter process arrival time and burst time:" << endl;

    vector<string> p;
    vector<int> at, bt;
    vector<int> st(n, 100), ct(n, 0), tat(n), wt(n), rt(n);
    vector<vector<int>> jobs;
    int total_time = 0;

    for (int i = 0; i < n; i++) {
        string pt;
        int att, btt;
        cin >> pt >> att >> btt;
        p.push_back(pt);
        st[i] = 100;
        ct[i] = 0;
        at.push_back(att);
        bt.push_back(btt);
        jobs.push_back({att, btt, i});
        total_time += btt;
    }

    int currt = 0;
    vector<bool> completed(n, false);
    vector<vector<int>> arrived;

    while (currt <= total_time) {
        // Check for newly arrived processes
        for (int i = 0; i < n; i++) {
            if (!completed[i] && jobs[i][0] <= currt) {
                arrived.push_back({jobs[i][0], jobs[i][1], jobs[i][2]});
                completed[i] = true;
            }
        }

        if (!arrived.empty()) {
            // Find the job with the shortest burst time among the arrived processes
            sort(arrived.begin(), arrived.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });

            arrived[0][1]--;
            st[arrived[0][2]] = min(currt, st[arrived[0][2]]);
            ct[arrived[0][2]] = currt + 1;

            if (arrived[0][1] == 0) {
                arrived.erase(arrived.begin());
            }
        }

        currt++;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = st[i] - at[i];
    }

    // Print Table
    cout << "Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tT.A.T\tW.T\tR.T" << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i] << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << st[i] << "\t\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\t" << rt[i] << endl;
    }
    // Calculate Averages
    int t_tat=0,t_wt=0,t_rt=0;
    for(int i=0;i<n;i++){
        t_tat+=tat[i];
        t_wt+=wt[i];
        t_rt+=rt[i];
    }

    cout << "Average turn around time: " << fixed << setprecision(2) << (float)t_tat/n << endl;
    cout << "Average waiting time: " << fixed << setprecision(2) << (float)t_wt/n << endl;
    cout << "Average response time: " << fixed << setprecision(2) << (float)t_rt/n << endl;

    return 0;
}
