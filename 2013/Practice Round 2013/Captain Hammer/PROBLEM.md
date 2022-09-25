Problem
===
The Hamjet is a true marvel of aircraft engineering. It is a jet airplane with a single engine so powerful that it burns all of its fuel instantly during takeoff. The Hamjet doesn't have any wings because who needs them when the fuselage is made of a special Wonderflonium isotope that makes it impervious to harm.

Piloting the Hamjet is a not a job for your typical, meek-bodied superhero. That's why the Hamjet belongs to Captain Hammer, who is himself impervious to harm. The G-forces that the pilot endures when taking a trip in the Hamjet are legen-dary.

The Hamjet takes off at an angle of θ degrees up and a speed of **V** meters per second. **V** is a fixed value that is determined by the awesome power of the Hamjet engine and the capacity of its fuel tank. The destination is **D** meters away. Your job is to program the Hamjet's computer to calculate θ given **V** and **D**.

Fortunately, the Hamjet's Wondeflonium hull is impervious to air friction. Even more fortunately, the Hamjet doesn't fly too far or too high, so you can assume that the Earth is flat, and that the acceleration due to gravity is a constant 9.8 m/s<sup>2</sup> down.

Input
===
The first line of the input gives the number of test cases, **T**. **T** lines follow. Each line will contain two positive integers -- **V** and **D**.

Output
===
For each test case, output one line containing "Case #x: θ", where x is the case number (starting from 1) and θ is in degrees up from the the horizontal. If there are several possible answers, output the smallest positive one.

An answer will be considered correct if it is within 10<sup>-6</sup> of the exact answer, in absolute or relative error. See the [FAQ](https://codingcompetitions.withgoogle.com/codejam/faq.html#floating_point) for an explanation of what that means, and what formats of floating-point numbers we accept.

Limits
===
Time limit: 60 seconds.<br />
Memory limit: 1 GB.<br />
1 ≤ **T** ≤ 4500;<br />
1 ≤ **V** ≤ 300;<br />
1 ≤ **D** ≤ 10000;<br />
It is guaranteed that each test case will be solvable.

Sample
===
Sample Input
---
```
3
98 980
98 490
299 1234
```
Sample Output
---
```
Case #1: 45.0000000
Case #2: 15.0000000
Case #3: 3.8870928
```