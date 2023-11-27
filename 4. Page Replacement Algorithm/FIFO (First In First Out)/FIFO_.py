a = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1]
n = len(a)
f = 3
l = []
pf = 0
for i in range(n):
    if a[i] not in l:
        if len(l)==f:
            l=l[1:]
        l.append(a[i])
        pf+=1
    print(a[i],end="       ")
    print(*l)
h=n-pf
print("Page Faults: ",pf)
print("Hits: ",h) 

# 7       7
# 0       7 0
# 1       7 0 1
# 2       0 1 2
# 0       0 1 2
# 3       1 2 3
# 0       2 3 0
# 4       3 0 4
# 2       0 4 2
# 3       4 2 3
# 0       2 3 0
# 3       2 3 0
# 2       2 3 0
# 1       3 0 1
# Page Faults:  11
# Hits:  3