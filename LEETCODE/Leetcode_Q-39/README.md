Problem: 39. Combination Sum

Given an array of distinct integers 'candidates' and a target integer 'target', 
return a list of all unique combinations of candidates where the chosen numbers 
sum to target. The same number may be chosen from candidates an unlimited number of times.

You may return the combinations in any order.

Each number in candidates may be used unlimited times in the combination.
Two combinations are unique if the frequency of at least one of the chosen 
numbers is different.

The test cases are generated such that the number of unique combinations 
that sum up to target is less than 150 combinations for the given input.

Example:
---------
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Explanation:
2 and 3 can be used multiple times.
- 2+2+3 = 7
- 7 = 7

Constraints:
-------------
1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40