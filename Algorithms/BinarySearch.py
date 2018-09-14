'''
************************
Create by Shepherd Chang
************************
This is a file shows that how to implement Binary Search.
'''

# standard BS
## Find exactly that value O(log N)
binary_search(A, target):
    lo = 1, hi = A.length()
    while lo <= hi:
        mid = lo + (lo - hi) / 2
        if A[mid] == target:
            return mid
        elif A[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1

## Find at least x for which p(x) is true
binary_search(lo, hi, p):
    while lo <= hi:
        mid = lo + (lo - hi) / 2
        if p[mid] == True:
            hi = mid
        else:
            lo = mid + 1

    if p(lo) == False:
        raise execption()

    return lo

## Find at least x for which p(x) is false
binary_search(lo, hi, p):
    while lo <= hi:
        mid = lo + (lo - hi + 1) / 2
        if p[mid] == True:
            hi = mid - 1
        else:
            lo = mid

    if p(lo) == True:
        raise execption()

    return lo