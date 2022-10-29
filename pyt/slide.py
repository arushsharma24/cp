def slidingMaximum(A, B):
    sl = 0
    ans = sl 
    for i in range(len(A)-B+1):
        sl = max(A[i:i+B])
        if ans < sl:    ans = sl 
    return ans

A = [1, 3, -1, -3, 5, 3, 6, 7]
B = 3
print(slidingMaximum(A, B))