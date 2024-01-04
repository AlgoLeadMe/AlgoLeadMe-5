N = int(input())

for i in range(1,N+1):
  for j in range (N - i):
    print(" ", end = "")

  a = 2 * i - 1 

  if a == N * 2 - 1:
    for k in range(a):
      print("*", end = "")

  else:
    for k in range(a):
      if (k == 0 or k == a-1 ):
        print("*", end = "")
      else:
        print(" ", end="")

  print()
