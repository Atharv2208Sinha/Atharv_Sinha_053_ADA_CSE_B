import matplotlib.pyplot as plt

x = [4, 8, 16, 32, 64, 128, 256, 512]
y = [0.000968, 0.005507, 0.044804, 0.3426, 2.765, 22.591, 177.57, 1451.9]

x1 = []
y1 = []

plt.plot(x, y, '-o', color='blue', label='Code')
plt.plot(x1, y1, '-o', color='red', label='x^3')

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [4, 8, 16, 32, 64, 128, 256, 512]
plt.xticks(x_ticks, x_ticks)

plt.xlabel('n')
plt.ylabel('Runtime (ms)')
plt.title('Matrix Multiplication\n(Divide & Conquer)')
plt.legend()
plt.show()