def sort_max(nums):
    nums_str = list(map(str, nums))
    for i in range(len(nums_str)):

        for j in range(len(nums_str) - i - 1):

            if nums_str[j] < nums_str[j + 1]:
                nums_str[j], nums_str[j + 1] = nums_str[j + 1], nums_str[j]
    return int("".join(nums_str))


if __name__ == '__main__':
    nums = [123, 456, 78]
    res = sort_max(nums)
    print(res)  # 78456123
