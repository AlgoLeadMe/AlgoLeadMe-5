import sys

N = int(sys.stdin.readline())
N_list = map(int,sys.stdin.readline().split())
N_set = set(N_list)

M = int(sys.stdin.readline())
M_list = map(int,sys.stdin.readline().split())

index = 0

for i in M_list:
  if i in N_set:
    print(1)
  else:
    print(0)