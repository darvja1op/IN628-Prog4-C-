def ListReverser(wordList):
    for w in reversed(wordList):
        yield w


animalWords = ["antelope", "burro", "cheetah", "donkey", "elephant"]
wordMachine = [ w for w in ListReverser(animalWords) if len(w)>=7]

for w in wordMachine:
    print(w)