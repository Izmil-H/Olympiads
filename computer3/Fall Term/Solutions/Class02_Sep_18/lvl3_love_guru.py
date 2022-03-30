A = list(input().lower())
B = list(input().lower())

vaA = 0
vaB = 0
for i in range(len(A)):
    vaA += pow(ord(A[i]) - ord('a') + 1, i+1, 10)
for i in range(len(B)):
    vaB += pow(ord(B[i]) - ord('a') + 1, i+1, 10)
vaA = vaA % 10
vaB = vaB % 10
if vaA == 0:
    vaA += 10
if vaB == 0:
    vaB += 10
print(vaA + vaB)