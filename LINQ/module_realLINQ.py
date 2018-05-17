# https://habr.com/post/132554/
# http://pythonicway.com/python-functinal-programming

import collections


class FuncProgSequence:
    def __init__(self, data):
        self.data = iter(data)

    def select(self, operation):
        return FuncProgSequence(operation(elem) for elem in self.data)

    def flatten(self):
        return FuncProgSequence(elem for elems in self.data for elem in elems)

    def where(self, predicate):
        return FuncProgSequence(elem for elem in self.data if predicate(elem))

    def take(self, n):
        return FuncProgSequence(self.take_generator(n))

    def take_generator(self, n):
        i = 0
        for el in self.data:
            if i == n:
                break
            yield el
            i += 1

    def groupBy(self, key_func=lambda x: x):
        dict_ = collections.defaultdict(list)
        for x in self.data:
            dict_[key_func(x)].append(x)
        return FuncProgSequence(dict_.items())

    def orderBy(self, key_func):
        return FuncProgSequence(sorted(self.data, key=key_func))

    def toList(self):
        return list(self.data)

