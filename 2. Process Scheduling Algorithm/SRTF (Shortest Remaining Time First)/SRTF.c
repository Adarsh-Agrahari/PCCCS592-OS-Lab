#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Job {
    char p[10];
    int at, bt, st, ct, tat, wt, rt, ind;
};

int comp(const void *a, const void *b) {
    // Comparison function for qsort, sorting by burst time
    return (*(struct Job *)a).bt - (*(struct Job *)b).bt;
}

int main() {
    // Taking User Input
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    int b_t[n];
    struct Job arr[n];
    printf("Enter process arrival time and burst time\n");
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d", arr[i].p, &arr[i].at, &arr[i].bt);
        arr[i].st = 100;
        arr[i].ct = 0;
        arr[i].ind = i;
        b_t[i] = arr[i].bt;
    }

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
        // Check for newly arrived processes
        for (int i = 0; i < n; i++) {
            if (!done[i] && arr[i].at <= t) {
                arrived[arrivedCount] = arr[i];
                arrivedCount++;
                done[i] = true;
            }
        }

        if (arrivedCount > 0) {
            // Sort the arrived processes by burst time using qsort
            qsort(arrived, arrivedCount, sizeof(struct Job), comp);

            // Execute the process with the shortest burst time
            struct Job *curr = &arrived[0];
            curr->bt--;

            if (curr->st == 100) {
                curr->st = t;
            }

            t++; // Execute for one time unit

            // Check if the process has completed
            if (curr->bt == 0) {
                curr->ct = t;
                curr->tat = curr->ct - curr->at;
                curr->wt = curr->tat - curr->bt;
                curr->rt = curr->st - curr->at;
                arr[curr->ind] = *curr;
                c++;

                // Remove the completed process from the arrived queue
                for (int i = 0; i < arrivedCount - 1; i++) {
                    arrived[i] = arrived[i + 1];
                }
                arrivedCount--;
            }
        } else {
            t++; // If no process arrived yet, increment time
        }
    }

    for(int i=0;i<n;i++) arr[i].bt = b_t[i];

    // Calculate totals
    int tat = 0, wt = 0, rt = 0;
    for (int i = 0; i < n; i++) {
        tat += arr[i].tat;
        wt += arr[i].tat-arr[i].bt;
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
