import matplotlib.pyplot as plt

x1 = [100,500,1000,5000,10000]
y1 = [0.0156,0.3839,1.533,38,159]

plt.plot(x1, y1, '-o', color='red', label='Worst Case')

x2 = [100,500,1000,5000,10000]
y2 = [0.000096,0.000432,0.000856,0.003926,0.008261]

plt.plot(x2, y2, '-o', color='blue', label='Best Case')

x3 = [100,500,1000,5000,10000]
y3 = [0.0142,0.3466,1.285,31,142]

plt.plot(x3, y3, '-o', color='green', label='Average Case')

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [100, 500, 1000, 5000, 10000]
plt.xticks(x_ticks, [f'{i}' for i in x_ticks])

plt.xlabel('n')
plt.ylabel('Runtime (ms)')
plt.title('Bubble Sort')
plt.legend()
plt.show()