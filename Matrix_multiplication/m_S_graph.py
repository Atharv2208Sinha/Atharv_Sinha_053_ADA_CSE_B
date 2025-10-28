import matplotlib.pyplot as plt

x = [4, 8, 16, 32, 64, 128, 256, 512]
y = [0.003339, 0.021181, 0.1645, 1.214, 7.79, 56.79, 394, 2751]

x1 = []
y1 = []

plt.plot(x, y, '-o', color='blue', label='Code')
plt.plot(x1, y1, '-o', color='red', label='x^2.81')

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [4, 8, 16, 32, 64, 128, 256, 512]
plt.xticks(x_ticks, x_ticks)

plt.xlabel('n')
plt.ylabel('Runtime (ms)')
plt.title('Matrix Multiplication\n(Strassen)')
plt.legend()
plt.show()