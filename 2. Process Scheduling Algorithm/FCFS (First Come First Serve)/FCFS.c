#include <stdio.h>
#include <stdlib.h>

struct Job {
    char p[5];
    int at, bt, st, ct, tat, wt, rt;
};

int compare(const void* a, const void* b) {
    return (*(struct Job*)a).at - (*(struct Job*)b).at;
}

int main() {
    // Taking User Input
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    struct Job arr[n];
    printf("Enter process arrival time and burst time\n");
    for (int i = 0; i < n; i++) scanf("%s %d %d", arr[i].p, &arr[i].at, &arr[i].bt);

    // Sorting
    qsort(arr, n, sizeof(struct Job), compare);

    // Calculate start time and completion time
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t < arr[i].at) t = arr[i].at;
        arr[i].st = t;
        t += arr[i].bt;
        arr[i].ct = t;
    }

    // Calculate tat, at, bt
    for (int i = 0; i < n; i++) {
        arr[i].tat = arr[i].ct - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
        arr[i].rt = arr[i].st - arr[i].at;
    }

    // Calculate totals
    float tat = 0, wt = 0, rt = 0;
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
    printf("Average turn around time: %.2f\n", tat / n);
    printf("Average waiting time: %.2f\n", wt / n);
    printf("Average response time: %.2f\n", rt / n);
    return 0;
}
