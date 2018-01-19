
# coding: utf-8

# In[ ]:


# from sklearn.datasets import load_digits
digits=load_digits()
#检视数据规模和特征维度
digits.data.shape


# In[2]:


from sklearn.cross_validation import train_test_split


# In[3]:


X_train,X_test,y_train,y_test=train_test_split(digits.data,digits.target,test_size=0.25,random_state=33)

#检视训练和测试数据规模
y_train.shape


# In[4]:


y_test.shape


# In[6]:


from sklearn.preprocessing import StandardScaler
#引入基于线性假设的支持向量机分类器LinearSVC
from sklearn.svm import LinearSVC

ss=StandardScaler()
X_train=ss.fit_transform(X_train)
X_test=ss.transform(X_test)

lsvc=LinearSVC()

lsvc.fit(X_train,y_train)

y_predict=lsvc.predict(X_test)


# In[7]:


print('正确率：',lsvc.score(X_test,y_test))


# In[8]:


from sklearn.metrics import classification_report
print(classification_report(y_test,y_predict,target_names=digits.target_names.astype(str)))

