
# coding: utf-8

# In[1]:


import pandas as pd
#利用pandas的read_csv从网上搜集
titanic=pd.read_csv('http://biostat.mc.vanderbilt.edu/wiki/pub/Main/DataSets/titanic.txt')
titanic.head()


# In[2]:


titanic.info()


# In[3]:


X=titanic[['pclass','age','sex']]
y=titanic['survived']

X.info()


# In[4]:


#清洗数据，对空缺值填补
X['age'].fillna(X['age'].mean(),inplace=True)

X.info()


# In[6]:


#数据分割
from sklearn.cross_validation import train_test_split
X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.25,random_state=33)

#用feature_extraction特征抽取
from sklearn.feature_extraction import DictVectorizer
vec=DictVectorizer(sparse=False)
#转换特征，单独剥离，自成一列特征，数值型特征保持不变。
X_train=vec.fit_transform(X_train.to_dict(orient='record'))
print(vec.feature_names_)


# In[7]:


#对测试数据进行特征转换
X_test=vec.transform(X_test.to_dict(orient='record'))
#导入决策树分类器
from sklearn.tree import DecisionTreeClassifier
#默认初始化决策树分类器
dtc=DecisionTreeClassifier()
#用分割到的训练数据进行模型训练
dtc.fit(X_train,y_train)
#进行预测
y_predict=dtc.predict(X_test)


# In[8]:


print(dtc.score(X_test,y_test))

