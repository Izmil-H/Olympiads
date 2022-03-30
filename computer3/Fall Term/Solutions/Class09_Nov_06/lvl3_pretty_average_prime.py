import sys
import math
input = sys.stdin.readline

def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True

for _ in range(int(input())):
    n = int(input())
    for a in range(2, n+1):
        if isPrime(a) and isPrime(2*n - a):
            print(a, 2*n-a)
            break