def lucky(n):
  return all(i in ['4','7'] for i in n)
for i in xrange(int(raw_input())):
  n=raw_input()
  int_n=int(n)
  n1=int_n+1
  while True:
    if lucky(str(n1)):
      break
    n1+=1
  print n1
