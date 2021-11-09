from src.language import *
from enum import Enum
import random
#----------------------------------------------

class Typing(Enum):
    STRICT = 1
    DYNAMIC = 2

class Functional(Language):
    def In(self, lines, i):
        if len(lines) <= i:
            print("error: reached end of file")
            return
        typing_type = lines[i].split()[1]
        if typing_type == "STRICT":
            self.typing_type = Typing.STRICT
        elif typing_type == "DYNAMIC":
            self.typing_type = Typing.DYNAMIC

    def InRnd(self):
        self.typing_type = [Typing.STRICT, Typing.DYNAMIC][random.randint(0, 1)]

    def Out(self, ostream):
        ostream.write(f"""functional language:
    name: {''.join(self.name)}
    creation_date: {self.creation_date}
    popularity: {self.popularity}
    typing_type: {str(self.typing_type).split('.')[1]}
    compare_value: {self.CompareValue()}""")
