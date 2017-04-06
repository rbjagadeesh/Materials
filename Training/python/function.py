x = range(5)

def modify(y):
	y[0] = 1000
	x = ['abc']
	print "x", x

print x
modify(x)
print x
