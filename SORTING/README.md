# Sorting

This folder contains the solutions to the Sorting and Data Retrivial section of the course. 
## Running the tests

In order to compile the program is just necessary to compile it with the command 
```
gcc -o "name_of_executable.x" *.c
```


## Graphs
In this section it's possible to see the result of the execution of the program. 

### Worst Case test for InsertionSort and QuickSort
![Alt-Text](https://github.com/lfresco/ALGORITHMIC_DESIGN/blob/master/img/ins_quick_worst.png "Worst Case test for Insertion and QuickSort")

In order to test the behaviour in the worst case we have to first understand what we mean by that. In both cases this is related to the fact that the array we want to sort in ascending order is already sorted in a discending one. For the QuickSort algorithm we have to add a little tweak meaning that we have to make sure that the Partition sub-routine always selects the "worst" pivotal element (in this case the first one).

With that said, what we had to prove was that the behaviour was quadratic w.r.t the input dimension (the length of the array). And the graph show us that perfectly. 

### Best Case test for Insertion Sort and QuickSort
![Alt-Text](https://github.com/lfresco/ALGORITHMIC_DESIGN/blob/master/img/bestcase.png )

As we done in the section above we have to define what we mean by best case scenario. As it is easy to imagine the best case for the insertion sort algorithm would be to have to deal with an already sorted array as it has to go through al the element at most once. The best case for QuickSort is to have a pivot that each time the function is called it will be at the center of the array. WE achieved this by passing a sorted array and select as the pivotal element the middle one. The theoretical result for the first one is a time-complexity is linear w.r.t. the size of the input while the QuickSort has a time complexity of O(n*log(n)).

The graph above clearly depicts this.

