vowels = ["a","e","i","o","u"]
weekDays = ["Monday","Tuesday","Wednesday","Thursday","Friday"]
noVowels = [ ''.join([l for l in word if l not in vowels]) for word in weekDays ]
print(noVowels)