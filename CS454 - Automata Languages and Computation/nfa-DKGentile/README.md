[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/uH6puH-W)
# NFA: Design an NFA and create a function to run it

**Section 8.3.2** in the textbook deals with non-deterministic finite automata. Read that section, and pay particular attention to the example of an NFA in Figure 8.2.

In this assignment you are going to complete the function `NFA(input_string, nfa)` that runs an NFA. Note that the instructor has re-written the code from the first assignment, and now finite automata (FA) are defined as a class, and both DFAs and NFAs are defined with the FA class.

In particuar, modify the code on the following lines:
- line 28: initialize `current_states` (note the plural!)
- line 35: define `x` 
- line 48: define the NFA given in Figure 8.2; use, as an example, the definition of `dfa1` given in line 47
