import sys

from src.container import Container

def fail():
    print("""incorrect command line!
  Waited:\n"
     python3 main.py -f infile outfile
  Or:\n"
     python3 main.py -n number outfile""")
    exit()

#----------------------------------------------
if __name__ == '__main__':
    if len(sys.argv) != 4:
        fail()
    elif sys.argv[1] == "-f":
        inputFileName  = sys.argv[2]
        outputFileName = sys.argv[3]
        ifile = open(inputFileName)
        lines = ifile.read().split('\n')
        ifile.close()
    elif sys.argv[1] == "-n":
        count = int(sys.argv[2])
        outputFileName = sys.argv[3]
    else:
        fail()

    # Формирование массива строк, содержащего чистые данные в виде массива строк символов.

    print('==> Start')

    container = Container()
    if sys.argv[1] == "-f":
        container.In(lines)
    else:
        container.InRnd(count)

    container.ShellSort()
    ofile = open(outputFileName, 'w')
    container.Out(ofile)
    ofile.close()

    print('==> Finish')
