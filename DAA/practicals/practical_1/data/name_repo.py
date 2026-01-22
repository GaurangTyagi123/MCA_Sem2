from faker import Faker
import os

def generate_names():
    fake = Faker()
    names = list()
    dir = os.getcwd()
    for i in range(20):
        names.append(fake.name())
    names.insert(0,"name")
    with open(f"{dir}/data/name_repo.csv","w") as f:
        names = [f"{name}\n" for name in names]
        f.writelines(names)
        
if __name__ == "__main__":
    generate_names()