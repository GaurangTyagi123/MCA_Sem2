# MCA Semseter 2
<br>
<br>
<br>

# 1.) Design & Analysis of Algorithms
* ### Practical 1 : [Insertion Sort](./DAA/practicals/sorting.cpp#L97)
    - `Implement Insertion Sort  and run it on a synthetic data of (Name : string type, age : float type) for n = 10, 20, ...100. For each n, randomly generate at least 10 data sets. Report the average number of comparisons for each n. Plot a graph and obtain a best-fit curve. (6 hours)`

            a.) Write a function to sort on age

            b.) Write a function to sort on names

            c.) Sort on age and then on names so that the ordering on age is maintained. i.e. For (Reeta, 18.3), (Reeta 17.8), (Geet, 18.3), the output should be  (Geet, 18.3), (Reeta 17.8), (Reeta, 18.3). I.e. If there are two people with the name Reeta their records should appear so that they are sorted on their ages

<br>
<br>
<br>

# 2.)  Data Mining

* ### Practical 1 : [magic gama telescope](./DM/magic_gama_telescope/magic_gamma.ipynb)
    - `Lab 1: Exploratory Analysis and Class Imbalance Handling using the MAGIC Gamma Telescope Dataset`
        
            Import the MAGIC Gamma Telescope dataset from the UCI Machine Learning Repository. Perform exploratory data analysis by visualizing the correlation between each input feature and the target class. Further, demonstrate the effect of class imbalance by applying a Random Oversampling technique and illustrate its impact on the class distribution.

* ### Practical 2 : [ChestXRay](./DM/chest_x_ray/chest_xray.ipynb)
    - `Lab 2: Data Preprocessing and Attribute-Based Segregation of Medical Imaging Data`
        
            In this exercise, you will work with the COVID-19 Chest X-ray dataset available at:

            https://github.com/ieee8023/covid-chestxray-dataset

            The dataset includes a metadata file (metadata.csv) describing imaging attributes for each X-ray.

            You are required to perform attribute-based data selection and transformation using the metadata.

        - `Tasks`
                1. Load metadata.csv using Pandas.

                2. Select the attributes:

                    - view (categorical attribute)

                    - filename (object identifier)

                3. Perform data cleaning by:

                        - Removing records with missing or undefined view values.
                        - Ignoring records corresponding to non-PA and non-AP views.

                4. Perform data transformation and reduction by:

                    - Creating two homogeneous subsets of the dataset corresponding to PA and AP chest X-ray views.

                5. Using the cleaned metadata:

                - Create two directories (PA, AP) in Google Drive.
                - Populate them with the corresponding X-ray images from the images folder.

                6. Generate a summary report showing:

                    - Total images in the original dataset
                    - Number of images retained after preprocessing
                    - Distribution of PA and AP views

# 3.) Operating System
*  ### Practical 1: [Commands](./OS/Assignments/Assignment-1/Assignment-1-sol.pdf)  
    - Write Linux commands for the following commands
        * Create a Project Directory 

        * Navigate to the Project Directory

        * Create Subdirectories: css & js

        * Navigate to the 'css' Directory 

        * Create css File Style.css

        * Navigate to the 'js' Directory and create javascript file script.js 

        * Delete file Style.css
*   ### Practical 2: [fork](./OS/Assignments/Assignment-2/Assignment-2-sol.pdf)
     - Write a C++ program to demonstrate process creation using fork().The child process should print its PID and parentPID, perform a simple task (e.g.,counting from 1 to 5 with delay ), and then terminate.The parent process should wait for the child using wait() and display the child’s exit status.

# 4.) Artificial Intelligence & Machine Learning
*   ### Practical 1: [TicTacToe](./AI_ML/practical_1/TicTacToe.cpp)
     - Write a program which can play TicTacToe
    ### Practical 2: [WaterJug](./AI_ML/practical_2/WaterJug.cpp)
     - Write a program to solve the Water Jug problem.