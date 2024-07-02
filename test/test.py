# 数据处理

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt  
import seaborn as sns
from sklearn.model_selection import train_test_split,cross_val_score
from sklearn.ensemble import RandomForestClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn import svm
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
from sklearn import metrics 
# 导入数据
pd.set_option('display.max_columns',None)
pd.set_option('display.max_rows',None)

data_train = pd.read_csv("pfm_train.csv")
# 训练集总共1100条数据

# 删除常量

data_train.drop('EmployeeNumber',axis=1) # 每个人都是唯一的
data_train.drop('Over18',axis=1)  # 全是同样的值
data_train.drop('StandardHours',axis=1) # 都是一样的值
# 添加测试集
test = pd.read_csv('pfm_test.csv')

#和训练集一样的处理
test.drop('EmployeeNumber',axis=1)
test.drop('Over18',axis=1) 
test.drop('StandardHours',axis=1)

# 数据处理

## 1. 字符型变量数值化

# 筛选出字符型的变量
col = data_train.select_dtypes(include=['object']).columns.tolist()

from sklearn.preprocessing import OrdinalEncoder
# 创建一个OrdinalEncoder实例  
encoder = OrdinalEncoder()  
# 将DataFrame的列子集转换为二维数组  
col_data = data_train[col].values  
# 拟合编码器并转换数据  
col_data_encoded = encoder.fit_transform(col_data)  
# 将编码后的数据转换回DataFrame，并替换原始列  
data_train[col] = pd.DataFrame(col_data_encoded, columns=col)  
# 同样处理test
col_data = test[col].values
col_data_encoded = encoder.fit_transform(col_data)
test[col] = pd.DataFrame(col_data_encoded, columns=col)
test[col].head()
 

## 2.独热编码

X = data_train.loc[:,data_train.columns!='Attrition']  # 从DataFrame中取出的除了'Attrition'列以外的所有列，作为特征
Y = data_train.loc[:,'Attrition'] # 取出'Attrition'列作为目标变量
X_test = test.loc[:,:] #test中没有attrition

# 删除不需要进行独热编码的连续数值型值
X_onehot = X.drop(['Age','NumCompaniesWorked','PercentSalaryHike','TotalWorkingYears','YearsAtCompany','YearsInCurrentRole',  
'YearsSinceLastPromotion', 'YearsWithCurrManager'],axis=1)
X_test_onehot = X_test.drop(['Age','NumCompaniesWorked','PercentSalaryHike','TotalWorkingYears','YearsAtCompany','YearsInCurrentRole',  
'YearsSinceLastPromotion', 'YearsWithCurrManager'],axis=1)

from sklearn.preprocessing import OneHotEncoder
encoder = OneHotEncoder(sparse_output=False, handle_unknown='ignore')  # 忽略测试集中但不在训练集中的类别
X_onehot = encoder.fit_transform(X_onehot)  
# 对测试集进行独热编码，使用相同的 encoder 对象  
X_test_onehot = encoder.transform(X_test_onehot)

X_other = X.loc[:,['Age','NumCompaniesWorked','PercentSalaryHike','TotalWorkingYears','YearsAtCompany','YearsInCurrentRole',  
'YearsSinceLastPromotion', 'YearsWithCurrManager']]
X_test_other = X_test.loc[:,['Age','NumCompaniesWorked','PercentSalaryHike','TotalWorkingYears','YearsAtCompany','YearsInCurrentRole',  
'YearsSinceLastPromotion', 'YearsWithCurrManager']]

# 合并
X = pd.concat([pd.DataFrame(X_onehot),X_other],axis=1)
X_test = pd.concat([pd.DataFrame(X_test_onehot),X_test_other],axis=1)

# 将列名改为字符类型
X.columns = X.columns.astype(str)
X_test.columns = X_test.columns.astype(str)

# 模型学习

## 1.划分训练集和验证集

from sklearn.model_selection import train_test_split
#测试集将占整个数据集的20%。剩下的80%将用作训练集
Xtrain,Xtest,Ytrain,Ytest = train_test_split(X,Y,test_size=0.2,random_state=42) 
Xtrain.shape

## 2.基于信息增益的决策树

### 2.1 模型训练

from sklearn.model_selection import train_test_split  
from sklearn.tree import DecisionTreeClassifier  
from sklearn.metrics import accuracy_score  

# 创建决策树分类器实例，使用默认参数，即信息增益作为特征选择标准 
clf = DecisionTreeClassifier(random_state=42)  # random_state用于可重复性  

# 训练模型  
clf.fit(Xtrain, Ytrain)  

# 预测测试集
y_pred = clf.predict(Xtest)  

### 2.2 评估模型性能

# 使用准确率
accuracy = accuracy_score(Ytest, y_pred)  
print(f"Accuracy: {accuracy}")  

### 2.3 模型预测

# 使用模型进行预测  
y_pred = clf.predict(X_test) 
print(y_pred)

## 3.基于基尼指数的决策树

### 3.1 模型训练

# 创建决策树分类器实例，并指定使用基尼指数作为划分标准  
clf = DecisionTreeClassifier(criterion='gini', random_state=42)   

# 训练模型  
clf.fit(Xtrain, Ytrain)

# 预测测试集  
y_pred = clf.predict(Xtest) 

### 3.2 评估模型性能

accuracy = accuracy_score(Ytest, y_pred)  
print(f"Accuracy: {accuracy}")  

### 3.3 模型预测

# 使用模型进行预测  
y_pred = clf.predict(X_test) 
print(y_pred)

## 4.朴素贝叶斯模型

### 4.1 模型训练

from sklearn.model_selection import train_test_split  
from sklearn.naive_bayes import GaussianNB
from sklearn.naive_bayes import BernoulliNB
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import accuracy_score

# 创建朴素贝叶斯分类器实例  
clf = MultinomialNB()  

# 使用训练数据拟合模型  
clf.fit(Xtrain, Ytrain)  

# 使用测试数据进行预测  
y_pred = clf.predict(Xtest)

### 4.2 评估模型性能

accuracy = accuracy_score(Ytest, y_pred)  
print(f"Accuracy: {accuracy}") 

### 4.3 模型预测

# 使用模型进行预测  
y_pred = clf.predict(X_test) 
print(y_pred)

## 5.支持向量机模型

### 5.1 模型训练

from sklearn import svm    
from sklearn.metrics import classification_report, confusion_matrix

clf = svm.SVC(kernel='linear', C=1.0, random_state=42) 

clf.fit(Xtrain, Ytrain)  

Ypred = clf.predict(Xtest)

### 5.2 评估模型性能

print("混淆矩阵:")  
print(confusion_matrix(Ytest, Ypred))    
print("分类报告:")  
print(classification_report(Ytest, Ypred)) 

### 5.3 模型预测

# 使用模型进行预测  
y_pred = clf.predict(X_test) 
print(y_pred)