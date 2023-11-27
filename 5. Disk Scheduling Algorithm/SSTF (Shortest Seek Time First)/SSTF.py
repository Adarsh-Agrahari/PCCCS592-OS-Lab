# User Input ---------------------------
n = int(input("Enter number of requests: "))
print("Enter requests: ")
r = []
for i in range(n):
    t = int(input())
    r.append(t)
ds = int(input("Enter disk size: "))
c = int(input("Enter current head position: "))

# Input 1 ---------------------------
# n = 7
# r = [82,170,43,140,24,16,190]
# ds = 200
# c = 50

# Input 2 ----------------------------
# n = 7
# r = [98, 183, 40, 122, 10, 124, 65 ]
# ds = 200
# c = 53

m = 0
vis = [0]*n
seq = [c]

while sum(vis)!=n:
    ind = n+1
    mn = ds+1
    for i in range(n):
        if vis[i]==0:
            d=abs(c-r[i])
            if(d<mn):
                mn = d
                ind = i
    seq.append(r[ind])
    c=r[ind]
    vis[ind]=1
    m+=mn

print("Total number of track movement:",m)
print("Sequence:",*seq)

# Output 1
# Total number of track movement: 208
# Sequence: 50 43 24 16 82 140 170 190

# Output 2
# Total number of track movement: 240
# Sequence: 53 65 40 10 98 122 124 183