import sys

N, K = map(int, sys.stdin.readline().split())
people = []

for i in range(1,N+1):
  people.append(i)

result = []


index = 0
for i in range(1, N + 1):
    index = (index + K - 1) % len(people)
    result.append(people.pop(index))

print("<" + ", ".join(map(str, result)) + ">")
