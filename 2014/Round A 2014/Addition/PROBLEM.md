Problem
=======
Six years ago, a robot, Bob, with infant's intelligence has been invented by an evil scientist, Alice.

Now the robot is six years old and studies in primary school. Addition is the first operation he learned in math. Due to his strong reasoning ability, he could now conclude a+b=12 from a=2 and b=10.

Alice wanted to test Bob's addition skills. Some equations were given to Bob in form of a=2, b=10, c=4, and Bob has to find out the answers of questions like a+b, a+c, etc.

Alice checked Bob's answers one by one in the test papers, and no mistake has been found so far, but Alice lost the given equations after a cup of coffee poured on them. However she has some of Bob's correct answers, e.g. a+b=12, a+c=6, c+d=5. She wants to continue with the checkable equations, e.g. b+d=11 could be concluded by a+b=12, a+c=6, c+d=5, and thus the question b+d is checkable.

To prevent the artificial intelligence technology from being under the control of Alice, you disguised yourself as her assistant. Now Alice wants you to figure out which of the rest of questions are checkable and their answers.

Input
=====
The first line of the input gives the number of test cases, **T**. **T** test cases follow.

The first line of each test case contains a single integer **N**: the number of correctly answered questions. Each of the next **N** lines contain one correctly answered question in the form "**x+y=z**", where **x** and **y** are names of variables and **z** is a decimal integer.

The next line contains a single integer Q: the number of remaining questions. Each of the next Q lines contain one question in the form "x+y", where x and y are names of variables.

Output
======
For each test case, the first line of output contains "Case #**x**:", where **x** is the test case number (starting from 1). For each question in the input that was checkable, output a single line with the answer in the form "**x+y=z**", where **x** and **y** are names of variables and **z** is a decimal integer. Questions should be listed in the same order as they were given in the input. Please do **NOT** ignore duplicated questions, since Alice would fire you if you pointed any mistake of hers.

Limits
======
Time limit: 30 seconds per test set.<br />
Memory limit: 1GB.

Names of variables are strings of lowercase English letters. Each name contains at most 10 characters.<br />
-200000 ≤ **z** ≤ 200000<br />
There is no contradiction in the answered questions and if the answer is checkable, the result is an integer.

Small dataset (Test set 1 - Visible)
====================================
1 ≤ **T** ≤ 10<br />
1 ≤ **N** ≤ 10<br />
1 ≤ **Q** ≤ 10

Large dataset (Test set 2 - Hidden)
===================================
1 ≤ **T** ≤ 3<br />
1 ≤ **N** ≤ 5000<br />
1 ≤ **Q** ≤ 5000

Sample
======
Sample Input
------------
```
2
2
apple+banana=10
coconut+coconut=12
5
apple+banana
apple+banana
apple+apple
banana+apple
peach+apple
3
a+b=3
b+c=3
c+d=3
4
a+c
a+d
b+c
b+d
```
Sample Output
-------------
```
Case #1:
apple+banana=10
apple+banana=10
banana+apple=10
Case #2:
a+d=3
b+c=3
```