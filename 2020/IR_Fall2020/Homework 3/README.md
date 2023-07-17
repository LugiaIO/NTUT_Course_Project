# 2020_Fall_IR_HW3
This is the third assignment in the Informaiton Retrieval and Applications. 

HW#3 : Text Classification

Classifier: SVC RFC Naive Bayes LogisticRegression KNN
## Enviroment Settings
Python 3.8

Required packages: sklearn nltk xml warnings re BeautifulSoup 

## Input
`python3 main.py`

## Output
```python
SVC classifier:
Accuary: 0.7124
Micro-average quality numbers
Precision: 0.9276, Recall: 0.6501, F1-measure: 0.7644
Macro-average quality numbers
Precision: 0.5177, Recall: 0.2701, F1-measure: 0.3307


RFC classifier:
Accuary: 0.0651
Micro-average quality numbers
Precision: 1.0000, Recall: 0.0385, F1-measure: 0.0741
Macro-average quality numbers
Precision: 0.0348, Recall: 0.0023, F1-measure: 0.0039


Naive Bayes classifier:
Accuary: 0.3375
Micro-average quality numbers
Precision: 0.9838, Recall: 0.2350, F1-measure: 0.3794
Macro-average quality numbers
Precision: 0.0751, Recall: 0.0189, F1-measure: 0.0253


LogisticRegression classifier:
Accuary: 0.6038
Micro-average quality numbers
Precision: 0.9531, Recall: 0.5244, F1-measure: 0.6765
Macro-average quality numbers
Precision: 0.3162, Recall: 0.1135, F1-measure: 0.1496


KNN classifier:
Accuary: 0.5953
Micro-average quality numbers
Precision: 0.7146, Recall: 0.6092, F1-measure: 0.6577
Macro-average quality numbers
Precision: 0.3930, Recall: 0.2910, F1-measure: 0.3044
```

## ModApte Split
 VIII.B. The Modified Apte ("ModApte") Split :

Training Set (9,603 docs): LEWISSPLIT="TRAIN";  TOPICS="YES"
 Test Set (3,299 docs): LEWISSPLIT="TEST"; TOPICS="YES"
 Unused (8,676 docs):   LEWISSPLIT="NOT-USED"; TOPICS="YES"
                     or TOPICS="NO" 
                     or TOPICS="BYPASS"

This replaces the 10645/3672 split (7,856 not used) of the
Reuters-22173 collection.  These are our best approximation to the
training and test splits used in APTE94 and APTE94b. Note the
following:

      1. As with the ModLewis, those documents removed in forming
Reuters-21578 are not present, and BYPASS documents are not used.  
      2. The intent in APTE94 and APTE94b was to use the Lewis split,
but restrict it to documents with at least one TOPICS categories.
However, but it was not clear exactly what Apte, et al meant by having
at least one TOPICS category (e.g. how was "bypass" treated, whether
this was before or after any fixing of typographical errors, etc.). We
have encoded our interpretation in the TOPICS attribute.  ***Note
that, as discussed above, some TOPICS="YES" stories have no TOPICS
categories, and a few TOPICS="NO" stories have TOPICS
categories. These facts are irrelevant to the definition of the
split.*** If you are using a learning algorithm that requires each
training document to have at least TOPICS category, you can screen out
the training documents with no TOPICS categories. Please do NOT screen
out any of the 3,299 documents - that will make your results
incomparable with other studies.

      3. As with ModLewis, it may be desirable to use the 8,676 Unused
documents for gathering statistical information about feature
distribution.

As with ModLewis, this split assigns documents from April 7, 1987 and
before to the training set, and documents from April 8, 1987 and after
to the test set.  The difference is that only documents with at least
one TOPICS category are used.  The rationale for this restriction is
that while some documents lack TOPICS categories because no TOPICS
apply (i.e. the document is a true negative example for all TOPICS
categories), it appears that others simply were never assigned TOPICS
categories by the indexers. (Unfortunately, the amount of time that
has passed since the collection was created has made it difficult to
establish exactly what went on during the indexing.)

WARNING: Given the many changes in going from Reuters-22173 to
Reuters-21578, including correction of many typographical errors in
category labels, results on the ModApte split cannot be compared
with any published results on the Reuters-22173 collection!

