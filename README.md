# producer-consumer

A rappid solution of the producer-consumer issue.

github repo https://github.com/hop-/producer-consumer

Author:
    Hovhannes Palyan (hovhannespalyan@gmail.com)

## Requirements

The project has been tested on linux machine.

g++
make

## Build

To build this solution run ```make``` command in root directory of project.
It will make an executable ```producer-consumer```

## Run

Execute the solution with tne following command
```
./producer-consumer
```
After start please input the number of producers and consumers. The numbers should be between 1 to 10.

Iterruption ```Ctrl+C``` of the process will cause of gracefully shut down.
It will stop producers and wait till consumers complete their job.

## Output

The solution will print current number of elements of data queue in each second.
It also generates output file ```data.txt``` which contains the values of consumed element.
