import random
import os
import sys


def generate_nodes():
    size = random.randint(1, 1000)
    nodes = []
    for _ in range(0, size):
        n = random.randint(0, 1000)
        nodes.append(n)
    return size, nodes, random.randint(0, 1000)


print("Testcases creation starts")

file = open("input.txt", "w+")
file.write("1000\n")
for _ in range(0, 1000):
    size, nodes, ele = generate_nodes()
    file.write(str(size)+'\n')
    string = ""
    for node in nodes:
        string += str(node)+' '
    string = string [:-1]+'\n'
    file.write(string+str(ele)+'\n')

child_pid = os.fork()
if child_pid == 0:
    os.system("./a.out < input.txt > output.txt")
    sys.exit(0)
os.waitpid(child_pid, 0)

print("Testcases creation completed")
