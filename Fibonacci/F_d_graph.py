import matplotlib.pyplot as plt

x = [10, 15, 20, 25, 30, 35]
y = [18, 26, 35, 44, 51.8, 60.03]


plt.plot(x, y, '-o', color='blue',)

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [10, 15, 20, 25, 30, 35]
plt.xticks(x_ticks, x_ticks)

plt.xlabel('n')
plt.ylabel('Runtime (ns)')
plt.title('Fibonacci Series\n(Dynamic - Bottom Up)')
plt.show()