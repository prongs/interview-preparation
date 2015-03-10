import sys, operator
def factorPrime(n):
    ans={}
    _n=n
    for i in approx_gen_primes():
        if _n == 1:
            break
        d,m = divmod(_n, i)
        while m==0:
            ans[i] = ans.get(i, 0) + 1
            _n = d
            d,m = divmod(_n, i)
    return ans
def noDevisers(n):
    primeFactors=factorPrime(n)
    ans=1
    for i in primeFactors.values():
        ans=ans*(i+1)
    return ans

def sumOfDevisors(n):
    divisors=factorPrime(n)
    ans=1
    for (k,v) in divisors.items():
        ans=ans*((k**(v+1)-1)/(k-1))
    return ans

def sumOfProperDivisors(n):
    return sumOfDevisors(n)-n

def to_num(factorization):
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

def approx_gen_primes():
    yield 2
    yield 3
    yield 5
    cur = 5
    while True:
        yield cur
        cur += 2
        yield cur
        cur += 4

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

if __name__=="__main__":
    print to_num(factorPrime(10)) == 10
    print to_num(factorPrime(100)) == 100
    print to_num(factorPrime(2520)) == 2520
    print noDevisers(12)
    print sumOfProperDivisors(220)
    print lcm(2,4,6,9)
    print multiply(2,4,6,9)
