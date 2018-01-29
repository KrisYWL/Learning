
# coding: utf-8

# In[6]:


from __future__ import print_function

import numpy as np
import matplotlib.cm as cm
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt
import matplotlib.cbook as cbook
from matplotlib.path import Path
from matplotlib.patches import PathPatch


# In[12]:


np.random.seed(19680801)

mu=100
sigma=15
x=mu+sigma*np.random.randn(437)

num_bins=50

fig,ax=plt.subplots()

n,bins,patches=plt.hist(x,num_bins,normed=1)

y=mlab.normpdf(bins,mu,sigma)
ax.plot(bins,y,'--')
ax.set_xlabel('Probability density')
ax.set_title(r'Histogram  $\mu=15$  $\sigma=100$')
plt.show()

