# TravellingSalesmanProblem
Application of Travelling Salesman Problem in the Logistic Practice 
The project is divided into two sections. 
The First part "old research paper" implements the travelling Salesman Problem in logistics practice considering a scenario of delievering goods among 16 cities.The aim ids to find a shortest path for the salesman so as to cover all cities and reach the starting city as the final destination. The distance and travelling time between these cities is given in the form of four matrices as input:-
(i) Matrix of distance in kilometers for shortest connection.
(ii) Matrix of distance in kiolmeters for fastest connection.
(iii)Matrix of time in minutes for shortest connection.
(iv)Matrix of time in minutes for fastest connection.
The implemenattion is done using three algorithms namely "Dynamic Programming (Depth first search)" , Branch and Bound (Breadth First Search) ,and, "Ant Colony Optimization".
(i)"final code for ant colony in c#" applies ant colony algorithm in C# to solve the above problem and optimizes all the four situations with inputs for these situations given in "ant colony inputs".
(ii)"final code for branch and bound in c++" makes use of banch and bound algorithm with its coding done in c++ and optimizes the four situations based on their inputs given in "inputs for tsp".
(iii)"final code for dynamic programming in c++" makes use of Dynamic Programming with its coding done in c++ and optimizes the four situations based on their inputs given in "inputs for tsp".
The branch and bound algorithm apparently provided the best solutions (for the inputs chosen) with the minimum required distance to be travlled by the salesman.

The second part of the project "research paper" deals with dynamic problems that the salesman may encounter during his journey on the previously optmized path. In such cases, the salesman has to make a dynamic decision as to how to to formulate a new path which comes up with a maximum profit for the logistics company by minimizing the actual required distance to be travelled.
The types of situation he may encounter:-
(i)Landslide or bad weather conditions
(ii)Visiting a warehouse on the way
(iii)Return request from a customer
(iv)Cancellation request from a customer
Here we are working on a dataset for 15 cities.
The (i) and (iv) situations demand a city to be skipped from the cuurent path and optimize the reamining path accordingly whereas the the (ii) and (iii) demand a city or inventory to be added to the current path and optimize the new path leaving the cities already traversed (in both the cases).
The codes provided for the same are:-
(i) "FINAL CODE FOR ADDITION OF A NODE IN THE BEGINNING" adds a new city to the current path before the salesman starts his journey. The distance of this new city from all other 16 cities is required . The inputs are given in "inputs for tsp" under the heading '17 cities'and '16 cities'.
(ii)"FINAL CODE FOR ADDITION OF A NODE PRIOR TO ANY OTHER NODE" adds a new city to the current path before the salesman visits the next node during his journey (asks the salesman if he wants to add a city). The distance of this new city from all other 16 cities is required. The inputs are given in "inputs for tsp" under the heading '17 cities'(assuming that 2 cities have been added during the journey)
(iii) "FINAL CODE FOR DELETION OF NODE IN THE BEGINNING" deletes a city from the existing path before the salesman starts his journey. The inputs for the same are provided in "inouts for tsp" under the heading '14 cities' (assuming that the salesman has deleted single city from his path).
(iv) "FINAL CODE FOR DELETION OF NODE PRIOR TO ANY OTHER NODE" deletes a city from the existing path while the salesman is on his journey. The inputs for the same are provided in "inouts for tsp" under the heading '14 cities' (assuming that the salesman has deleted single city from his path).
The "report" conatins a reort of the entire project.
