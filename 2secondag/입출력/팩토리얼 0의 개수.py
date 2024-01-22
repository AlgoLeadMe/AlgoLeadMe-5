N = int(input())
result=1
count = 0

for i in range(1,N+1):
  result *= i

result = str(result)

for a in range(1,len(result)):
  if result[-a] == "0":
    count+=1
  else:
    break

print (count)
