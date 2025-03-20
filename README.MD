# LAB 04 - SORTING ALGORITHM
## How to build
```
g++ -I include main.cpp cpp/*.cpp -o main -std=c++11
```

## Run code
### Algorithm mode
* Command 1: run sort algorithm with input from `input.txt`, output both `running time` and `comparisons`
```
main.exe -a bubble-sort input.txt -both
```

* Command 2: run sort algorithm with input of size 10000 in nearly sorted order, output `running time`
```
main.exe -a heap-sort 10000 -nsorted -time
```

* Command 3: run sort algorithm with input of size 20000 in all type of order, output `comparisons`
```
main.exe -a merge-sort 20000 -nsorted -comp
```

### Comparison mode
* Command 1: run sort algorithm with input from `input.txt`, output both `running time` and `comparisons`
```
main.exe -c bubble-sort heap-sort input.txt -both
```

* Command 2: run sort algorithm with input of size 10000 in nearly sorted order, output `running time`
```
main.exe -c heap-sort quick-sort 10000 -nsorted -time
```

* Command 3: run sort algorithm with input of size 20000 in all type of order, output `comparisons`
```
main.exe -c merge-sort radix-sort 20000 -nsorted -comp
```