from scipy import interpolate
import matplotlib.pyplot as plt

global x
x = [2.0,4.25,5.25,7.81,9.2,10.6]
global y
y = [7.2,7.1,6.0,5.0,3.5,5.0]


def f(m):
    t = interpolate.splrep(x, y)
    return interpolate.splev(m, t)


n = 5


def main():
    xx = float(input("Enter the distance:"))
    x_r = x[0]
    m = (x[n] - x[0]) / xx
    if m == int(m):
        plotans = [0] * (int(m))
    else:
        plotans = [0] * (int(m) + 1)
    ni = 0

    while x_r <= x[n]:
        plotans[ni] = f(x_r)
        ni += 1
        x_r += xx
    print(plotans)

    size = len(plotans)

    global p
    p = [0] * size

    p[0] = x[0]

    for i in range(1, size):
        p[i] = p[i - 1] + xx

    plt.plot(p, plotans)
    plt.show()


if __name__ == '__main__':
    main()