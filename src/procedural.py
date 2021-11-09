from src.language import *
import random
#----------------------------------------------

class Procedural(Language):
    def In(self, lines, i):
        if len(lines) <= i:
            print("error: reached end of file")
            return
        self.has_adt = int(lines[i].split()[1])

    def InRnd(self):
        self.has_adt = random.randint(0, 1)

    def Out(self, ostream):
        ostream.write(f"""procedural language:
    name: {''.join(self.name)}
    creation_date: {self.creation_date}
    popularity: {self.popularity}
    has_adt: {self.has_adt}
    compare_value: {self.CompareValue()}""")
