import random
def get_test_case():
  l=random.randint(1,1000)
  lis=['4' if random.random()>0.5 else '7' for i in xrange(l)]
  return ''.join(lis)

nums=[get_test_case() for i in xrange(10000)]

f=open('test.txt','w')
print>>f, 10000
for n in nums:
  print>>f, n
