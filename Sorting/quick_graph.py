import matplotlib.pyplot as plt

x1 = [100,500,1000,5000,10000]
y1 = [0.00651,0.1251,0.4567,10.68,41.53]

plt.plot(x1, y1, '-o', color='red', label='Worst Case')

x2 = [100,500,1000,5000,10000]
y2 = [0.00166,0.0105,0.0431,0.361,0.79]

plt.plot(x2, y2, '-o', color='green', label='Average Case')

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [100, 500, 1000, 5000, 10000]
plt.xticks(x_ticks, [f'{i}' for i in x_ticks])

plt.xlabel('n')
plt.ylabel('Runtime (ms)')
plt.title('Quick Sort')
plt.legend()
plt.show()