# https://habr.com/post/132554/
# http://pythonicway.com/python-functinal-programming
import itertools

class MyFuncProg:
    def __init__(self):
        hello = "hello, world!"
        #self.gen_ = generator

    def select(self, operation, data):
        return map(operation, data)

    def flattern(self, dataset):
        return list(itertools.chain(*dataset))

    def where(self, predicat, data):        #TODO make generator
        return filter(predicat, data)

    def take(self, amount, data):       #TODO make generator
        return data[:amount]

    def groupBy(self, key_func, data):
        pass    #TODO

    def orderBy(self, key_func, data):
        return sorted(data, key_func)   #TODO make generator

    def toList(selfself, data):
        return list(data)       #TODO make generator

