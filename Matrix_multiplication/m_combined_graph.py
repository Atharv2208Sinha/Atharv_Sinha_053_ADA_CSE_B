import matplotlib.pyplot as plt

x1 = [512, 1024, 2048, 4096]
y1 = [0.32, 3.056, 51.263, 612.886]

plt.plot(x1, y1, '-o', color='green', label='Iterative Method')

x2 = [512, 1024, 2048, 4096]
y2 = [1.41, 11.116, 92.997, 834.309]

plt.plot(x2, y2, '-o', color='blue', label='Divide & Conquer')

x3 = [512, 1024, 2048, 4096]
y3 = [1.757, 12.542, 97.974, 697.206]

plt.plot(x3, y3, '-o', color='red', label="Strassen's Method")

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [512, 1024, 2048, 4096]
plt.xticks(x_ticks, x_ticks)

plt.xlabel('n')
plt.ylabel('Runtime (s)')
plt.title('Matrix Multiplication\n(Comparison)')
plt.legend()
plt.show()