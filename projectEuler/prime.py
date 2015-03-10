import sys, operator

def factorPrime(n):
    ans={}
    _n=n
    while _n!=1:
        def temp(_n):
            i=2
            while i*i<=_n:
                if _n%i==0:
                    try: arbit=ans[i]
                    except KeyError as e: ans[i]=0
                    ans[i]=ans[i]+1
                    _n=_n/i
                    return _n;
                i=i+1
            try: arbit=ans[_n]
            except KeyError as e: ans[_n]=0
            ans[_n]=ans[_n]+1
            return 1
        _n=temp(_n);
    return ans

def to_num(factorization):
    print factorization
    return reduce(operator.mul, (k**v for k,v in factorization.items()))

def lcm(*args):
    f = {}
    for n in args:
        for k,v in factorPrime(n).items():
            f[k] = max(f.get(k,0), v)
    return to_num(f)

def multiply(*args):
    f = {}
    for n in args:
        for k,v in factorPrime(n).items():
            f[k] = f.get(k,0) + v
    return to_num(f)

def gen_primes():
    """ Generate an infinite sequence of prime numbers.
    """
    # Maps composites to primes witnessing their compositeness.
    # This is memory efficient, as the sieve is not "run forward"
    # indefinitely, but only as long as required by the current
    # number being tested.
    #
    D = {}

    # The running integer that's checked for primeness
    q = 2

    while True:
        if q not in D:
            # q is a new prime.
            # Yield it and mark its first multiple that isn't
            # already marked in previous iterations
            #
            yield q
            D[q * q] = [q]
        else:
            # q is composite. D[q] is the list of primes that
            # divide it. Since we've reached q, we no longer
            # need it in the map, but we'll mark the next
            # multiples of its witnesses to prepare for larger
            # numbers
            #
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]

        q += 1
