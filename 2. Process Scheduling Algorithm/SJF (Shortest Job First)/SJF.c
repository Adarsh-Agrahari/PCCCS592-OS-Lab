#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Job {
    char p[10];
    int at, bt, st, ct, tat, wt, rt;
};

int comp(const void *a, const void *b) {
    // Comparison function for qsort, sorting by arrival time
    return (*(struct Job *)a).at - (*(struct Job *)b).at;
}


int main() {
    // Taking User Input
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    struct Job arr[n];
    printf("Enter process arrival time and burst time\n");
    for (int i = 0; i < n; i++)
        scanf("%s%d%d", arr[i].p, &arr[i].at, &arr[i].bt);

    int t = 0; // Current time
    int c = 0; // Number of completed processes
    bool done[n];
    for (int i = 0; i < n; i++) {
        done[i] = false;
    }

    // Store arrived processes
    struct Job arrived[n];
    int arrivedCount = 0;

    while (c < n) {
        // Add arrived processes to the queue
        for (int i = 0; i < n; i++) {
            if (!done[i] && arr[i].at <= t) {
                arrived[arrivedCount] = arr[i];
                arrivedCount++;
                done[i] = true;
            }
        }

        // If no process arrived yet, increment time
        if (arrivedCount == 0) {
            t++;
            continue;
        }

        // Sort the arrived processes by burst time using qsort
        qsort(arrived, arrivedCount, sizeof(struct Job), comp);

        // Execute the process with the shortest burst time
        struct Job curr = arrived[0];
        for (int i = 0; i < arrivedCount - 1; i++) {
            arrived[i] = arrived[i + 1];
        }
        arrivedCount--;

        curr.st = t;
        t += curr.bt;
        curr.ct = t;
        curr.tat = curr.ct - curr.at;
        curr.wt = curr.tat - curr.bt;
        curr.rt = curr.st - curr.at;
        arr[c] = curr;

        c++;
    }

    // Calculate totals
    int tat = 0, wt = 0, rt = 0;
    for (int i = 0; i < n; i++) {
        tat += arr[i].tat;
        wt += arr[i].wt;
        rt += arr[i].rt;
    }

    // Print Table
    printf("Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tT.A.T\tW.T\tR.T\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d\t%d\n", arr[i].p, arr[i].at, arr[i].bt, arr[i].st, arr[i].ct, arr[i].tat, arr[i].wt, arr[i].rt);
    }

    // Print Averages
    printf("Average turn around time: %.2f\n", (float)tat / n);
    printf("Average waiting time: %.2f\n", (float)wt / n);
    printf("Average response time: %.2f\n", (float)rt / n);

    return 0;
}
