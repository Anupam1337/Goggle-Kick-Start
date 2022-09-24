Problem
-------
A fabric is represented by three properties:

Color (**C**), a string consisting of lowercase letters of the English alphabet, representing the color of the fabric.
Durability (**D**), an integer representing the durability of the fabric.
Unique identifier (**U**), an integer representing the ID of the fabric.
Ada and Charles work at the Kick Start fabric factory. Each day they receive **N** fabrics, and one of them has to sort it. They sort it using the following criteria:

Ada sorts in lexicographically increasing order by color (**C**).
Charles sorts in ascending order by durability (**D**).
They break ties by sorting in ascending order by the unique identifier (**U**).
Given **N** fabrics, count the number of fabrics which end up in the same position regardless of whether Ada or Charles sort them.

Input
-----
The first line of the input gives the number of test cases, **T**. **T** test cases follow.
Each test case begins with one line consisting of an integer **N** denoting the number of fabrics. Then **N** lines follow, each line with a string **C<sub>i></sub>**, an integer **D<sub>i</sub>**, and an integer **U<sub>i</sub>**: the color, the durability and the unique identifier of the i-th fabric respectively.

Output
------
For each test case, output one line containing <i>Case #x: y</i>, where x is the test case number (starting from 1) and <i>y</i> is the number of fabrics which end up in the same position regardless of whether a worker sorts them by color or by durability

Limits
------
| Time limit: 20 seconds.
| Memory limit: 1 GB.
| 1 ≤ **T** ≤ 100.
| 1 ≤ length of string **C<sub>i</sub>** ≤ 10.
| String **C<sub>i</sub>** consists of only lowercase letters of the English alphabet.
| No two fabrics have same **U<sub>i</sub>**.

Test set 1 - Visible
~~~~~~~~~~~~~~~~~~~~
1 ≤ **N** ≤ 2.
1 ≤ **D<sub>i</sub>** ≤ 2.
1 ≤ **U<sub>i</sub>** ≤ 2.

Test set 2 - Hidden
~~~~~~~~~~~~~~~~~~~
1 ≤ **N** ≤ 10<sup>3</sup>.
1 ≤ **D<sub>i</sub>** ≤ 10<sup>2</sup>.
1 ≤ **U<sub>i</sub>** ≤ 10<sup>3</sup>.

Sample
------

```
    Sample Input            Sample Output
    3
    2
    blue 2 1
    yellow 1 2              Case #1: 0
    2
    blue 2 1
    brown 2 2               Case #2: 2
    1
    red 1 1                 Case #2: 1
```

In Sample Case #1, when sorted by color, the order of fabrics represented by the unique identifier is 1 and 2. When sorted by durability, the order of fabrics is 2 and 1. Therefore, 0 fabrics have the same position when sorted by color or durability.

In Sample Case #2, when sorted by color, the order of fabrics represented by the unique identifier is 1 and 2. When sorted by durability, the order of fabrics is also 1 and 2. Therefore, 2 fabrics have the same position. Notice that both fabrics have the same durability, so when Charles sorts them he decides that fabric 1 comes first because it has a smaller identifier.

In Sample Case #3, since there is only 1 fabric, the position remains the same whether the fabrics are sorted by color or durability.

Additional Sample - Test Set 2
The following additional sample fits the limits of Test Set 2. It will not be run against your submitted solutions.

```
    Sample Input            Sample Output
    1
    5
    blue 1 2
    green 1 4
    orange 2 5
    red 3 6
    yellow 3 7              Case #1: 5

In Sample Case #1, the order is the same for both when sorted by color or durability. So the answer is 5.