# [Seven-segment Display](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000434d9c/0000000000434c09)

## [Problem](PROBLEM.md)

## [Analysis](ANALYSIS.md)

## Solution
[CPP](Solution.cpp)<br />
[JAVA](Solution.java)<br />
[PYTHON](Solution.py)

## Approach

<details>
<summary>Hint 1</summary>
<br />
* Question is not asking next number, but asking next display, i.e, LEDs that are turned on in (N + 1)th step.
</details>

<details>
<summary>Hint 2</summary>
<br />
* Each LED has either of 3 stages:- Working, Broken, Unknown<br />
* Working and Broken are easy to work with. For Unknown, if it has to glow, then we can't tell if it glow. So, Display ERROR! else Display 0 at that place
</details>

<details>
<summary>Hint 3</summary>
<br />
* If you are getting multiple numbers that can be diplayed and all lead to same diplay pattern then show that pattern, because what ever number is being diplayed, you will see single pattern<br />
* If all numbers leads to different LED patterns, then you can't decide which to display, hence display ERROR!
</details>

<details>
<summary>Hint 4</summary>
<br />
* If you are getting multiple sequence at the end, keep in mind for each sequence LED status will be different, i.e., same element can be Working, Broken or Unknown for different sequence
</details>