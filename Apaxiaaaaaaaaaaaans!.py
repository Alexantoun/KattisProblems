inputString = input()
print(inputString[0], end="")
for x in range(1,len(inputString)):
    if inputString[x] != inputString[x-1]:
        print(inputString[x], end = "")