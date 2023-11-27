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
# r = [98,183,37,122,14,129,65,67]
# ds = 200
# c = 53

m = 0
seq = [c]

for x in r:
    m+=abs(x-c)
    c=x 
    seq.append(c)
print("Total number of track movement:",m)
print("Sequence:",*seq)

# Output 1
# Total number of track movement: 642
# Sequence: 50 82 170 43 140 24 16 190

# Output 2
# Total number of track movement: 650
# Sequence: 53 98 183 37 122 14 129 65 67
