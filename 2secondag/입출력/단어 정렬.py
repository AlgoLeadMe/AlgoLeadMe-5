N = int(input())
words = []

# N개의 단어 입력 받기
for i in range (N):
  word = input() 
  words.append(word)

  for j in range(i, 0, -1):
    if len(words[j-1]) > len(words[j]):
      temp = words[j-1]
      words[j-1] = words[j]
      words[j] = temp

    elif len(words[j-1]) == len(words[j]):
      if words[j-1] > words[j]:
        temp = words[j-1]
        words[j-1] = words[j]
        words[j] = temp

i = 1
while i < N:
    if words[i-1] == words[i]:
        for j in range(i, N):
            words[j-1] = words[j]
        N -= 1
    else:
        i += 1

for i in range(N):
   print(words[i])