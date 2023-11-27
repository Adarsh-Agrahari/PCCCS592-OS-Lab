# Taking User Input
n = int(input("Enter number of jobs: "))
print("Enter process arrival time and burst time:")
jobs = []
for i in range(n):
    pt, att, btt = input().split()
    jobs.append((pt, int(att), int(btt)))

# Sorting
jobs.sort(key=lambda x: x[1])

# Extract sorted data into separate lists
p, at, bt, st, ct, tat, wt, rt = [], [], [], [], [], [], [], []
for job in jobs:
    p.append(job[0])
    at.append(job[1])
    bt.append(job[2])

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
