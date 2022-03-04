n, m = map(int, input().split(' '))
l = list(map(int, input().split(' ')))
has = dict()
for sz in l:
	if (sz in has):
		has[sz] = has[sz] + 1
	else:
		has[sz] = 1


l = list(map(int, input().split(' ')))
ok = True
for sz in l:
	if (sz not in has):
		ok = False
	else:
		has[sz] = has[sz] - 1
		if (has[sz] == 0):
			del has[sz]
			
print(['No', 'Yes'][ok])
