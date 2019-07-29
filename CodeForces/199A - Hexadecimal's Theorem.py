def fibo(n):
    if(n == 0 or n == 1):
        return list()
    else:
        l = list()
        l.append(0); l.append(1)
        while(True):
            x = l[len(l)-1]
            y = l[len(l)-2]
            z = x + y
            l.append(z)
            if(z == n):
                break
        return l

n = int(input())
l = fibo(n)
if(len(l) == 0):
    if(n == 0):
        print(0, 0, 0)
    else:
        print(0 , 0, 1)
else:
    x = l[len(l)-3]
    y = l[len(l)-3]
    z = l[len(l)-4]
    print(x, y, z)
