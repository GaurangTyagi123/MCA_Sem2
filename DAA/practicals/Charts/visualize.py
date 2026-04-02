import matplotlib.pyplot as plt
import pandas as pd
import sys
import seaborn as sns

if __name__ == "__main__":
    arg_list = sys.argv 
    report_path = arg_list[1]
    image_path = arg_list[2]
    report = pd.read_csv(report_path)
    
    
    plt.style.use("ggplot")
    plt.figure(figsize=(19.2,10.8))
    plt.subplot(2,3,1)
    sns.lineplot(report,x='dataset',y='age_comparisons',marker="*",color="red")
    
    plt.subplot(2,3,2)
    sns.lineplot(report,x='dataset',y='age_assignments',marker="*",color="blue")
    
    plt.subplot(2,3,3)
    sns.lineplot(report,x='dataset',y='name_comparisons',marker="*",color="green")
    
    plt.subplot(2,3,4)
    sns.lineplot(report,x='dataset',y='name_assignments',marker="*",color="violet")
    
    plt.subplot(2,3,5)
    sns.lineplot(report,x='dataset',y='age_name_assignments',marker="*",color="lime")
    
    plt.subplot(2,3,6)
    sns.lineplot(report,x='dataset',y='age_name_comparisons',marker="*",color="orangered")
    
    plt.savefig(image_path)
    plt.plot()