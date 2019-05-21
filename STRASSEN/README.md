# STRASSEN'S ALGORITHM FOR MATRIX MULTIPLICATION

The code in this section provides an implementation of Strassen's algorithm for matrix multiplication. The strassen_improved.h header contains an improved version of the algorithm that achieves better performances by reducing the number of matrices allocation from 17 to 5. 



## Running the tests

In order to compile the program is just necessary to compile it with the command 
```
gcc -o "name_of_executable.x" *.c
```

## Graphs
In this section it's possible to see some plots relative to result of the execution of the program. The first two graphs are related to the execution of the file obtained via the -O0 option of gcc.  The first one shows us that, even though the difference with the naive one is quite impressive, the two versions of the strassen seem to achieve pratically the same performance. We can see a little difference as the number of elements reaches 1024. 


![Alt-Text](https://github.com/lfresco/ALGORITHMIC_DESIGN/blob/master/img/strassen_all.png "Strassen Performance")
![Alt-Text](https://github.com/lfresco/ALGORITHMIC_DESIGN/blob/master/img/strassen_sing_nopt.png "Strassen Performance")


In the following two graphs we can instead see the results when our files are compiled with the -O4 option on. Here, in particular in the second plot we can see that the results, even though they are always in the same order of magnitudes, show that the second implementation is consistenly faster than the first one. 


![Alt-Text](https://github.com/lfresco/ALGORITHMIC_DESIGN/blob/master/img/strassen_opt.png "Strassen Performance")
![Alt-Text](https://github.com/lfresco/ALGORITHMIC_DESIGN/blob/master/img/strassen_sing_opt.png "Strassen Performance")


