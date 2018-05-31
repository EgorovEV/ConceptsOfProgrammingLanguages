import numpy as np


class Memory():
    def __init__(self, size):
        self.memory = np.zeros(size, dtype=np.int)

    def get(self, index):
        return self.memory[index]

    def set(self, index, val):
        self.memory[index] = val