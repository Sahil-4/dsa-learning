# DSA Notes

### Basic terminology

1. Data Structures : containers to store data.
2. Algorithm : Logic to perform operations on data.
3. Flowchart : Diagramatic representation of an approach to solve any problem.
4. Pseudo Code : Simple way of representing the logic.

### Flowchart compomemts

1. Terminator : Used to show Start or End of the program.
   ![terminator](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fterminator.svg?alt=media&token=86ecbeb8-085e-4f35-8430-9de9ef02670f)

2. Process : Used to show operations or processes.
   ![process](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fprocess.svg?alt=media&token=cdf5ea13-0707-452b-895b-fa839921a0f2)

3. Input/ Output : for taking input or giving output.
   ![i/o](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fio.svg?alt=media&token=72df56cc-5ff6-4145-8261-98b1e23a60e4)

4. Decision : Used to show decision statements in a program, where answer is usually Yes/true or No/false.
   ![decision](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fdecision.svg?alt=media&token=c4a221e4-2574-4e04-bf33-b11a5e2d53a7)

5. Arrow : Shows relationships between components or to connect components.
   ![arrow](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Farrow.svg?alt=media&token=91bcfecd-51d2-4136-aa29-d36874a667ca)

6. On-page Connector : Connects two or more parts of a flowchart on the same page.
   ![connector1](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fconnector1.svg?alt=media&token=b8070e18-ef1b-4add-a87d-a6e00458a974)

7. Off-page Connector : Connects two parts of a flowchart which are spread over different pages.
   ![connector2](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fconnector2.svg?alt=media&token=6bcc4eeb-61c0-4101-80e1-182c11b9862a)

### Pseudo Code : Logic or steps to solve a problem written in plain english.

#### Examples of Flowcharts

1. Flowchart to print hello.
   ![flowchart_hello](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fflowchart_hello.svg?alt=media&token=01a6e0c8-d486-4fb0-aff7-1c22d404d133)

2. Flowchart to calculate sum of two numbers.
   ![flowchart_2sum](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fflowchart_2sum.svg?alt=media&token=31606e39-7892-4b06-bbff-e6df8f7826e0)

3. Flowchart to calculate average of three numbers.
   ![flowchart_3avg](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fflowchart_3avg.svg?alt=media&token=e1b96c6d-635a-4ebc-9563-6325cdc6109d)

4. Flowchart to check whether a number is odd or even
   ![flowchart_oddeven](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fflowchart_oddeven.svg?alt=media&token=ec735c65-cdb0-4a63-8e14-bfe73cacd6bd)

5. Flowchart to check whether a triangle is valid or not
   ![flowchart_validtriangle](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fflowchart_validtriangle.svg?alt=media&token=85bfec9a-b5df-42d0-8c2b-9bb6b45de140)

6. Flowchart to print counting 1 to n
   ![flowchart_counting](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fflowchart_counting.svg?alt=media&token=263947b2-e118-4b09-a0f3-9952d7ec6dda)

7. Flowchart to check if n is a prime number
   ![flowchart_prime](https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fflowchart_prime.svg?alt=media&token=40d20948-f92d-479b-bb61-117642444d05)

#### Examples of Pseudo Code

1. Pseudo Code to print Hello.
   `1. Start`
   `2. print Hello`
   `3. End`

2. Pseudo Code to calculate sum of two numbers.
   `1. Start`
   `2. Take input a and b`
   `3. Process c = a + b`
   `4. Print c`
   `5. End`

3. Pseudo Code to calculate average of three numbers.
   `1. Start`
   `2. Take input a, b and c`
   `3. Calculate avg = (a + b + c)/3`
   `4. Print avg`
   `5. End`

4. Pseudo code to check whether a number is odd or even
   `1. Start`
   `2. Take input n`
   `3. Check if n is devisible by 2`
   `4. if n is devisible by 2 print even`
   `5. if n is not devisible by 2 print odd`
   `6. End`

5. Pseudo Code to check whether a triangle is valid or not
   `1. Start`
   `2. Take input of a, b, c (all three sides of triangle)`
   `3. Check below conditions`
   &nbsp;&nbsp;&nbsp;&nbsp;`a. a+b < c`
   &nbsp;&nbsp;&nbsp;&nbsp;`a. b+c < a`
   &nbsp;&nbsp;&nbsp;&nbsp;`a. c+a < b`
   `4. if above condition is true then given triangle is valid`
   `5. if above condition is false then given triangle is not valid`
   `6. End`

6. Pseudo code to print counting 1 to n
   `1. Start`
   `2. Take input n`
   `3. initialise i = 1`
   `4. if i < n print i and then increment value of i by 1`
   `5. if i is not less then n End`

7. Pseudo code to check if n is a prime number
   `1. Start`
   `2. Take input n`
   `3. initialise i = 2`
   `4. check if i is less then n if yes continue else End the program`
   `5. check if n is divisible by i if yes then print not prime and End the program`
   `6. if n is not divisible by i increament i by 1`
   `7. End`

### Approach to solve a problem

Take problem --> Understand Problem --> Read given hints --> Think for approach --> Code --> Compile --> Run
