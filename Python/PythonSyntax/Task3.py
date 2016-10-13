class Dog:

    species = 'Canis familiaris'
    dogCount = 0

    def __init__(self, name, breed):
        self.name = name
        self.breed = breed
        # By using the class name rather than self, the dogCount variable belongs to the class itself, not the object made
        Dog.dogCount += 1

    def bark(self):
        print("Woof")

    def describe(self):
        print("My name is " + self.name + ". I am a " + self.breed)

fido = Dog('Fido', "German Shepherd")
buddy = Dog('Buddy', "Poodle")
spot = Dog('Spot', "Yorkshire Terrier")

print(fido.dogCount)
print(buddy.dogCount)
print(spot.dogCount)