## Task 2 ##

animals = ["dog","cat","horse","fish","platypus"]
numbers = [ 21, 45, 80, 45, 22, 64, 75, 95 ]
# a)
if "dog" in animals:
    print("Bark")

# b)
if "alligator" not in animals:
    print("Crocodile Dundee got me!")

# c)
print("Pen" + "Pineapple" + "Apple" + "Pen")

# d)
print(animals[0] + animals[1] * 10)

# e)
print(len(animals))

# f)
print("Max: ", max(numbers))
print("Min: ", min(numbers))

# g)
print("First occurence of 45: ", numbers.index(45))

# h)
print("Number of 45's: ", numbers.count(45))

# i)
print(numbers)
del(numbers[3])
print(numbers)

# j)
numbers.append(38)
print(numbers)

# k)
moreNumbers = [ 22, 18, 45]
numbers.extend(moreNumbers)
print(numbers)

# l)
numbers.insert(2, 33)
print(numbers)

# m)
numbers.remove(45)
print(numbers)

# n)
print(numbers.pop())
print(numbers)

# o)
numbers.reverse()
print(numbers)