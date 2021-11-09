from src.language import *
from enum import Enum
import random
#----------------------------------------------

class Inheritance(Enum):
    SINGLE = 1
    MULTIPLE = 2
    INTERFACE = 3

class ObjectOriented(Language):
    def In(self, lines, i):
        if len(lines) <= i:
            print("error: reached end of file")
            return
        inheritance_type = lines[i].split()[1]
        if inheritance_type == "SINGLE":
            self.inheritance_type = Inheritance.SINGLE
        elif inheritance_type == "MULTIPLE":
            self.inheritance_type = Inheritance.MULTIPLE
        elif inheritance_type == "INTERFACE":
            self.inheritance_type = Inheritance.INTERFACE
        else:
            print("error: no such inheritance_type")

    def InRnd(self):
        self.inheritance_type = [Inheritance.SINGLE, Inheritance.MULTIPLE, Inheritance.INTERFACE][random.randint(0, 2)]

    def Out(self, ostream):
        ostream.write(f"""object_oriented language:
    name: {''.join(self.name)}
    creation_date: {self.creation_date}
    popularity: {self.popularity}
    inheritance_type: {str(self.inheritance_type).split('.')[1]}
    compare_value: {self.CompareValue()}""")
