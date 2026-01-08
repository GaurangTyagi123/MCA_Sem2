import sys

from faker import Faker
from random import random
from pprint import pprint

def generate_data(n:int)->list:
    fake = Faker()
    output = list()
    if n <= 0:
        return output
    else:
        for i in range(n):
            record = dict();

            name:str = fake.name()
            age:float = round(random()*100,2)

            record['name'] = name
            record['age'] = age
            output.append(record)
        return output


if __name__ == '__main__':
    arg_list = sys.argv
    
    n:int = 10
    if len(arg_list) > 1:
        if type(arg_list[1] == 'int'):
            n = int(arg_list[1])
    data = generate_data(n)
    with open(f"/home/shared/College Material/MCA_Sem2/DAA/data/{n}_set.csv",'w+') as f:
        # f.write('name,age\n')
        for rec in data:
            name,age = rec['name'],rec['age']
            f.write(f"{name},{age}")
            f.write('\n')
    