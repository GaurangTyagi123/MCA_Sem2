import sys
import os
import pandas as pd
from random import random

def generate_data(n:int)->list:
    
    """
        @brief Function to generate random dataset of size n
        @input n:int Size of the dataset
        @return output:dict Dictionary of name and age
    """
    
    output = list()
    if n <= 0:
        return output
    else:
        names = pd.read_csv(f"/home/gaurang/d_drive/College Material/MCA_Sem2/DAA/data/name_repo.csv").sample(n,replace=True).name.values.reshape(-1,)
        for name in names:
            record = dict();
            age:float = round(random()*100,2)

            record['name'] = name
            record['age'] = age
            output.append(record)
        return output


if __name__ == '__main__':
    # get the arguments passed in the command line
    arg_list = sys.argv 
    
    # default value of 10 for the dataset size
    n:int = 10
    
    if len(arg_list) > 1:
        if type(arg_list[1] == 'int'):
            n = int(arg_list[1])
            
    data = generate_data(n)
    with open(f"/home/gaurang/d_drive/College Material/MCA_Sem2/DAA/data/{n}_set.csv",'w+') as f:
        for rec in data:
            name,age = rec['name'],rec['age']
            f.write(f"{name},{age}")
            f.write('\n')
    