<p align="center"><b>Name :</b> Gaurang Tyagi</p>
<p align="center"><b>Roll No :</b> 16</p>
<p align="center"><b>Subject :</b> Artificial Intelligence & Machine Learning</p>

<div style="page-break-after: always;"></div>

<h1 align="center">Table of Contents</h1>


|                         Section                         | Page Number |
| :------------------------------------------------------: | -------------- |
|                [Introduction](#introduction)                | 2           |
|           [Problem Statement](#problem-statement)           | 2           |
|         [Dataset Description](#dataset-description)         | 2           |
|      [Naive Bayes Classifier](#naive-bayes-classifier)      | 2-3         |
| [System Architecture Diagram](#system-architecture-diagram) | 3-5         |
|      [Performance Evaluation](#performance-evaluation)      | 5-6         |
|                  [Conclusion](#conclusion)                  | 6           |

<div style="page-break-after: always;"></div>

---

# Introduction

In this assignment, an intelligent disease diagnosis system is designed using a machine learning approach. The system takes a set of symptoms as input and predicts the most probable disease as output. A Naive Bayes classifier is used for the prediction due to its simplicity, efficiency, and effectiveness in handling categorical medical data. The system architecture, working mechanism, and evaluation metrics used to measure the performance of the model are discussed in the following sections.

# Problem Statement

Design an Intelligent System for Disease Diagnosis, given a set of symptoms and diagnosis.

# Dataset Description

#### Health Symptoms and Disease Prediction Dataset

> description

  This dataset is a comprehensive collection of health-related symptoms mapped to potential diseases. It is designed to aid in building machine learning models for disease prediction based on symptoms, supporting health research, diagnostics, and application development.

> Features

  **Symptoms Columns:**
    Contains multiple columns representing various symptoms such as itching, headache, vomiting, and more. Each symptom is recorded as 1 (present) or 0 (absent).
  <br>
  <br>
  **Prognosis Column:**
    Represents the predicted disease based on the combination of symptoms.
    Includes common diseases like Malaria, Dengue, Diabetes, Pneumonia, and more.
  <br>
  <br>
  **Medicine Column:**
    Provides suggested medicines for each disease, helping connect predictions to actionable medical advice.
    Potential Uses

> Source

[Health Symptoms and Disease Prediction Dataset](https://www.kaggle.com/datasets/devikshah/health-symptoms-and-disease-prediction-dataset?select=training.csv)

# Naive Bayes Classifier

Naive Bayes Classifier is based on the bayes theorem which states that:

$$
P(\frac{h}{E}) = \frac{P(h)\times P(\frac{E}{h})}{P(E)}
$$

```
where,
  h is a hypothesis such that h E H (H is the set of all the hypothesis)
  E is the set of attributes
  P(h) is the prior probability of hypothesis h
  P(E) is the evidence
  P(e/h) is the likelihood
  P(h/E) is the posterior probability
```

A Naive Bayes classifier estimates the class-conditional probability by assuming
that the attributes are conditionally independent, given the class label h. i.e,

$$
P(\frac{E}{H=h}) = \prod_{i=1}^dP(\frac{E^i}{H=h})
$$

```
where,
d is the number of attributes in the dataset

```

To classify a test record, the naıve Bayes classifier computes the posterior
probability for each class h. i.e,

$$
P(\frac{h}{E}) = P(h)\times \prod_{i=1}^dP(\frac{E^i}{H=h})
$$

for minimum error, the Bayes' classifier chooses the hypothesis with
the highest posterior probability.

I chose Naive Bayes classifier for the following reasons:

1. It classifies based on prior evidence which is helpfull when dealing with diagnosis data.
2. It is simple and efficient for handling categorical data.
3. It handles high dimensional data efficiently (provided the attributes are conditionally independent).
4. It is suitable for multiclass-classification (required in this dataset)

# System Architecture Diagram

### Training System

![1775153790771](image/theory/1775153790771.png)

#### **Disease Dataset**

- This step loads the dataset into memory.
- Additional information about the dataset

```
      Number of features (symptoms) : 136
      Number of unique prognosis (diseases) : 43
      Number of instances : 4924  
```

#### **Preprocessing**

  This step does the following :
  <br>
    1. Separates the dataset into features (symptoms) and class label (prognosis/disease).
  <br>
    2. Checks the dataset for missing or invalid prognosis values.
  <br>
    3. If missing values are found, the corresponding instances are removed from the dataset.
  <br>
    4. Encodes the symptoms into numerical values (e.g., 0 for absence and 1 for presence) so that they can be processed by the machine learning model.

#### **Training Phase**

  This step does the following :
  <br>
    1. Calculates the prior probability of each disease in the dataset.
  <br>
    2. Calculates the likelihood probability of each symptom given a particular disease using the Naive Bayes assumption.

#### **Naive Bayes Classifier**

  Now, the model is ready to take new patient's symptoms and input,
  use these probabilities to predict the prognosis

### Prediction System

![1775136993564](image/theory/1775136993564.png)

#### **Input**

The system receives a set of symptoms from a new patient.
Each symptom is represented as a feature (e.g., 1 for presence and 0 for absence).
These symptoms are provided to the trained Naive Bayes classifier to estimate the probability of each possible disease.

#### **Model**

The Naive Bayes classifier assumes that symptoms are conditionally independent given the disease.
This simplifies the joint probability calculation and allows efficient computation.

The model calculates the posterior probability of each disease using the Naive Bayes formula:

$$
P(\frac{H=prognosis_i}{S=Set\ of patient's\ symptoms}) = P(H=prognosis_i)\times \prod_{j=1}^dP(\frac{S_j}{H=prognosis_i})
$$

```
where,

- **H** represents the *hypothesis (disease/prognosis)*  
- **S_j** represents the *j-th symptom*  
- **P(H)** is the *prior probability of the disease*  
- **P(S_j | H)** is the *likelihood of observing symptom S_j given the disease*  
- **d** is the *total number of symptoms*

```

#### **Output**

The predicted disease is chosen using the following decision rule:

$$
\hat{H} = \arg\max_{i} P(H = prognosis_i) \prod_{j=1}^{d} P(S_j \mid H = prognosis_i)
$$

# Performance Evaluation

The performance of the disease diagnosis system is evaluated using standard classification metrics such as **accuracy, precision, recall, and F1-score**. These metrics help measure how well the Naive Bayes classifier predicts diseases based on patient symptoms.

The original dataset was divide into training and test dataset to induce the model on training dataset and measure the performance on test dataset.

> training dataset size: 3939 instances
<br>

> test dataset size : 985 instances

```
accuracy : 0.9695431472081218
precision : 0.9594633792603335
recall : 0.9695431472081218
f1_score : 0.9617958050771294
```


### Accuracy

Accuracy measures the proportion of correct predictions made by the model out of all predictions.

$$
Accuracy = \frac{TP + TN}{TP + TN + FP + FN}
$$

The model achieved an **accuracy of 0.9695 (96.95%)**, indicating that most disease predictions were correct.

---

### Precision

Precision measures how many of the predicted disease cases were actually correct.

$$
Precision = \frac{TP}{TP + FP}
$$

The model achieved a **precision of 0.9594 (95.94%)**, which indicates that most predicted diseases were accurate.

---

### Recall

Recall measures the ability of the model to correctly identify actual disease cases.

$$
Recall = \frac{TP}{TP + FN}
$$

The model achieved a **recall of 0.9695 (96.95%)**, showing that it successfully identifies most true disease cases.

---

### F1 Score

The F1-score is the harmonic mean of precision and recall and provides a balanced evaluation of the classifier.

$$
F1 = 2 \times \frac{Precision \times Recall}{Precision + Recall}
$$

The model achieved an **F1-score of 0.9618 (96.18%)**, indicating strong overall classification performance.

---

# Conclusion

The evaluation results show that the Naive Bayes classifier performs very well on the symptom–disease dataset. High accuracy, precision, recall, and F1-score indicate that the model is capable of predicting diseases effectively based on patient symptoms. Therefore, the proposed intelligent disease diagnosis system is efficient and reliable for assisting medical diagnosis.
