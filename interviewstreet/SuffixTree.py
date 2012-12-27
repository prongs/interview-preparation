from array import array
class SuffixTree:
    strings=[];
    trie=[None]*26
    base=ord('a')
    def __init__(self, strings):
        self.strings=list(strings)
        print self.strings
        self.trie=[None]*26
        for s in self.strings:
          self.add(s)
    def add(self, string):
      l=len(string)
      for i in xrange(0,l):
        t=self.trie
        for j in xrange(i,l):
          ind=ord(string[j])-self.base
          if t[ind]==None:
            t[ind]=[None]*26
          t=t[ind]
    def to_sorted_list(self):
      result=[]
      def to_list(t,s):
        ret=[]
        for i in xrange(26):
          if t[i]!=None:
            s1=s+chr(self.base+i)
            ret.append(s1);
            ret.extend(to_list(t[i],s1))
        return ret
      return to_list(self.trie, "")


st=SuffixTree(raw_input() for i in xrange(0,int(raw_input())))
sl=st.to_sorted_list();
l=len(sl)
for t in xrange(int(raw_input())):
  n=int(raw_input())
  if n>l:
    print "INVALID"
  else:
    print sl[n-1]
