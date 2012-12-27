for t in xrange(int(raw_input())):
    n,P=map(int,raw_input().split())
    d,m=divmod(n,P)
    res=0;
    if d!=0:
        res=(n+1)*d-2*(P*d*(d-1)/2+d*(m+1))
    print res
    #n=2,P=2
    #d=1,m=0
    #k=0: 1 0 1
    #k=1: 1 0 0
    #k=2: 1 1 0
    #3-2*()
