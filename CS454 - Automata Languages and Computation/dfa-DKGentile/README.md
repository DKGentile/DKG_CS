[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/VQngTDxz)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=16117686&assignment_repo_type=AssignmentRepo)
# Assignment 1: A DFA Simulator

In this assignment you will receive a short code in Python, which simulates a simple DFA that computes whether a given binary string has an even or odd number of zeros. 

The alphabet of the DFA is $\Sigma=\{0,1\}$ and the set of states is $\{q,r\}$ where $q$ is the accepting state (and $r$ is rejecting). The transition function of the DFA works as follows:

$$
\begin{array}{c|cc}
& 0 & 1 \\
\hline
q & r & q \\
r & q & r \\
\end{array}
$$

The goal of the assignment is to modify the description of the DFA so instead it works on the alphabet $\{a,b\}$ and has enough states to establish whether a given string is such that the number of $a$'s is divisible by 2 and the number of $b$'s is divisible by 3.

So for example, the new DFA should accept the string `abbbabaabbbbb` but should reject `aabb`.
