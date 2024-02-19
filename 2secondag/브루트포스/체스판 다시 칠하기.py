N,M = map(int,input().split())
board = []
result = []

for i in range(N):
  board.append(list(input()))

for i in range (N-7):
  for j in range(M-7):
    w_start = 0
    b_start = 0
    for a in range(i,i+8):
      for b in range(j,j+8):
        if (a+b)%2 == 0:
          if board[a][b] == "W":
            b_start +=1
          else :
            w_start +=1
        else:
          if board[a][b] == "W":
            w_start += 1
          else:
            b_start += 1
    result.append(w_start)
    result.append(b_start)
print(min(result))
