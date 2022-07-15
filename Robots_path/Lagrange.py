import matplotlib.pyplot as plt

n = int(input("Give n input:"))

print("Input x array:")
x = [float(input()) for i in range(n)]
print("Input f(x) array:")
y = [float(input()) for i in range(n)]
xx = float(input("Give the difference of x :"))
la = 1
l = [0]*n
x_r = x[0]
ni = 0

m = (x[n-1] - x[0])/xx
if m == int(m):
    plotans = [0] * (int(m)+1)
else:
    plotans = [0] * (int(m) + 2)

while x_r <= x[n-1]:
    la = 1
    ans = 0
    for i in range(0,n):
        for j in range(0,n):
            if j != i:
                la *= (x_r - x[j])/(x[i] - x[j])
        l[i] = la
        la = 1
    print(l)
    for i in range(0,n):
        ans += l[i]*y[i]

    #print("The cof is:")
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
    p[i] = p[i - 1] + xx

print(p)

plt.plot(p, plotans)
plt.show()
