def unit_fraction_decimal_rep(n):
    numerator, denominator = 1, n
    fraction = []
    remainders = {}
    while True:
        numerator *= 10
        r = numerator % denominator
        q = (numerator - r)/denominator
        if(r == 0):
            fraction.append(q)
            break
        if(r in remainders.values()):
            foundCycle = False
            for key,value in remainders.items():
                if(r == value) and (q == int(fraction[key])):
                    # mark the cycle with parenthesis
                    fraction.insert(key,"(")
                    fraction.append(")")
                    foundCycle = True
                    break
            if foundCycle:
                break
        remainders[len(fraction)] = r
        fraction.append(str(q))
        numerator = r
    return "0."+"".join(fraction)
