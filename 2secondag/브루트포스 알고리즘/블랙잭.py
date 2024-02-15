N,M = map(int, input().split())
card = list(map(int, input().split()))

# 크기 순으로 정렬
card.sort()

start = 0 
end = N-1
min_abs = card[0]+card[start]+card[end]

for i in range(0, N-2):
  for j in range(i+1, N-1):
    for k in range(j+1, N):
      sum = card[i] + card[j]+card[k]
      if sum <= M:
        if (M - sum) < (M-min_abs):
          min_abs = sum

print(min_abs)