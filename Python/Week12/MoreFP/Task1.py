def removeTheVowels(inputString):
    vowels = ["a","e","i","o","u"]
    consonants = [ l for l in inputString if l not in vowels ]
    newString = ''.join(consonants)
    print(newString)

removeTheVowels("Jared")