class Ear:
    def __init__(self,ear):
        self.ear = ear

class Eye:
    def __init__(self,eye):
        self.eye = eye

    def __sizeof__(self):
        return super().__sizeof__()

e1 = Eye(2)
print(e1.__sizeof__())

integer = 5
print(integer.__sizeof__())

