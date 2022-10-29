def f():
    n = int(input())
    s = int(input())
    m = pow(10, n+1)
    m = m-1
    print(m - s)


tc = int(input())
for i in range(tc):
    f()