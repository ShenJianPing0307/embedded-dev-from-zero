
def split_sentence(s):
    words = []
    unit = ""
    for k, i in enumerate(s):
        if (ord(i)>=ord('A') and ord(i) <= ord('Z')) or (ord(i)>=ord('a') and ord(i) <= ord('z')):
            unit += i
        else:
            if unit:
                unit = unit.replace(unit[0], unit[0].upper())
                words.append(unit)
            unit = ""
        if k == len(s)-1 and i.isalpha():
            if unit:
                unit = unit.replace(unit[0], unit[0].upper())
                words.append(unit)
    if not words:
        return "."
    print(words)
    res = " ".join(words)
    return "{}.".format(res)


if __name__ == '__main__':
    s1 = "Who Love?. Solo.."
    s2 = "---Who,love???Solo"
    res = split_sentence(s2)
    print(res)