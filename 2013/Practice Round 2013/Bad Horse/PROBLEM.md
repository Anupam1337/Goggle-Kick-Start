Problem
As the leader of the Evil League of Evil, Bad Horse has a lot of problems to deal with. Most recently, there have been far too many arguments and far too much backstabbing in the League, so much so that Bad Horse has decided to split the league into two departments in order to separate troublesome members. Being the Thoroughbred of Sin, Bad Horse isn't about to spend his valuable time figuring out how to split the League members by himself. That what he's got you -- his loyal henchman -- for.

Input
===
The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each test case starts with a positive integer **M** on a line by itself -- the number of troublesome pairs of League members. The next **M** lines each contain a pair of names, separated by a single space.

Output
===
For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is either "Yes" or "No", depending on whether the League members mentioned in the input can be split into two groups with neither of the groups containing a troublesome pair.

Limits
===
Time limit: 60 seconds per test set.<br />
Memory limit: 1 GB.<br />
1 ≤ **T** ≤ 100.<br />
Each member name will consist of only letters and the underscore character.<br />
Names are case-sensitive.<br />
No pair will appear more than once in the same test case.<br />
Each pair will contain two distinct League members.<br />

Small dataset
===
1 ≤ **M** ≤ 10.

Large dataset
===
1 ≤ **M** ≤ 100.

Sample
===
Sample Input
---
```
2
1
Dead_Bowie Fake_Thomas_Jefferson
3
Dead_Bowie Fake_Thomas_Jefferson
Fake_Thomas_Jefferson Fury_Leika
Fury_Leika Dead_Bowie
```
Sample Output
---
```
Case #1: Yes
Case #2: No
```