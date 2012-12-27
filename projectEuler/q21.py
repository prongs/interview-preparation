from prime import *
a={}
amicablesum=0
for i in xrange(2,10000):
    a[i]=sumOfProperDivisors(i)

for (k,v) in a.items():
    try:
        if a[v]==k and v!=k:
            print k,v
            amicablesum=amicablesum+k
    except KeyError as e:
        pass

print amicablesum
