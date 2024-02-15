import sys

N = int(sys.stdin.readline())
stack = []

for i in range (N):
  sen = list(map(str, sys.stdin.readline().split()))

  if sen[0] == "push":
    stack.append(int(sen[1]))
  
  elif sen[0] == "pop":
    if len(stack) > 0:
      print(stack[-1])
      stack.pop()
    else:
      print(-1)
  
  elif sen[0] == "size":
    print(len(stack))
  
  elif sen[0] == "empty":
    if len(stack) > 0:
      print(0)
    else: 
      print(1)

  elif sen[0] == "top":
    if len(stack)>0 :
      print(stack[-1])
    else:
      print(-1)
    