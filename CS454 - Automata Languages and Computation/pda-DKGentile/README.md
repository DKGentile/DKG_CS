[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/O7BA1HYE)
# Deterministic PDA

This assignment is related to section **8.4.2: Pushdown Automata** in the textbook. In this assignment you are going to both specify a PDA and design a function to run a PDA:

1. First, design a `pda2` on line 131 for the language of _well formed parenthetical expressions_; this language is defined as follows: $E\rightarrow EE|(E)|\varepsilon$. So for example, $()()(())$ is a well formed parenthetical expression, but $)($ is not.
2. Second, design the function `PDAdet` for running deterministic PDAs without $\varepsilon$ on line 86. Note that the determinism and lack of $\varepsilon$ makes the design and coding of the function much easier.

You can use the design of `pda1` as the template for designing `pda2`. Also note that there is a new class for PDAs, that builds on an NFA with $\varepsilon$ transitions, and additionally has a stack with methods for _popping_, _pushing_ and _peeking_ (where _peeking_ allows to see what is the top element on the stack).

Note the example `pda1` presents the description of this table:

|       |    $0$       |      $1$       |      $\varepsilon$    |
|-------|--------------|----------------|-----------------------|
| $q_0$ | $0$: $(q_0,00),(q_1,\varepsilon)$ | $0$: $(q_0,10)$ | $0$: - |
|       | $1$: $(q_0,01)$ | $1$: $(q_0,11),(q_1,\varepsilon)$ | $1$: - |
|       | $\varepsilon$: $(q_0,0)$ | $\varepsilon$: $(q_0,1)$ | $\varepsilon$: $(q_2,\varepsilon)$  |
| $q_1$ | $0$: $(q_1,\varepsilon)$ | $0$: - | $0$: - |
|       | $1$: - | $1$: $(q_1,\varepsilon)$ | $1$: - |
|       | $\varepsilon$: - | $\varepsilon$: - | $\varepsilon$: $(q_2,\varepsilon)$  |
| $q_2$ | $0$: - | $0$: - | $0$: - |
|       | $1$: - | $1$: - | $1$: - |
|       | $\varepsilon$: - | $\varepsilon$: - | $\varepsilon$: - |

This table is a representation of the transition function of a PDA recognizing the language of even length palindromes - Problem 8.38 (page 196) in the textbook. Note that this problem has a solution on page 229; it is this solution that is implemented here as `pda1` with the transition function given by the above table. 
