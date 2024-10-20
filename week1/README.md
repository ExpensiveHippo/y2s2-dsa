# Week 1

## Question 1

Write a function ```printInteger``` which:
1. takes in a 5-digit integer as an input.
2. prints each digit separated by 3 spaces.

**Example:**
```cpp
printInteger(12345); // prints "1   2   3   4   5"
```
<br>
<br>

## Question 2
Write a program *pointerDemo.cpp* which:
1. declares and initializes an int variable ```value1``` with 200000.    
2. declares an int variable ```value2```.
3. declares and initializes an int pointer variable  ```ptr``` which points to the address of value1. 
4. prints the value pointed by ```ptr```.
5. assigns ```value2``` the value pointed to by ```ptr```.
6. prints the value of ```value2```. What do you observe?
7. prints the address of ```value1```.
8. prints the value of ```ptr```. Is the value the same as ```value1```'s address?
9. assigns ```ptr``` the address of ```value2```.
10. adds 2000 to the value pointed to by ```ptr```.
11. prints the value of ```value1``` and ```value2```. What do you observe? Can you explain the observation?
<br>
<br>

## Question 3
In *pointerDemo2.cpp*:
1.	Write a function ```changeValue(int x, int* y)``` that:
    1. adds 10 to x.
    2. adds 10 to value pointed to by y.

2. 	In ```main```, 
    1. declare an int variable ```x``` and initalize it to 30.
    2. declare another int variable ```y```.
    3. assign value of ```x``` to ```y```. 
    4. make a function call to ```changeValue``` and pass in value of ```x``` and address of ```y```.
    5. print ```x``` and ```y```.

What do you observe? Are ```x``` and ```y``` in ```main``` same as the ```x``` and ```y``` in ```changeValue```? Can you explain the observations?
<br>
<br>



## Question 4
Create a class ```Employee``` that has three attributes:
- ```firstName``` (string) 
- ```lastName``` (string) 
- ```monthlySalary``` (int)

 Your class should have a constructor that initializes the three data members. Provide a set and get function for each data member. If the monthly salary is not positive, set it to 0. 

Write a program ```calYearlySalary.cpp``` that demonstrates class ```Employee```’s capabilities. Create two ```Employee``` objects and display each object’s yearly salary. Then give each employee a 10 percent raise and display each employee’s yearly salary again.
<br>
<br>

## Optional
1. Create a base class called ```Account``` that contains:
- attribute ```balance``` of type double to represent the account balance. 
- constructor that receives initial balance and initializes ```balance```.
- function ```credit()``` that adds an amount to current balance.
- function ```debit()``` that withdraws money from the account.
- function ```getBalance``` that returns the current balance.

The constructor should validate initial balance to ensure that it is greater than or equal to 0. If not, set ```balance``` to 0 and display error message *"Initial balance was invalid.".*

```debit()``` should ensure the amount to withdraw does not exceed the account's balance. If it does, balance should not change. Instead, print an error message *"Debit amount exceeded account balance."*
<br>

2. Next, define a derived class ```SavingsAccount``` that inherits from ```Account``` and contains:
- attribute ```interestRate``` of type double to represent interest rate (percentage) 
- constructor that receives initial balance as well as initial value for ```interestRate```.
- function ```calculateInterest()``` that returns double to represent amount of interest (interest rate * account balance )
<br>

3.	Define another derived class ```CheckingAccount``` that inherits from ```Account``` and contains:
- attribute ```fee``` of type double that represents fee charged per transaction 
- constructor that receives initial balance and initial value for ```fee```.
- overridden functions ```credit()``` and ```debit()``` so that they subtract ```fee``` from  ```balance``` whenever transaction is successful

```debit()``` function charges fee only if money is actually withdrawn.
<br>

4.	Now, write a polymorphic banking program called ```banking.cpp```. Create a ```vector``` of ```Account``` pointers to ```SavingsAccount``` and ```CheckingAccount``` objects. For each ```Account``` in the vector:
- allow user to specify amount to withdraw from it using ```debit()```.
- allow user to specify amount to deposit into it using ```credit()```.
- determine type of object.
    -  If object is of type ```SavingsAccount```, calculate amount of interest owed to account and then add interest to the account balance.
- print updated account balance using ```getBalance()```.
