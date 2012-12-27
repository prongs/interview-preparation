fib_seq=[0,1,1,2,3,5,8,13,21,34,55,89,144]

def fib(n):
    if n>=len(fib_seq):
        for i in xrange(len(fib_seq), n+1):
            fib_seq.append(fib_seq[-1]+fib_seq[-2])
    return fib_seq[n]
