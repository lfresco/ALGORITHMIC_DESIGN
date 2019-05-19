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

In order to test the behaviour in the worst case we have to first understand what we mean by that. In both cases this is related to the fact that the array we want to sort in ascending order is already sorted in a discending one. For the QuickSort algorithm we have to add a little tweak meaning that we have to make sure that the Partition sub-routine always selects the "worst" pivotal element (in this case the first one, aka the biggest one).

With that said, what we had to prove was that the behaviour was quadratic w.r.t the input dimension (the length of the array). And the graph show us that perfectly. 

### Best Case test for Insertion Sort and QuickSort

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc