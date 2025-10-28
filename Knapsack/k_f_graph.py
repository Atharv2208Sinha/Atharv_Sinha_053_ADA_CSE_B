import matplotlib.pyplot as plt

x1 = [20,40,60,80,100,120]
y1 = [0.000265,0.000595,0.000946,0.001177,0.001417,0.001629]

plt.plot(x1, y1, '-o', color='red', label='Max Weight(W)=100')

x2 = [20,40,60,80,100,120]
y2 = [0.000433,0.001130,0.001803,0.002285,0.002781,0.003210]

plt.plot(x2, y2, '-o', color='blue', label='Max Weight(W)=200')

plt.grid(color = 'gray', linestyle = '--', linewidth = 0.2)

x_ticks = [20,40,60,80,100,120]
plt.xticks(x_ticks, x_ticks)

plt.xlabel('No. of items(N)')
plt.ylabel('Runtime (ms)')
plt.title('Knapsack Problem\n(Fractional)')
plt.legend()
plt.show()