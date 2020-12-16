string = input()
k = int(input())

all_substr = set()
for i in range(len(string)):
    for j in range(i+1, len(string)):
        all_substr.add(string[i:j+1])

all_substr_l = list(all_substr)
sorted(all_substr_l)
print(all_substr_l[k])
