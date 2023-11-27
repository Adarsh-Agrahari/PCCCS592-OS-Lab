# Taking User Input
n = int(input("Enter number of jobs: "))
print("Enter process arrival time and burst time:")
jobs = []
total_time = 0  # Total time
for i in range(n):
    pt, att, btt = input().split()
    jobs.append((pt, int(att), int(btt)))
    total_time += int(btt)

# Initialize variables
p, at, bt, st, ct, tat, wt, rt = [], [], [], [], [], [], [], []
currt = 0
completed = [False] * n
arrived = []

# Sorting 
while currt <= total_time:
    # Check for newly arrived processes
    for i in range(n):
        if not completed[i] and jobs[i][1] <= currt:
            arrived.append((jobs[i][0], jobs[i][1], jobs[i][2], i))
            completed[i] = True

    if arrived:
        # Find the job with the shortest burst time among the arrived processes
        arrived.sort(key=lambda x: x[2])
        current_job = arrived[0]

        # Update job information
        p.append(current_job[0])
        at.append(current_job[1])
        bt.append(current_job[2])
        arrived = arrived[1:]

        # Update currt only if there are jobs in the bt list
        if bt:
            currt += bt[-1]  # Update currt with the last burst time
    else:
        currt += 1  # No jobs arrived, increment currt by 1


# Calculate start time and completion time
t = 0
for i in range(n):
    if t < at[i]:
        t = at[i]
    st.append(t)
    t += bt[i]
    ct.append(t)

# Calculate tat, at, bt
for i in range(n):
    tat.append(ct[i]-at[i])
    wt.append(tat[i]-bt[i])
    rt.append(st[i]-at[i])

# Calculate totals
t_tat, t_wt, t_rt = sum(tat), sum(wt), sum(rt)

# Print Table
print("Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tT.A.T\tW.T\tR.T")
for i in range(n):
    print(f"{p[i]}\t\t{at[i]}\t\t{bt[i]}\t\t{st[i]}\t\t{ct[i]}\t{tat[i]}\t{wt[i]}\t{rt[i]}")

print("Average turn around time:", t_tat/n)
print("Average waiting time:", t_wt/n)
print("Average response time:", t_rt/n)
