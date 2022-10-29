def myfun(a, b):
	return (a**b**b)*(b**a**a)

def factorial(a):
	if a > 1:
		return a*factorial(a-1)
	return 1

for i in range(23):
	print(factorial(i))