from module_LINQ import MyFuncProg

def simpleGenerator(i):
    mylist = range(i)
    for i in mylist:
        yield i

mygen = simpleGenerator(3)
for i in mygen:
    print(i)