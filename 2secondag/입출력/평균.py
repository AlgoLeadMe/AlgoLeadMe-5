N = int(input())
a = list(map(int,input().split()))
M = max(a)
sum = 0

for i in range(N):
  a[i] = a[i] / M*100
  sum += a[i]
print(sum/N)