for i in xrange(int(raw_input())):
  n=raw_input()
  l=len(n)
  n2=[c for c in n]
  t=n.rfind('4')
  if t==-1:
    n2=['4']*(l+1)
  else:
    for j in xrange(t,l):
      if n2[j]=='4':
        n2[j]='7'
      elif n2[j]=='7':
        n2[j]='4'
  print ''.join(n2)
