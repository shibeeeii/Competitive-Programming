def combinationSum(candidates, target):
    res = []

    def backtrack(start, current, total):
        # Base case: found a valid combination
        if total == target:
            res.append(list(current))
            return

        if total > target:
            return

        for i in range(start, len(candidates)):
            current.append(candidates[i])
            backtrack(i, current, total + candidates[i])
            current.pop()  # backtrack

    backtrack(0, [], 0)
    return res


if __name__ == "__main__":
    candidates = [2, 3, 6, 7]
    target = 7
    print(combinationSum(candidates, target))
