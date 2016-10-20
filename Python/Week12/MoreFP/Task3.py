numbers = [11,-17,42,8,-12,9]

numbers = [n if n is not 0 else n for n in numbers if n>0]
print(numbers)