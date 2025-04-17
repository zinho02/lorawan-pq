import matplotlib.pyplot as plt
import numpy as np

algorithms = [
    "ML-DSA", "SLH-DSA", "Falcon", "MiRitH", "MQOM", "PERK", "MIRA", "SDitH", 
    "MAYO", "QR-UOV", "SNOVA", "UOV", "LESS", "CROSS", "SQISign", "HAWK", "FAEST"
]

energy_consumption_root = [
    9.8161, 11.6809, 9.8152, 17.1926, 27.4000, 12.0600, 12.0372, 11.0482,
    9.8683, 9.8572, 9.9178, 9.7825, 22.2882, 9.7992, 12.6295, 9.7808, 11.2763
]

energy_consumption_pair = [
    0.0233, 1.8980, 0.1661, 5.0208, 12.4242, 1.5585, 1.5821, 1.2407,
    0.0958, 0.3334, 0.1278, 0.1930, 9.1158, 0.0158, 4.0890, 0.0305, 1.0773
]

energy_consumption_root_mJ = [j * 1000 for j in energy_consumption_root]
energy_consumption_pair_mJ = [j * 1000 for j in energy_consumption_pair]

ordered = sorted(zip(algorithms, energy_consumption_root_mJ, energy_consumption_pair_mJ), key=lambda x: x[2], reverse=True)
algorithms = [i for i, _, _ in ordered]
energy_consumption_mJ = [j for _, j, _ in ordered]
energy_consumption_pair_mJ = [k for _, _, k in ordered]

x = np.arange(len(algorithms))

fig, ax1 = plt.subplots(figsize=(12, 6))

ax1.bar(x - 0.2, energy_consumption_mJ, width=0.4, color='tab:blue', label="Root Key Renewal Procedure")
ax1.set_ylabel("Energy Consumption (mJ) (Log Scale)", fontsize=14)
ax1.tick_params(axis='y', labelcolor='tab:blue', labelsize=14)
ax1.set_yscale("log")

ax2 = ax1.twinx()
ax2.bar(x + 0.2, energy_consumption_pair_mJ, width=0.4, color='tab:red', label="Key Pair Update Procedure")
ax2.tick_params(axis='y', labelcolor='tab:red', labelsize=14)
ax2.set_yscale("log")
ax2.set_ylim([1e1, 1e5])
ax1.set_ylim([1e1, 1e5])

ax1.tick_params(axis='x', labelrotation=45, labelsize=14)
plt.xticks(x, algorithms, rotation=45, ha="right")

ax2.yaxis.grid(color='gray', linestyle='dashed')
ax1.yaxis.grid(color='gray', linestyle='dashed')

handles1, labels1 = ax1.get_legend_handles_labels()
handles2, labels2 = ax2.get_legend_handles_labels()
ax1.legend(handles1 + handles2, labels1 + labels2, loc="lower left", bbox_to_anchor=(0, 1), fontsize=14)

fig.tight_layout()
plt.show()
