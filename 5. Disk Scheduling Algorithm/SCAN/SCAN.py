# User Input ---------------------------
n = int(input("Enter number of requests: "))
print("Enter requests: ")
r = []
for i in range(n):
    t = int(input())
    r.append(t)
ds = int(input("Enter disk size: "))
c = int(input("Enter current head position: "))
d = input("Enter direction (L-left, R=right): ")

# Input 1 ---------------------------
# n = 7
# r = [82,170,43,140,24,16,190]
# ds = 200
# c = 50
# d = 'R'

# Input 2 ---------------------------
# n = 8
# r = [176,79,34,60,92,11,41,114]
# ds = 200
# c = 50
# d = 'L'

m=0
seq = [c]
lr = []
rr = []

for x in r:
    if x<c:
        lr.append(x)
    else:
        rr.append(x)


rr = sorted(rr)
lr = sorted(lr,reverse=True)

if d=='L':
    m+=c-0
    m+=rr[-1]
    seq+=lr
    seq+=rr
else:
    m+=(ds-1-c)
    m+=(ds-1-seq[-1])
    seq+=rr
    seq+=lr

print("Total number of track movement:",m)
print("Sequence:",*seq)

# Output 1
# Total number of track movement: 332
# Sequence: 50 82 140 170 190 43 24 16

# Output 2
# Total number of track movement: 226
# Sequence: 50 41 34 11 60 79 92 114 176