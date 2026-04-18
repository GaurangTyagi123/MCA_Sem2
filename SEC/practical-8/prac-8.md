**Name : Gaurang Tyagi**

**Roll No. : 16**

# Assignment - 8

## Ques1 : Write a program to compute the sum of the following series.
$$
S = 1 + \frac{1}{2} + \frac{1}{3} + ... + \frac{1}{n} 
$$

#### CODE :

```matlab
n = input('Enter n: ');
S = 0;

for i = 1:n
    S = S + 1/i;
end

disp(['Sum = ', num2str(S)]);
```
#### OUTPUT
![1776224333728](image/prac-8/1776224333728.png)


## Ques2 : Write a program to generate Fibonacci series up to n terms using while loop.

#### CODE :

```matlab
n = input('Enter number of terms: ');

a = 0;
b = 1;
count = 1;

while count <= n
    fprintf('%d ', a);
    temp = a + b;
    a = b;
    b = temp;
    count = count + 1;
end
```

#### OUTPUT:
![1776224405304](image/prac-8/1776224405304.png)

## Ques3 : Write a program to find the sum of all even numbers from 1 to n.

#### CODE: 

```matlab
n = input('Enter n: ');
sum_even = 0;

for i = 1:n
    if mod(i,2) == 0
        sum_even = sum_even + i;
    end
end

disp(['Sum of even numbers = ', num2str(sum_even)]);
```
#### OUTPUT:
![1776224451133](image/prac-8/1776224451133.png)

## Ques4: Write a program to accept a number from the user and check whether it is a prime number or not.

#### CODE :

```matlab
n = input('Enter a number: ');
isPrime = true;

if n <= 1
    isPrime = false;
else
    for i = 2:sqrt(n)
        if mod(n,i) == 0
            isPrime = false;
            break;
        end
    end
end

if isPrime
    disp('Prime number');
else
    disp('Not a prime number');
end
```
#### OUTPUT:
![1776224496864](image/prac-8/1776224496864.png)
![1776224512541](image/prac-8/1776224512541.png)

## Ques5: Write a program to find the largest among three numbers.

#### CODE:

```matlab
a = input('Enter first number: ');
b = input('Enter second number: ');
c = input('Enter third number: ');

largest = max([a b c]);

disp(['Largest number = ', num2str(largest)]);
```
#### OUTPUT:
![1776224553781](image/prac-8/1776224553781.png)

## Ques6: Write a program to accept year from the user and check whether it is a leap year or not.

#### CODE:

```matlab
year = input('Enter year: ');

if (mod(year,4) == 0 && mod(year,100) ~= 0) || mod(year,400) == 0
    disp('Leap year');
else
    disp('Not a leap year');
end
```
#### OUTPUT:
![1776224585077](image/prac-8/1776224585077.png)

## Ques7: Write a function that returns the sum of digits of a number.
        Sample Input : 236
        Sample Output : 11

#### CODE:

```matlab
function s = sum_of_digits(n)
    s = 0;
    while n > 0
        digit = mod(n,10);
        s = s + digit;
        n = floor(n/10);
    end
end

num = input('Enter a number: ');
result = sum_of_digits(num);
disp(['Sum of digits = ', num2str(result)]);
```
#### OUTPUT:
![1776224715382](image/prac-8/1776224715382.png)
![1776224755884](image/prac-8/1776224755884.png)

## Ques8: Create a user-defined function to compute factorial of a number.

#### CODE:

```matlab
function f = my_factorial(n)
    f = 1;
    
    for i = 1:n
        f = f * i;
    end
end

num = input('Enter a number: ');
result = my_factorial(num);
disp(['Factorial = ', num2str(result)]);
```
#### OUTPUT: 
![1776224802254](image/prac-8/1776224802254.png)

## Ques9: Write a function that returns the reverse of a given number.

## CODE:

```matlab
function rev = reverse_number(n)
    rev = 0;
    
    while n > 0
        digit = mod(n,10);
        rev = rev * 10 + digit;
        n = floor(n/10);
    end
end

num = input('Enter a number: ');
result = reverse_number(num);
disp(['Reversed number = ', num2str(result)]);
```
#### OUTPUT:
![1776224828006](image/prac-8/1776224828006.png)

## Ques10: Write a program to compute the sum of the following series:
$$
S = a + \frac{a}{2} - \frac{a}{3} + ... n
$$

#### CODE:

```matlab
a = input('Enter value of a: ');
n = input('Enter value of n: ');

S = 0;

for i = 1:n
    if mod(i,2) == 1  
        S = S + a/i;
    else             
        S = S - a/i;
    end
end

disp(['Sum of series = ', num2str(S)]);
```

#### OUTPUT:
![1776224871026](image/prac-8/1776224871026.png)