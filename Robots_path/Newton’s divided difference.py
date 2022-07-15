import matplotlib.pyplot as plt
a= [[]]
x = []
y = [[]]
f_x = []
n = -1
b = []
xx = -1
p = []


def main():
    global n
    n = int(input("input the order:"))

    global xx
    xx = float(input("input the distance of x:"))

    global x
    print("input x array:")
    x = [float(input()) for i in range(n+1)]
    print(x)

    x_r = x[0]

    global y
    y = [[0 for i in range(n+1)]
         for j in range(n+1)]
    #print(y)

    global f_x
    f_x = [0]*(n+1)

    print("input f(x):")
    for i in range(n + 1):
        y[0][i] = float(input())

    print(y)

    m = (x[n] - x[0])/xx

    if m == int(m):
        plotans = [0]*(int(m))
    else:
        plotans = [0]*(int(m)+1)

    ni = 0

    k = n

    for i in range(1, n + 1):
        for j in range(0, k):
            y[i][j] = (y[i - 1][j + 1] - y[i - 1][j]) / (x[j + i] - x[j])
        k = k - 1

    #print(y)

    global b
    b = [0] * (n + 1)

    for i in range(n + 1):
        b[i] = y[i][0]
        f_x[i] = y[0][i]

    print("b is:", b)
    print("f_x is:", f_x)

    while x_r <= x[n]:
        l = 1
        ans = 0
        for i in range(n+1):
            l = b[i]
            for j in range(0, i):
                l *= (x_r - x[j])
            ans += l
            l = 1

        #print(ans)

        plotans[ni] = ans
        ni += 1

        x_r += xx
    print("for graph ploting:")
    print(plotans)

    size = len(plotans)

    global p
    p = [0] * size

    p[0] = x[0]

    for i in range(1, size):
        p[i] = p[i-1]+xx

    print(p)

    plt.plot(p, plotans)
    plt.show()


if __name__ == '__main__':
    main()