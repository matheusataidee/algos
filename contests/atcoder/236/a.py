s = input()

l = [c for c in s]

a, b = input().split(' ')
a = int(a)
b = int(b)

a-=1
b-=1

l[a], l[b] = l[b], l[a]

s = ""
for c in l:
	s += c
print(s)
