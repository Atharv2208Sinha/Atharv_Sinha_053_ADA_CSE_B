import matplotlib.pyplot as plt

x = [100,1000,10000,100000]
y = [17,30,37,44]

plt.plot(x, y, '-o', color='blue')

for xi, yi in zip(x, y):
    plt.text(xi + 500, yi-0.5, f'({xi}, {yi})', fontsize=8, va='center')

plt.xlabel('No. of Elements in list (n)')
plt.ylabel('Runtime (10^(-6) ms)')
plt.title('Linear Search')
plt.show()