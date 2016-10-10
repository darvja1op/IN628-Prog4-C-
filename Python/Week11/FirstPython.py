import random

def returnOddLetters(word):
    #print(word[1::2])
    #return every second letter starting from the 2nd letter
    return word[1::2]

print(returnOddLetters("Jared Darvill-Jackson"))

def randomNumbers():
    numbers = []
    for i in range(10):
        numbers.append(random.randrange(100))
        #print(numbers[i])
    print("Min: ", min(numbers))
    print("Max: ", max(numbers))

randomNumbers()