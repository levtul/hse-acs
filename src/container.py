from src.language    import Language
from src.functional import Functional
from src.procedural  import Procedural
from src.object_oriented import ObjectOriented

import random

#----------------------------------------------
class Container:
    def __init__(self):
        self.store = []

    def In(self, lines):
        arrayLen = len(lines)
        i = 0   # Индекс, задающий текущую строку в массиве
        while i < arrayLen:
            line = lines[i]
            if line.split()[0] == "functional":
                i += 1
                language = Functional()
            elif line.split()[0] == "procedural":
                i += 1
                language = Procedural()
            elif line.split()[0] == "procedural":
                i += 1
                language = ObjectOriented()
            else:
                print(f"error: unknown language type: {line.split()[0]}")
                return line.split()[0]
            line = lines[i]
            language.name = line.split()[1]
            i += 1
            line = lines[i]
            language.creation_date = int(line.split()[1])
            i += 1
            line = lines[i]
            language.popularity = float(line.split()[1])
            i += 1
            language.In(lines, i)
            self.store.append(language)

    def InRnd(self, count):
        for _ in range(count):
            language_type = random.randint(0, 2)
            if language_type == 0:
                language = Functional()
            elif language_type == 1:
                language = Procedural()
            else:
                language = ObjectOriented()
            language.name = random.choices([chr(i + ord('a')) for i in range(26)], k=random.randint(1,30))
            language.creation_date = random.randint(1970, 2020)
            language.popularity = random.random() * 100
            language.InRnd()
            self.store.append(language)

    def Out(self, ostream):
        ostream.write(f"Container contains {len(self.store)} elements.\n")
        for language in self.store:
            language.Out(ostream)
            ostream.write("\n")

    def ShellSort(self):
        pass
