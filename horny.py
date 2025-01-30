import time
from time import sleep
from random import randint
i = 0
username = input("Enter username:")
Shit = [f'U are so gay {username} !', f'u are a faggot {username}', ]
repeat = int(input('How often should i tell u?(please only int :3):'))
while i < repeat:
        print(Shit[randint(0,len(Shit)-1)])
        i = i + 1
        print(i)
        sleep(0.5)
print('u gay fuck')
