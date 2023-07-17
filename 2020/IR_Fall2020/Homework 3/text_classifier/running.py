import re
import warnings
import sklearn.exceptions
import xml.sax.saxutils as saxutils
from nltk.corpus import stopwords
from nltk import word_tokenize
from nltk.stem.porter import PorterStemmer
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.preprocessing import MultiLabelBinarizer
from sklearn.svm import LinearSVC
from sklearn.multiclass import OneVsRestClassifier
from sklearn.naive_bayes import MultinomialNB
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import f1_score, precision_score, recall_score,accuracy_score

import random
warnings.filterwarnings("ignore", category=sklearn.exceptions.UndefinedMetricWarning)
# Set Numpy random seed
random.seed(1000)
cachedStopWords = stopwords.words("english")


# Parse SGML files
#document_train = {}
#document_test = {}
#document_label={}
#documents=[]

def tokenize(text):
    min_length = 3
    words = map(lambda word: word.lower(), word_tokenize(text))
    words = [word for word in words if word not in cachedStopWords]
    tokens = (list(map(lambda token: PorterStemmer().stem(token),words)))
    parm = re.compile('[a-zA-Z]+');
    filtered_tokens = list(filter (lambda token: parm.match(token) and len(token) >= min_length,tokens))
    return filtered_tokens



def represent(document_train, document_test, document_label,documents):
    train_docs_id = list(filter(lambda doc: doc.startswith("train"), documents))
    test_docs_id = list(filter(lambda doc: doc.startswith("test"), documents))
    train_docs = [document_train[doc_id] for doc_id in train_docs_id]
    test_docs = [document_test[doc_id] for doc_id in test_docs_id]
    # Tokenisation
    vectorizer = TfidfVectorizer(tokenizer=tokenize)
    
    # Learn and transform train documents
    vectorised_train_documents = vectorizer.fit_transform(train_docs)
    vectorised_test_documents = vectorizer.transform(test_docs)

    # Transform multilabel labels
    mlb = MultiLabelBinarizer()
    train_labels = mlb.fit_transform([document_label[doc_id] for doc_id in train_docs_id]) 
    test_labels = mlb.transform([document_label[doc_id] for doc_id in test_docs_id])
    
    return (vectorised_train_documents, train_labels, vectorised_test_documents, test_labels)

def svc_train_classifier(train_docs, train_labels):
    classifier = OneVsRestClassifier(LinearSVC(random_state=42))
    #classifier = OneVsRestClassifier(RandomForestClassifier(max_depth=7, random_state=42))
    classifier.fit(train_docs, train_labels)
    return classifier

def lr_train_classifier(train_docs, train_labels):
    classifier = OneVsRestClassifier(LogisticRegression(random_state=42))
    #classifier = OneVsRestClassifier(RandomForestClassifier(max_depth=7, random_state=42))
    classifier.fit(train_docs, train_labels)
    return classifier

def rfc_train_classifier(train_docs, train_labels):
    #classifier = OneVsRestClassifier(LinearSVC(random_state=42))
    classifier = OneVsRestClassifier(RandomForestClassifier(max_depth=5, random_state=42))
    classifier.fit(train_docs, train_labels)
    return classifier

def bayes_train_classifier(train_docs, train_labels):
    #classifier = OneVsRestClassifier(LinearSVC(random_state=42))
    classifier = OneVsRestClassifier(MultinomialNB())
    classifier.fit(train_docs, train_labels)
    return classifier

def knn_train_classifier(train_docs, train_labels):
    #classifier = OneVsRestClassifier(LinearSVC(random_state=42))
    classifier = OneVsRestClassifier(KNeighborsClassifier(n_neighbors=5))
    classifier.fit(train_docs, train_labels)
    return classifier

def evaluate(test_labels, predictions):
    #print ("")
    precision = precision_score(test_labels, predictions, average='micro')
    recall = recall_score(test_labels, predictions, average='micro')
    f1 = f1_score(test_labels, predictions, average='micro')
    accuary = accuracy_score(test_labels, predictions)
    print("Accuary: {:.4f}".format(accuary))
    print("Micro-average quality numbers")
    print("Precision: {:.4f}, Recall: {:.4f}, F1-measure: {:.4f}".format(precision, recall, f1))

    precision = precision_score(test_labels, predictions, average='macro')
    recall = recall_score(test_labels, predictions, average='macro')
    f1 = f1_score(test_labels, predictions, average='macro')
    #accuary = accuracy_score(test_labels, predictions, average='macro')
    print("Macro-average quality numbers")
    print("Precision: {:.4f}, Recall: {:.4f}, F1-measure: {:.4f}".format(precision, recall, f1))

def tcrun(document_train, document_test, document_label, documents):
    train_docs, train_labels, test_docs, test_labels = represent(document_train, document_test, document_label,documents)
    print("\n")
    print("SVC classifier:")
    model = svc_train_classifier(train_docs, train_labels)
    predictions = model.predict(test_docs)
    evaluate(test_labels, predictions)
    print("\n")
    print("RFC classifier:")
    model = rfc_train_classifier(train_docs, train_labels)
    predictions = model.predict(test_docs)
    evaluate(test_labels, predictions)
    print("\n")
    print("Naive Bayes classifier:")
    model = bayes_train_classifier(train_docs, train_labels)
    predictions = model.predict(test_docs)
    evaluate(test_labels, predictions)
    print("\n")
    print("LogisticRegression classifier:")
    model = lr_train_classifier(train_docs, train_labels)
    predictions = model.predict(test_docs)
    evaluate(test_labels, predictions)
    print("\n")
    print("KNN classifier:")
    model = knn_train_classifier(train_docs, train_labels)
    predictions = model.predict(test_docs)
    evaluate(test_labels, predictions)