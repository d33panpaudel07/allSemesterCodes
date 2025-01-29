class Animal:
    def __init__(self, no_of_legs, breed):
        self.no_of_legs = no_of_legs
        self.breed = breed


class Cat(Animal):
    def __init__(self, name, no_of_legs, breed):
        super().__init__(no_of_legs, breed)
        self.name = name


class Dog(Animal):
    def __init__(self, name, no_of_legs, breed):
        super().__init__(no_of_legs, breed)
        self.name = name


def main():
    name = no_of_legs = breed = ""

    name = "Catty"
    no_of_legs = 4
    breed = "Asian"

    a1 = Animal(no_of_legs, breed)

    d1 = Dog("Doggy",no_of_legs,breed)

    no_of_legs = 3
    breed = "Fat"
    c1 = Cat("Cat",no_of_legs,breed)

    print(c1.name)
    print(c1.no_of_legs)
    print(c1.breed)
    print()
    print(d1.name)
    print(d1.no_of_legs)
    print(d1.breed)

main()