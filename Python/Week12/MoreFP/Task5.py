def ListReverser(wordList):
    for w in reversed(wordList):
        yield w


animalWords = ["antelope", "burro", "cheetah", "donkey", "elephant"]
wordMachine = ListReverser(animalWords)

for w in wordMachine:
    print(w)