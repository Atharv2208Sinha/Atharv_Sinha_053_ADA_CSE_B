import matplotlib.pyplot as plt

x = [4, 8, 10, 20, 30, 50, 75, 100, 200, 300,  400, 500]
y = [0.000283, 0.001469, 0.002647, 0.0213, 0.0615, 0.3005, 0.984, 2.296, 17.949, 66.35, 162.05, 333.87]

x1 = []
y1 = []

plt.plot(x, y, '-o', color='blue', label='Code')
plt.plot(x1, y1, '-o', color='red', label='x^3')

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [4, 10, 20, 30, 50, 75, 100, 200, 300,  400, 500]
plt.xticks(x_ticks, x_ticks)

plt.xlabel('n')
plt.ylabel('Runtime (ms)')
plt.title('Matrix Multiplication\n(Iterative Method)')
plt.legend()
plt.show()