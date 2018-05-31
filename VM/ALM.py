from memory import Memory
from x86comands import *
from MemManager import MemManager

"""
Устройство памяти:
--------------------------------------------------------------------------
| количество | РЕГИСТРЫ | число==количество памяти |  КОМАНДЫ | ТЕКСТ |
| регистров  |          | занимаемой командами     |          |       |
--------------------------------------------------------------------------
"""

class ALM():
    def __init__(self, commands):
        mem = Memory(500)
        mem.set(0, len(val_req) + 1)

        for i, s in enumerate(commands):
            mem.set(i + len(val_req), s)

        self.memory = mem
        self.current_pos_runner = len(val_req) + 1
        self.current_pos_text = self.memory.get(len(val_req)) + len(val_req)

        self.MM = MemManager()


    def descriptor(self, command, arg1, arg2):
        if command == -1:
            return False

        if command == 6:
            #print("command = ",command)
            self.memory.set(arg1, input())
            return True

        if command == 0:
            #print("command = ", command)
            self.memory.set(arg1, self.memory.get(arg1) + self.memory.get(arg2))
            return True

        if command == 1:
            #print("command = ", command)
            if self.memory.get(arg1):
                self.memory.set(arg1, self.memory.get(arg1) - 1)
            return True

        if command == 3:
            #print("command = ", command)
            self.memory.set(arg1, arg2)
            return True

        if command == 2:
            #print("command = ", command)
            print(self.memory.get(arg1))
            return True

        if command == 4:
            #print("command = ", command)
            if self.memory.get(arg1):
                self.current_pos_runner = self.memory.get(0) + (arg2 - 1) * 3
            return True

        if command == 5:
            #print("command = ", command)
            self.memory.set(arg1, self.memory.get(arg2))
            return True

        if command == 8:
            #print("command = ", command)
            string = ''
            for i in range(int(arg2)):
                string += chr(self.memory.get(self.current_pos_text + arg1 + i))
            print(string)
            return True

        print("Wrong command ")
        return False



    def run(self):
        while True:
            command = self.memory.get(int(self.current_pos_runner))
            arg1 = self.memory.get(int(self.current_pos_runner) + 1)
            arg2 = self.memory.get(int(self.current_pos_runner) + 2)
            if not self.descriptor(command, arg1, arg2):
                break

            self.current_pos_runner += 3



