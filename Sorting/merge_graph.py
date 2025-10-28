import matplotlib.pyplot as plt

x1 = [100,500,1000,5000,10000]
y1 = [0.002784,0.016540,0.0354,0.2011,0.419]

plt.plot(x1, y1, '-o', color='red', label='Worst Case')

x2 = [100,500,1000,5000,10000]
y2 = [0.002786,0.016440,0.0362,0.2161,0.4344]

plt.plot(x2, y2, '-o', color='blue', label='Best Case')

x3 = [100,500,1000,5000,10000]
y3 = [0.002893,0.017130,0.036,0.213,0.429]

plt.plot(x3, y3, '-o', color='green', label='Average Case')

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [100, 500, 1000, 5000, 10000]
plt.xticks(x_ticks, [f'{i}' for i in x_ticks])

plt.xlabel('n')
plt.ylabel('Runtime (ms)')
plt.title('Merge Sort')
plt.legend()
plt.show()