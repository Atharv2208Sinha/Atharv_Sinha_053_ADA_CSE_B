import matplotlib.pyplot as plt

x1 = [100,500,1000,5000,10000]
y1 = [0.005566,0.126070,0.4803,11.791,46.35]

plt.plot(x1, y1, '-o', color='red', label='Worst Case')

x2 = [100,500,1000,5000,10000]
y2 = [0.000151,0.000711,0.001395,0.007124,0.015]

plt.plot(x2, y2, '-o', color='blue', label='Best Case')

x3 = [100,500,1000,5000,10000]
y3 = [0.002995,0.064880,0.2513,6.072,23.54]

plt.plot(x3, y3, '-o', color='green', label='Average Case')

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [100, 500, 1000, 5000, 10000]
plt.xticks(x_ticks, [f'{i}' for i in x_ticks])

plt.xlabel('n')
plt.ylabel('Runtime (ms)')
plt.title('Insertion Sort')
plt.legend()
plt.show()