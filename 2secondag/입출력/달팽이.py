A, B, V = map(int, input().split())
day = ((V-A) / (A-B)) + 1

if (V-A)%(A-B) == 0:
    print(int(day))
else:
    print(int(day)+1)