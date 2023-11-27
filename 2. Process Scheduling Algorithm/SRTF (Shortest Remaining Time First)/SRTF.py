# Taking User Input
n = int(input("Enter number of jobs: "))
print("Enter process arrival time and burst time:")
jobs = []
total_time = 0  # Total time


# Initialize variables
p, at, bt, st, ct, tat, wt, rt = [], [], [],{}, {}, [], [], []
for i in range(n):
    pt, att, btt = input().split()
    p.append(pt)
    st[i]=100
    ct[i]=0
    at.append(int(att))
    bt.append(int(btt))
    jobs.append([pt, int(att), int(btt),i])
    total_time += int(btt)

currt = 0
completed = [False] * n
arrived = []

while currt <= total_time:
    # Check for newly arrived processes
    for i in range(n):
        if not completed[i] and jobs[i][1] <= currt:
            arrived.append([jobs[i][0], jobs[i][1], jobs[i][2],jobs[i][3]])
            completed[i] = True
    if arrived:
# Find the job with the shortest burst time among the arrived processes
        arrived.sort(key=lambda x: x[2])
        arrived[0][2]-=1
        st[arrived[0][3]]=min(currt,st[arrived[0][3]])
        ct[arrived[0][3]]=currt+1

        if(arrived[0][2]==0):
            arrived=arrived[1:]
    currt +=1
    
for i in range(n):
    tat.append(ct[i]-at[i])
    wt.append(tat[i]-bt[i])
    rt.append(st[i]-at[i])

# Print Table
print("Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tT.A.T\tW.T\tR.T")
for i in range(n):
    print(f"{p[i]}\t\t{at[i]}\t\t{bt[i]}\t\t{st[i]}\t\t{ct[i]}\t{tat[i]}\t{wt[i]}\t{rt[i]}")
# Calculate Averages
avg_tat = sum(tat)/n
avg_wt = sum(wt)/n
avg_rt = sum(rt)/n

print(f"Average turn around time: {avg_tat:.2f}")
print(f"Average waiting time: {avg_wt:.2f}")
print(f"Average response time: {avg_rt:.2f}")


