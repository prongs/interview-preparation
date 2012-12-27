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

if __name__=="__main__":
    print noDevisers(12)
    print sumOfProperDivisors(220)
