from module_LINQ import MyFuncProg
from module_realLINQ import FuncProgSequence

def limit_fib_generator(n):
    a, b = 1, 1
    for i in range(n-2):
        yield a + b
        a, b = b, a+b

def fib_generator():
    a, b = 0, 1
    while True:
        yield a + b
        a, b = b, a+b

def task_fib(debug):
    fp = MyFuncProg()
    isDevide3 = lambda x: True if x % 3 == 0 else False
    isDevide2Square = lambda x: x * x if x % 2 == 0 else x
    if (debug):
        a1 = fp.where(isDevide3, limit_fib_generator(100))
        # print(a1)
        a2 = fp.select(isDevide2Square, a1)
        # print(a2)
        a3 = fp.take(5, a2)
        # print(a3)
        a4 = fp.toList(a3)
        # print(a4)
        ans = fp.toList(fp.take(5, fp.select(isDevide2Square,
                                             fp.where(isDevide3, limit_fib_generator(100)))))
        print(ans)

    fps = FuncProgSequence(fib_generator())
    ans2 = fps.where(isDevide3).select(isDevide2Square).take(5).toList()
    print(ans2)

def task_word_count():
    with open("input.txt", "r") as f:
        ans = FuncProgSequence(f.readlines()).select(lambda line: line.split()).flatten() \
                    .groupBy(lambda word: word).select(lambda item: (item[0], len(item[1]))) \
                    .orderBy(lambda item: -item[1]) \
                    .toList()
        print(ans)

def main():
    task_fib(False)
    task_word_count()

if __name__ == "__main__":
    main()