def merge_and_count(a,b):
  c=[]
  count=0
  i,j=0,0
  while i<len(a) and j<len(b):
    c.append(min(b[j], a[i]))
    if b[j]<a[i]:
      count+=len(a)-i
      j+=1
    else:
      i+=1
  c+=a[i:]+b[j:]
  return count,c
def sort_and_count(L):
  if len(L)==1: return 0,L
  n=len(L)//2
  a,b=L[:n],L[n:]
  ra,a=sort_and_count(a)
  rb,b=sort_and_count(b)
  r,L=merge_and_count(a,b)
  return ra+rb+r,L

for i in xrange(int(raw_input())):
  st=""
  while len(st)==0:
    st=raw_input()
  n=int(st)
  nums1=map(int,raw_input().split())
  nums2=map(int,raw_input().split())
  perm=map(dict((v,i) for i,v in enumerate(nums2)).get, nums1)
  ans=sort_and_count(perm)
  print ans[0]
