import matplotlib.pyplot as plt

x = [100,1000,10000,100000]
y = [0.000073,0.000549,0.005392,0.058754]

plt.plot(x, y, '-o', color='blue')

plt.text(100, -0.001, f'(100,0.000073)', fontsize=8, va='center')
plt.text(2000,0.0007, f'(1000,0.000549)', fontsize=8, va='center')
plt.text(11500,0.0054, f'(10000,0.005392)', fontsize=8, va='center')
plt.text(101500,0.0588, f'(100000,0.058754)', fontsize=8, va='center')

plt.xlabel('No. of Elements in list (n)')
plt.ylabel('Runtime (ms)')
plt.title('Linear Search')
plt.show()