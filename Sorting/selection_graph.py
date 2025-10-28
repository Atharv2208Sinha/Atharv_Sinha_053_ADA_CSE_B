import matplotlib.pyplot as plt

x1 = [100,500,1000,5000,10000]
y1 = [0.007,0.153,0.564,13.494,55.59]

plt.plot(x1, y1, '-o', color='red', label='Worst Case')

x2 = [100,500,1000,5000,10000]
y2 = [0.007,0.153,0.553,13.315,56.11]

plt.plot(x2, y2, '-o', color='blue', label='Best Case')

x3 = [100,500,1000,5000,10000]
y3 = [0.007,0.153,0.55,13.09,56.48]

plt.plot(x3, y3, '-o', color='green', label='Average Case')

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [100, 500, 1000, 5000, 10000]
plt.xticks(x_ticks, [f'{i}' for i in x_ticks])

plt.xlabel('n')
plt.ylabel('Runtime (ms)')
plt.title('Selection Sort')
plt.legend()
plt.show()