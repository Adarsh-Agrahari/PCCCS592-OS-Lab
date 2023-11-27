#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Job {
    char p[10];
    int at, bt, st, ct, tat, wt, rt, ind;
};

int main() {
    // Taking User Input
    int n, time_quantum;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    printf("Enter process arrival time and burst time:\n");

    struct Job *jobs = (struct Job*)malloc(n * sizeof(struct Job));
    int total_time = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d", jobs[i].p, &jobs[i].at, &jobs[i].bt);
        jobs[i].st = 100;
        jobs[i].ct = 0;
        jobs[i].ind = i;
        total_time += jobs[i].bt;
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (jobs[i].at > jobs[j].at) {
                struct Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    int cur_time = 0;
    bool *completed = (bool*)malloc(n * sizeof(bool));
    struct Job *arrived = (struct Job*)malloc(n * sizeof(struct Job));
    struct Job *back = (struct Job*)malloc(n * sizeof(struct Job));
    int arrived_count = 0;
    int back_count = 0;

    while (cur_time <= total_time) {
        // Check for newly arrived processes
        for (int i = 0; i < n; ++i) {
            if (!completed[i] && jobs[i].at <= cur_time) {
                arrived[arrived_count++] = jobs[i];
                completed[i] = true;
            }
        }

        // Append the jobs from 'back' to 'arrived'
        for (int i = 0; i < back_count; ++i) {
            arrived[arrived_count++] = back[i];
        }
        back_count = 0;

        if (arrived_count > 0) {
            int min_bt = (time_quantum < arrived[0].bt) ? time_quantum : arrived[0].bt;
            arrived[0].bt -= min_bt;

            // Use the ind field to update the start time and completion time in the original array
            jobs[arrived[0].ind].st = (cur_time < jobs[arrived[0].ind].st) ? cur_time : jobs[arrived[0].ind].st;
            jobs[arrived[0].ind].ct = cur_time + min_bt;

            if (arrived[0].bt != 0) {
                back[back_count++] = arrived[0];
            }
            for (int i = 1; i < arrived_count; ++i) {
                arrived[i - 1] = arrived[i];
            }
            arrived_count--;
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
    printf("Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tT.A.T\tW.T\tR.T\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t%d\t%d\t%d\n", jobs[i].p, jobs[i].at, jobs[i].bt, jobs[i].st,
               jobs[i].ct, jobs[i].tat, jobs[i].wt, jobs[i].rt);
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

    printf("Average turn around time: %.2f\n", avg_tat);
    printf("Average waiting time: %.2f\n", avg_wt);
    printf("Average response time: %.2f\n", avg_rt);

    free(jobs);
    free(completed);
    free(arrived);
    free(back);

    return 0;
}
