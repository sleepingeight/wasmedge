## Build Instructions for running solution of Pretest-2

Prepare the module by writing functions in code.c. Next, use the below command to generate the LLVM module.

```bash
$ clang -S -emit-llvm code.c -o temp.ll
```

To run the source code - 

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make -j
$ ./main ../temp.ll
```

Running the executable as above will result in the output as, 
```bash
Function: add
Function: sub
Function: mod
```


