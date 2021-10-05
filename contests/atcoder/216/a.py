l = input().split('.')

num = int(l[1])
if (num <= 2):
	print('{}-'.format(l[0]))
elif (num <= 6):
	print('{}'.format(l[0]))
else :
	print('{}+'.format(l[0]))
