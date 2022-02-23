n = int(input())

counter = [0] * n

l = map(int, input().split(' '))
for x in l:
	counter[x-1] += 1
	
for i, num in enumerate(counter):
	if (num != 4):
		print(i + 1)
		
