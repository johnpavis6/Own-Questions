import string
import random
import os
import sys


def generate_string():
    size = random.randint(1, 1000)
    chars = string.ascii_lowercase
    return ''.join(random.choice(chars) for _ in range(size))+'\n'


print("Testcases creation starts")
strings = []
while(len(strings) < 500):
    str1, str2 = generate_string(), generate_string()

    file = open("temp_input.txt", "w+")
    file.write('1\n'+str1+str2)
    file.close()

    child_pid = os.fork()
    if child_pid == 0:
        os.system("./a.out < temp_input.txt > temp_output.txt")
        sys.exit(0)
    os.waitpid(child_pid, 0)

    file = open("temp_output.txt", "r")
    result = file.read()
    if "-1" not in result:
        strings.extend([str1, str2])
        print(len(strings))
    file.close()

for _ in range(0, 500):
    strings.append(generate_string())

file = open("input.txt", "w+")
file.write(str(int(len(strings)/2))+'\n')
for string in strings:
    file.write(string)
file.close()

child_pid = os.fork()
if child_pid == 0:
    os.system("./a.out < input.txt > output.txt")
    sys.exit(0)
os.waitpid(child_pid, 0)

print("Testcases creation completed")
