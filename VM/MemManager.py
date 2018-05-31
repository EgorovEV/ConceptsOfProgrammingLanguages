from memory import Memory
from x86comands import *
import numpy as np

class MemManager():
    def encoder(self, commands):
        if commands[0] == ADD:
            return np.array([0, dec_val_req[commands[1]], dec_val_req[commands[2]]])


        if commands[0] == DEC:
            return np.array([1, dec_val_req[commands[1]], 0])

        if commands[0] == PR:
            return np.array([2, dec_val_req[commands[1]], 0])

        if commands[0] == INIT:
            return np.array([3, dec_val_req[commands[1]], commands[2]])

        if commands[0] == GET:
            return np.array([6, dec_val_req[commands[1]], 0])

        if commands[0] == GOTO:
            return np.array([4, dec_val_req[commands[1]], commands[2]])

        if commands[0] == SAVE:
            return np.array([5, dec_val_req[commands[1]], dec_val_req[commands[2]]])

        if commands[0] == EXIT:
            return np.array([-1, 0, 0])

        print("Wrong command ", commands[0])
        return np.array([])
