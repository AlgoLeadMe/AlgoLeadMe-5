sen = input()

while sen != "0":
  index = 0

  for i in range (0, len(sen)//2):
    j = (len(sen)-1) - i
    if sen[i] != sen[j]:
        index = 1

  if index == 0:
    print("yes")

  else:
    print("no")
  
  sen = input()
      
