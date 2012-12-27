from prime import *
def a(n):
    return noDevisers((n)*(n+1)/2)

i=2
while a(i)<500:
    i=i+1
print i*(i+1)/2
