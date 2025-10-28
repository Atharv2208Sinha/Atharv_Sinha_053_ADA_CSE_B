import matplotlib.pyplot as plt

x1 = [20,40,60,80,100]
y1 = [0.887, 1.919, 2.79, 3.51, 4.536]

plt.plot(x1, y1, '-o', color='red')

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [20,40,60,80,100]
plt.xticks(x_ticks, x_ticks)

plt.xlabel('No. of items(N)')
plt.ylabel('Runtime (micro seconds)')
plt.title('Activity Selection')
plt.show()