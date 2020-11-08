# 302separation

A program that find the degree of separation between people using Floyd-Warshall algorithm

### Floyd-Warshall Algorithm ?

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/2e/Floyd-Warshall_example.svg/1920px-Floyd-Warshall_example.svg.png">

An algorithm which finds the shortest path in a graph, thanks to an adjacency matrix (but we are also using an incidence matrix here)

### Usage
```bash
./302separation file n
./302separation file p1 p2

    file: a file that contains a list of friends connections (view File Syntax)
    n: maximum size of paths
    p1: name of person 1
    p2: name of person 2
```

### File Syntax
```sh
# example
Jesus is friends with Chuck Norris
Cindy Crawford is friends with Nicole Kidman
V is friends with Barack Obama
Chuck Norris is friends with Barack Obama
V is friends with François Hollande
Penelope Cruiz is friends with Tom Cruise
Nicole Kidman is friends with Tom Cruise
Katie Holmes is friends with Tom Cruise
Sim is friends with Lara Croft
Sim is friends with Chuck Norris
Lara Croft is friends with V
Yvette Horner is friends with Sim
François Hollande is friends with Barack Obama
Sim is friends with Jesus
Tom Cruise is friends with Barack Obama
```

### Output
```bash
./302separation example 3
Barack Obama
Chuck Norris
Cindy Crawford
François Hollande
Jesus
Katie Holmes
Lara Croft
Nicole Kidman
Penelope Cruiz
Sim
Tom Cruise
V
Yvette Horner

0 1 0 1 0 0 0 0 0 0 1 1 0 
1 0 0 0 1 0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 1 0 0 0 0 0 
1 0 0 0 0 0 0 0 0 0 0 1 0 
0 1 0 0 0 0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 0 0 1 0 1 0 
0 0 1 0 0 0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 0 0 0 1 0 0 
0 1 0 0 1 0 1 0 0 0 0 0 1 
1 0 0 0 0 1 0 1 1 0 0 0 0 
1 0 0 1 0 0 1 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 1 0 0 0 

0 1 3 1 2 2 2 2 2 2 1 1 3 
1 0 0 2 1 3 2 3 3 1 2 2 2 
3 0 0 0 0 3 0 1 3 0 2 0 0 
1 2 0 0 3 3 2 3 3 3 2 1 0 
2 1 0 3 0 0 2 0 0 1 3 3 2 
2 3 3 3 0 0 0 2 2 0 1 3 0 
2 2 0 2 2 0 0 0 0 1 3 1 2 
2 3 1 3 0 2 0 0 2 0 1 3 0 
2 3 3 3 0 2 0 2 0 0 1 3 0 
2 1 0 3 1 0 1 0 0 0 3 2 1 
1 2 2 2 3 1 3 1 1 3 0 2 0 
1 2 0 1 3 3 1 3 3 2 2 0 3 
3 2 0 0 2 0 2 0 0 1 0 3 0 
```

```bash
./302separation example "Barack Obama" "V"
Degree of separation between Barack Obama and V: 1
```