for i in xrange(int(raw_input())):
  n,K=map(int,raw_input().split())
  numbers=map(int,raw_input().split())
  if n<=2:
    print "YES"
  else:
    np=map((lambda x: x % (K+1)), numbers)
    fr={}
    for i in np:
      fr[i]=fr.setdefault(i,0)+1
    if len(fr.keys())>2:
      print "NO"
    else:
      if max(fr.values())==n-1:
        print "YES"
      else:
        print "NO"
