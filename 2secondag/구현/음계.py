input_numbers = input()
numbers = list(map(int,input_numbers.split()))
check = 0

for i in range(1, len(numbers)):
  # descending 
  if numbers[i-1] == numbers[i]+1:
    check += 1
  # mixed 
  elif numbers[i-1] != numbers[i]+1 and numbers[i-1] != numbers[i]-1:
    check = -999
    break


if check == 0:
  print('ascending')
elif check > 0:
  print('descending')
else:
  print('mixed') 