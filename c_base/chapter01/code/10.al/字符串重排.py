from itertools import permutations


def perm(s):
    return len(set(list(permutations(s))))


if __name__ == '__main__':
    s = "ABCDEFGHHA"
    perm(s)
