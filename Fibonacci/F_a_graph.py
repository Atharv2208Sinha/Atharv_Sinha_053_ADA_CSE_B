import matplotlib.pyplot as plt

x = [10, 15, 20, 25, 30, 35]
y = [0.000264, 0.002900, 0.0313, 0.3437, 3.828, 42.01]


plt.plot(x, y, '-o', color='blue',)

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [10, 15, 20, 25, 30, 35]
plt.xticks(x_ticks, x_ticks)

plt.xlabel('n')
plt.ylabel('Runtime (ms)')
plt.title('Fibonacci Series\n(Recursion)')
plt.show()