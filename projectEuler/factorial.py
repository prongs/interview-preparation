fact_list=[1,1,2,6,24,120,720]
def fact(n):
    l=len(fact_list)
    if n>=l:
        for i in range(l, n+1):
            fact_list.append(fact_list[-1]*i)
    return fact_list[n]
