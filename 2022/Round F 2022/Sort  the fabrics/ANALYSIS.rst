Analysis
--------
Let us denote the fabric array sorted by Ada as <i>Ad</i>, and the one sorted by Charles as <i>Ch</i>.

Test Set 1
----------
The maximum number of fabrics here is 2.

**One fabric**

When there's only one fabric, the answer is always 1.

**Two fabrics**

When there are two fabrics, the answer is either 0 or 2.

If the two fabrics have the same color and the same durability, the sort will be done by the unique identifier, leading to the same ordering of the fabrics in both <i>Ad</i> and <i>Ch</i>; hence the answer is 2.

If the two fabrics have the same color, then <i>Ad</i> would be sorted in the ascending order of the unique identifier. We need to check, if the smaller unique index has the smaller durability of the two fabrics or not. If yes, then the fabrics in <i>Ch<i> will be in the same order as <i>Ad</i>, and the answer is 2; otherwise the answer is 0.

If the two fabrics have the same durability, then <i>Ch</i> would be sorted in the ascending order of the unique identifier. We need to check, if the smaller unique index has the lexicographically smaller color of the two fabrics, or not. If yes, then the fabrics in <i>Ad</i> will be in the same order as <i>Ch</i>, and the answer is 2; otherwise the answer is 0.

If the two fabrics have different colors and durabilities and if the less durable fabric also has the lexicographically smaller color, then in both <i>Ad</i> and <i>Ch</i>, the sorted array will have the same order of fabrics, and the answer will be 2. If that is not the case, the answer is 0.

In all of the approaches discussed above, the time complexity is O(1), which is sufficient for Test Set 1.

Test Set 2
----------
We can create two instances of the fabric array, and sort one of them to create <i>Ad</i>, and another one to create <i>Ch</i>. Now, we can compare the two arrays, and the number of fabrics that have the same index in both of them is the required answer.

Here, the time complexity of sorting by ascending durability is O(**N** log **N**), and the time complexity of sorting by ascending color is O(**N** log **N** × max|**C<sub>i</sub>**|). Running a loop over <i>Ad</i> and <i>Ch</i> is O(**N**). So, the total time complexity is <i>O</i>(**N** log **N** × max|**C<sub>i<sub>**|), which is sufficient for Test Set 2.