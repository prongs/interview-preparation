factors=[]
def lp(n):
	print n
	i=2
	while i<=n:
		if n%i==0:
			return i;
		i=i+1
n=600851475143
while n!=1:
	x=lp(n)
	factors.append(x)
	n=n/x
print max(factors)