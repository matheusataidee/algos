n = int(input())
l = []
for i in range(n):
	line = input().split(' ')
	l.append('{} {}'.format(line[0], line[1]))

l.sort()
cond = False
for i in range(len(l)-1):
	if (l[i] == l[i+1]):
		cond = True
		
if (cond):
	print('Yes')
else:
	print('No')
