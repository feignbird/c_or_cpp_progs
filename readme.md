### To build & compile a cpp program, you can use following commands:

1. To create an executable file "a.out". (it will compile, assemble, link & build an exec file)
`g++ test.cpp` (format: `g++ filename.cpp`) | return: `a.out` (format: `a.out`)

#### or

2. To get the assembly code for the c++ source code. (note return file is not runnable)
`g++ -S test.cpp` (format: `g++ filename.cpp`) | return: `test.s` (format: `filename.s`)

#### or

3. To output the exec file in desired name.
`g++ -o main.exe test.cpp` (format: `g++ -o desired_name target_source_file`)

#### or




4. run the exec file as
`./executable_file_name`


### OR simply run:

`./runcpp.sh filename.cpp`



## c_progs
List of C files containing data_structures like linked_list, stack, array etc.

### TO RUN
1. Install 'gcc' compiler on your machine & that should be accesible using command line.

2. After installing, if you have linux or mac operating system, you can directly build & execute your program like this `./runc.sh <c_source_file_path>` and if you are on windows please run `gcc -o main.exe <c_source_file_path>` then to execute the executable call `main.exe`.



### Important resources:
1. `Organizing Code Files in C and C++:` - https://www.gamedev.net/tutorials/_/technical/general-programming/organizing-code-files-in-c-and-c-r1798/
2. `Algorithms questions: ` - https://atekihcan.github.io/CLRS/01/E01.02-01/
3. `Competitive programming: ` - https://www.geeksforgeeks.org/how-to-prepare-for-competitive-programming/

## DS lab Programs
### section A
Write a program in c :
1) to implement linear search & binary search in an array.
2) to implement operation like insertion & deletion in an array.
3) to implement queue data structure along with its operations like enqueue, dequeue, display etc using array.
4) to implement queue data structure along with its operations like enqueue, dequeue, display etc. using linked list.
5) to implement linked list with creation of nodes dynamically.
6) to implement stack data structure along with its operations using array.
7) to implement stack data structure along with its operations using linked list.

### section B
8) to implement simple binary tree.
9) to implement binary search tree along with its operations like insertion, deletion (0, 1 & 2 child nodes) & display
10) to implement inorder, preorder & postorder traversal of BST.
11) to implement heap data structure using array.
12) to implement graph using adjacency matrix.
13) to implement BFS and DFS using graph.
