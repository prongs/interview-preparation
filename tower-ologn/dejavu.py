from itertools import count
def dejavu(n):
	a=[1,2,2]
	a={1:1,2:2}
	i=3
	l=3
	def next():
		yield 2
		k_0=3
		for k in count(k_0):

			for i in xrange(a[k]):
				yield k

	g=next()
	while(l<n):
		a[i]=g.next()
		l+=a[i]
		i+=1
	return a

if __name__ == '__main__':
	n=10**5
	a=dejavu(n**3)
	def cubic_gen():
		k=1
		s=0
		for n1 in count(1):
			for k1 in count(k):
				s+=a[k1]
				if s>=n1**3:
					yield k1
					k=k1+1
					break
	cg=cubic_gen();
	sums=[0]
	for i in xrange(n):
		sums.append(sums[-1]+cg.next())
	print sums


