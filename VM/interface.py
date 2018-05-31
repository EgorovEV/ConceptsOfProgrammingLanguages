from ALM import ALM
import numpy as np
from MemManager import MemManager

"""
Это интрефейс.
Через него можно загружать команды/данные,  
и получать результат работы программы
"""

from x86comands import *
from memory import Memory

def read_from_file(file):
    memMan = MemManager()
    file = open(file, 'r')

    commands = np.array([], dtype=np.int)
    static = np.array([], dtype=np.int)
    start_position_on_static = 0

    for line_ in file:
        line = line_.split()
        if line[0] == PUTSTR:
            line = line_.split(maxsplit=1)[1].strip()
            for symbol in line:
                static = np.append(static, ord(symbol))
            commands = np.append(commands, [8, start_position_on_static, len(line)])
            start_position_on_static += len(line)
        else:
            commands = np.append(commands, memMan.encoder(line))

    commands = np.array([len(commands) + 1, ] + list(commands) + list(static), dtype=np.int)
    return commands


def main():
    commands = read_from_file('input.txt')
    #print(commands)
    #write_to_file('output.txt', commands)
    vm = ALM(commands)
    #vm.upload_data(commands)
    vm.run()


if __name__ == "__main__":
    main()