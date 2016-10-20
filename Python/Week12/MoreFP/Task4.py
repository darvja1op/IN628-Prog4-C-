import random

class FlashCard:
    def __init__(self, inputWords):
        self.wordList = inputWords
        self.currentWordIndex = 0

    def __iter__(self):
        return self

    def __next__(self):
        # generate random index
        self.currentWordIndex = random.randint(0,4)

        currentWord = self.wordList[self.currentWordIndex]
        return currentWord

germanWords = FlashCard(["die Kuh", "der Hund", "die Katze", "das Pferd", "die Ente"])

for i in range(5):
    print(next(germanWords))