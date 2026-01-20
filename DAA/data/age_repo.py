from random import random
import os

def generate_ages():
    ages = list()
    dir = os.getcwd()
    for i in range(20):
        age:float = round(random()*100,2)
        ages.append(age)
    ages.insert(0,"age")
    with open(f"{dir}/data/age_repo.csv","w") as f:
        ages = [f"{age}\n" for age in ages]
        f.writelines(ages)
        
if __name__ == "__main__":
    generate_ages()