k = list(map(int,input().split()))[-1]
s = input().split()
c = 0
p = ""
for i in range(len(s)):
    if len(s[i]) + c <= k:
        p += s[i]
        p += " "
        c += len(s[i])
    else:
        print(p.strip())
        p = s[i]
        p += " "
        c = len(s[i])
print(p.strip())