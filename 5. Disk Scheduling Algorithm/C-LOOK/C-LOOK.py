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
# d = 'R'

m=0
seq = [c]
lr = []
rr = []

for x in r:
    if x<c:
        lr.append(x)
    else:
        rr.append(x)

if d=='L':
    rr = sorted(rr,reverse=True)
    lr = sorted(lr,reverse=True)
    m+=(c-lr[-1])
    m+=(rr[0]-lr[-1])
    print(rr[0],rr[-1])
    m+=(rr[0]-rr[-1])
    seq+=lr
    seq+=rr
else:
    rr = sorted(rr)
    lr = sorted(lr)
    m+=(rr[-1]-c)
    m+=(rr[-1]-lr[0])
    m+=(lr[-1]-lr[0])
    seq+=rr
    seq+=lr

print("Total number of track movement:",m)
print("Sequence:",*seq)

# Output 1
# Total number of track movement: 341
# Sequence: 50 82 140 170 190 16 24 43

# Output 2
# Total number of track movement: 321
# Sequence: 50 60 79 92 114 176 11 34 41