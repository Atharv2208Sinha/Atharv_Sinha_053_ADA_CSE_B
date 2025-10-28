import matplotlib.pyplot as plt

xN1 = [20,40,60,80,100,120]
yN1 = [0.0052,0.0107,0.0159,0.0228,0.028,0.034]

xN2 = [20,40,60,80,100,120]
yN2 = [0.0092,0.0186,0.0285,0.0382,0.049,0.058]

xN3 = [20,40,60,80,100,120]
yN3 = [0.0173,0.0344,0.0513,0.0692,0.086,0.104]

xW1 = [50,100,200]
yW1 = [0.0052,0.0092,0.0173]

xW2 = [50,100,200]
yW2 = [0.0107,0.0186,0.0344]

xW3 = [50,100,200]
yW3 = [0.0159,0.0285,0.0513]

xWN = [1000,4000,16000]
yWN = [0.0052,0.0186,0.0692]

xtN = [20,40,60,80,100,120]

fig = plt.figure(figsize=(10,6))
gs = fig.add_gridspec(2, 2, height_ratios=[1, 1], hspace=0.3, wspace=0.2)
ax = fig.add_subplot(gs[0, :])
ax1 = fig.add_subplot(gs[1, 0])
ax2 = fig.add_subplot(gs[1, 1])

ax.plot(xN1, yN1, '-o', color='red', label='W=50')
ax.plot(xN2, yN2, '-o', color='blue', label='W=100')
ax.plot(xN3, yN3, '-o', color='green', label='W=200')
ax.set_title('W: Fixed')
ax.set_xlabel('N')
ax.set_ylabel('Runtime (ms)')
ax.legend()
ax.grid(color = 'gray', linestyle = '--', linewidth = 0.2)
ax.set_xticks(xtN)
ax.set_xticklabels(xtN)

ax1.plot(xW1, yW1, '-o', color='red', label='N=20')
ax1.plot(xW2, yW2, '-o', color='blue', label='N=40')
ax1.plot(xW3, yW3, '-o', color='green', label='N=60')
ax1.set_title('N: Fixed')
ax1.set_xlabel('W')
ax1.set_ylabel('Runtime (ms)')
ax1.legend()
ax1.grid(color = 'gray', linestyle = '--', linewidth = 0.1)
ax1.set_xticks([50,100,200])
ax1.set_xticklabels([50,100,200])

ax2.plot(xWN, yWN, '-o', color='orange')
ax2.set_title('N & W both variable')
ax2.set_xlabel('N x W')
ax2.set_ylabel('Runtime (ms)')
ax2.grid(color = 'gray', linestyle = '--', linewidth = 0.1)
ax2.set_xticks([1000,4000,16000])
ax2.set_xticklabels(['20x50', '40x100', '80x200'])

plt.suptitle('0/1 Knapsack problem',y=0.96)
plt.show()