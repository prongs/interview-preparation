import itertools
fivecombs=itertools.combinations(xrange(52),5)
mapping={}
for c in fivecombs:
	# print "c= ",c
	fourcombs=itertools.combinations(c,4)
	for fc in fourcombs:
		key=reduce((lambda x,y:x|y), (1<<f for f in fc))
		if not mapping.has_key(key):
			cl=list(c)
			for d in fc:
				cl.remove(d)
			mapping[key]=cl[0]
			break
	else:
		print "Deadlock"
		fourcombs=itertools.combinations(c,4)
		for fc in fourcombs:
			key=reduce((lambda x,y:x|y), (1<<f for f in fc))
			print fc,":",mapping[key]
		break