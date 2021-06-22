# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np




data = [
    [1, 2, 3],
    [2, 2, 2],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
    [3, 2, 1],
]








index = [
    "05-00",
    "05-01",
    "05-02",
    "05-03",
    "05-04",
    "05-05",
    "05-06",
    "05-07",
    "05-08",
    "05-09",
    "05-10",
    "05-11",
    "05-12",
    "05-13",
    "05-14",
    "05-15",
    "05-16",
    "05-17",
    "05-18",
    "05-19",
]



df = pd.DataFrame(data=data, index=index, columns=["Easy", "Medium", "Hard"])
# df = df.cumsum()
ax = df.plot()

fig=ax.get_figure()
fig.savefig(r'./test.svg')


