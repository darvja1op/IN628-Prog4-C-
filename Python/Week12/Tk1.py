starWars = "A long time ago in a galaxy far far away"

longWords = filter(lambda x: len(x) > 3, starWars.split())
print(list(longWords))