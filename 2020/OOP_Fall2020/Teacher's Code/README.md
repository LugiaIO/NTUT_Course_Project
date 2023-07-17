# OOP2020f

### [Using Git to download code in class](https://drive.google.com/file/d/15nVKsPkmOzKK-hMLjZKlJrFbbgXGFWkz/view?usp=sharing)

### Grade of [HW00](https://docs.google.com/spreadsheets/d/1oym61SAnom4_WybEaMdRSqe82KYdLEICk-l2Tho9jOY/edit?usp=sharing)、[HW01&02](https://docs.google.com/spreadsheets/d/1Mz8H0tFF3Esn7XK-KPowslee1sf0aSnMKzqrjo66iTo/edit?usp=sharing)、[HW03](https://docs.google.com/spreadsheets/d/1x6VKXEVuh084mh2kiqOPh0TP_TSD9oMwlrOyfgpOQR4/edit?usp=sharing)、[Midterm](https://docs.google.com/spreadsheets/d/1Qm5m_47yu6gJdRKQll1A3N4pBdPKfr0UrLkQOY5HUfQ/edit?usp=sharing)、[HW04](https://docs.google.com/spreadsheets/d/1chLAXbK__L5shraIXFiXXDrZwI3FKI4m7mE16HHJRDE/edit?usp=sharing)

If you have any questions, please contact TA.
 <!--

---

### Week 18 - 1/11

### Week 18 - 1/14

---

### Week 17 - 1/4

### Week 17 - 1/8

---

### Week 16 - 12/28

### Week 16 - 1/1 (No Class)

---

### Week 15 - 12/21

### Week 15 - 12/25

---

### Week 14 - 12/18

### Week 14 - 12/14

-->
---

### Week 13 - 12/11

TBD

### Week 13 - 12/7

Topic: Friend Class

Suggest Reading: Page 372 - 377 & Page 810 - 813

1. Read the book ! Today's code does not work. What is friend class? Is there a thing called friend function? Please tell me what to do in next class.

2. I forget to mention makefile in today's calss. Let's rewrite it on Friday.

---

### Week 12 - 12/4 - Classroom changed to 億光 628

Topic: Bubble Sort with STL containers

Suggest Reading: Page 737 - 740

Summary II

- Convex Polygon -> representation and computation
    - Perimeter of rectangle
    - Area of rectangle
    - Take care of out-of-order vertices 
        - std::sort
        - Dafault operator of std::sort is <
        - greaterThan() as Pointer to function
        - [function template](http://www.cplusplus.com/doc/oldtutorial/templates/)
        - Sorting vertices with a Compare object
        - overloading function call operator in a Compare objects
- Factory: an object that creates other objects
    - createPolygon: sort vertices, and then create polygon

1. [HW05](https://css-gitlab.csie.ntut.edu.tw/qoolili/oop2020f_hw) is released. Due: 23:59, 14 December 2020 (System will be reopen on 7 December 12:00)

### Week 12 - 11/30

Topic: Sorting vertices with std::sort & Static method

Suggest Reading: Code in class 

---

### Week 11 - 11/27

Topic: Sorting vertices with std::sort & Static method

Suggest Reading: Code in class & Page 342 - 347 & Page 896 - 903

1. HW05 is going to release during next week. Please finish and upload HW04 before noon of 11/28

### Week 11 - 11/23

Topic: Area of rectangle & test Polygon::area() & test mathVector::getArea(mathVector inputA, mathVector inputB)

Suggest Reading: Code in class

---

### Week 10 - 11/20

Topic: [Convex Polygon](http://htsicpp.blogspot.com/2014/10/convex-polygon.html) -> representation and computation & Perimeter of rectangle

Suggest Reading: Code in class

1. HW04 is released. **[Link](https://css-gitlab.csie.ntut.edu.tw/qoolili/oop2020f_hw)**

2. If you want to see your exam sheet, please see TA during the office hour on 11/24. (Only on this date)

3. Test cases used in Midterm is released. **[Link](https://css-gitlab.csie.ntut.edu.tw/qoolili/oop2020f_hw)** 

4. 期中預警 have been announcement through school system.

### Week 10 - 11/16 

Topic: Member functions of static class paramaters shuold also be static & Test fixture

Suggest Reading: Code in class

1. Grade of both computer-based midterm is released.

---

### Week 9 - 11/9、11/13 

Midterm Week - No class

---

### Week 8 - 11/6

Topic: Math Vector Continued & Overloadding operator & functions

Suggest Reading: Code in class & Ch 8

1. Please follow this **[list](https://docs.google.com/spreadsheets/d/1yMNXDzxKSTjtdzo3QeRY3kzmTTbuuBodPv4kIkIgcYg/edit?usp=sharing)** for your classroom for taking the test.

2. Hand-written Midterm on 11/9 15:10 - 16:00. Go to your assigned classroom directly 六教 327 & 宏裕科技大樓 1222. No material is allowed.

3. Computer-based Midterm on 11/12 18:00 - 21:00. Please be in the classroom half hour earlier to prepare the git environment. Go to your assigned classroom directly 宏裕科技大樓 1223 & 宏裕科技大樓 1222. You can refer to code in class & HW & slides & hand-written notes & Cplusplus.com, but NO text book.

4. Code in today's class is runnable now. Please pay attention to the condition of using & (Reference) and operator overloadding.

5. Answer to HW01 & 03 has been released. **[Link](https://css-gitlab.csie.ntut.edu.tw/qoolili/oop2020f_hw)**

### Week 8 - 11/2

Topic: Math Vector Continued

Suggest Reading: Code in class & Ch 8

Summary I

- MathVector, continued
    - other operations: add, scalar multiplication, subtract, angle between two vectors, etc.
        - returning a value
    - copy assignments:
        - returning a reference
        - u = v;
        - u = v = w;
- When you find a bug:
    - write a test that fails due to the bug
    - fix the bug
    - compile and run the test
    - repeat until tests pass
- deep copy constructor: when an object allocates memory from heap upon constructor call, make sure to
    - provide its own copy constructor,
    - provide destructor,
    - provide copy assignment (operatro =)
-  Refactoring: we extracted the private function MathVector::initialize(double * a, int dim) which is used in two constructors and copy assignment. The act is called "refactoring" (Extract Function in this case) that meets three conditions:
    - not changing external behavior of the changed methods, the constructors and copy assignments
    - changing the internal structure: in this case, removed duplicated code in the member functions into a private member function (the initialize)
    - there unit tests that checked on the affected code. The tests must be passing before/after the change
    - reference: [Extract Method](https://refactoring.com/catalog/extractFunction.html)

---

### Week 7 - 10/30

Topic: Math Vector Continued

Suggest Reading: Code in class & Ch 8

1. **[HW03](https://css-gitlab.csie.ntut.edu.tw/qoolili/oop2020f_hw) is released.**

---

### Week 7 - 10/26

Topic: Copy Assignment & Assignment Operator

Suggest Reading: Code in class & Ch 14 Pages 670 - 671 

---

### Week 6 - 10/23

Topic: Copy Consuctor & constant label & getter() & setter() & memory model

Suggest Reading: Code in class & Ch 10 Pages 494 - 498 

1. Due to power outage during the weekend. Late submission of HW01 & HW02 are extended until 10/27 23:59 with 30% off in your grade. Please see the TA and this [HW02 Common Issues](https://drive.google.com/file/d/1PzYrAhNfrsUtkMvca7VIa7qB8TUSsztZ/view?usp=sharing).

---

### Week 6 - 10/19

Topic: The Vector Example & Consuctor & sizeof() function

Suggest Reading: Code in class & Chapter 7.1

---

### Week 5 - 10/16

Topic: The Vector Example & The structure of a class

Suggest Reading: Code in class & Chapter 6.2

1. Late submission of HW01 & HW02 are allowed until next Sunday 10/25 23:59 with 30% off in your grade. I am not trying to daunt you guys. Please see TA during next week to resolve your problem. 

---

### Week 5 - 10/12

Topic: Writing Test cases for Exception Handling

Suggest Reading: Code in class & [Solving the vector with OOP](http://htsicpp.blogspot.com/2014/09/inner-product-round-4-refactoring-into.html)

---

### Week 4 - 10/5

Topic: Exception Handling with the stdexpect

Suggest Reading: [Slides](https://drive.google.com/file/d/1MaJ9gdgixycSDUTSjNYt9doWm9RpUBPD/view?usp=sharing)、[Homework02](https://drive.google.com/file/d/1mco0gHi8DFRh5bFkBMtk0KHsPeiP2zr5/view?usp=sharing)、[HW02 Common Issues](https://drive.google.com/file/d/1PzYrAhNfrsUtkMvca7VIa7qB8TUSsztZ/view?usp=sharing)

HW02 will guide you through the submission process of HW01. If you can trigger automation tests on Jenkins Website, you can get 100 points for HW02. The Junkins website will be ready on 10/6 evening (Email will be sent out for notification).

Due to the delay of Junkins website, HW01 will will due on 10/13 23:59 (Extended).

**Two correction for HW01 & HW02**

(1) Use **ut_all** (not ut_main) as the name of the output runnable of the un_main.cpp

(2) The project name on gitlab shuold be **OOP2020f_HW_你的學號**

(3) *Automated Unit Test is now live.* Please upload your HW01 with methods mentioned in HW02. [**Link**](https://css-lab.csie.ntut.edu.tw). Username and Password is yout student ID.

---

### Week 3 - 9/28

Topic: Let’s Look Back before HW01

Suggest Reading: [Slides](https://drive.google.com/file/d/1MaJ9gdgixycSDUTSjNYt9doWm9RpUBPD/view?usp=sharing)、[Homework01](https://drive.google.com/file/d/1xSLfM8yBTvxpCLbAPdPXTu4VguM4iI7O/view?usp=sharing)

HW01 will be released tonight and the deadline is 10/13 23:59 (Extended). You will need to submit your code through gitlab. Method to submit your code will be released in next class.

**You can discuss with your friends, but do not copy. You will fail the course if you copy others homework.**

---

### Week 2 - 9/25

Topic: Google test & Using Git & Makefile

Suggest Reading: Chapter 5 & Chapter 18 & [Makefile](https://drive.google.com/file/d/19zdgML8V6lMEUTyYAV2RNKHWhjmaBSPD/view?usp=sharing)

1. Please see slides on 9/21 for updated content discussed in today's class.

2. We learned how to write **ranged-based for loop**.

3. We learned how to write **makefile**, how to use **google test**, and **ecpetion handling**.

**Please download the code and try to rewrite the makefile for generating the google test executable.**

---

### Week 2 - 9/21

Topic: Functions & Unit test

Suggest Reading: Chapter 3 & [Slides](https://drive.google.com/file/d/1FsORmHkuIi2584_iUdDthnJW3BNKsZ_P/view?usp=sharing)

We learned how to write a function, basic ideas of unit test, and how to write unit test.

---

### Week 1 - 9/18

Topic: Flow of Control & Console I/O & Namespace & Simple File I/O & String Class

Suggest Reading: Chapter 1 & Chapter 2 & [Slides](https://drive.google.com/file/d/1eSyluBFkhxsWmvcFG3ujPYNRYERwNd2u/view?usp=sharing)

1. We have demonstrated how to use **namespace** and you can find code in this gitlab project.

2. Simple **file I/O** have also be prtaciced in the class.

3. We have **partially** solved the problem of counting the number of continuous uppercase letters substring in a larger string.

---

### Week 1 - 9/14

Topic: Couse Information and Introduction

Suggest Reading: [Slides](https://drive.google.com/file/d/1BqgqIQE8hsiwbSdzkUCOaRgkiqXlNdcT/view)  

1. Slides can be found on i-learning (北科i學園).

- 教科書 Absolute C++ 6/e
- 參考書 Problem Solving with C++: Global Edition, 10th Edition

2. Garding policy

- Assignment: 40 %
- Midterm Exam: 30 %
- Final Exams: 30 %

3. Exam Timetable

|  Exam  | 1 hour Hand Written | 3 hours Computer Based |
| ------ | ------ | ------ |
| Midterm | 11/9 15:10 - 16:00 | 11/12 18:00 - 21:00 | 
| Final | 1/11 15:10 - 16:00 | 1/15 18:00 - 21:00 | 

If you need me to sign a letter for leaving other class, please send me an email. [shchen@ntut.edu.tw](shchen@ntut.edu.tw)

4. [Homework00](https://drive.google.com/file/d/11L8Z9mC5d-ZXTpdr1MtLFMLAiNUDwiOZ/view?usp=sharing) and [Report Template](https://drive.google.com/file/d/15lfq2M7T-r4SaArk-5YpLaqrBHG9O_yh/view?usp=sharing) need to be submitted through the Homework area of i-learning (北科i學園). The deadline is 2020/09/21 23:59. 

5. The office hour information are listed as below.

| | Teacher | Assistant |
| ------ | ------ | ------ |
| | Shuo-Han Chen (陳碩漢) | 蘇新允 |
| Office | 宏裕科技大樓 1532 | 宏裕科技大樓 438 |
| Office Hours | Monday 11:00 - 15:00 | Tuesday 15:00 - 17:00 |
| Email | shchen@ntut.edu.tw | t109598088@ntut.edu.tw |

---