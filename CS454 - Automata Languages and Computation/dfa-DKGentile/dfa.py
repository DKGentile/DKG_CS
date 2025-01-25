# Automata - A1
#
# By: Michael Soltys
#     Demitri Gentile
#
# A DFA simulator
# Usage: 
#   python3 dfa.py 0110010

# Write a dimulator of a deterministic finite automata

import numpy as np
import sys

#states for referencing
'''

language = ['a','b']

states = {
    ('0','0'), q
    ('0','1'), r
    ('0','2'), r
    ('1','0'), r
    ('1','1'), r
    ('1','2'), r
}

'''

cState = [0,0] #current state, also accepting state

'''
# 'ticker()' will analyze input 'inPu'.
# will then increment elements of 'cState[]' depending on value of 'inPu'.
# when cState[0] == 1, cState[0] = 0; these values represent whether or
  not cState[0] is odd or even (divisible by 2).
# cState[1] will increment from 0 to 2, when cState[1] == 2, cState[1] = 0;
  this is meant to represent cState[1] % 3.
# 'sys.exit(1)' will be called when 'inPu' is not a valid value. not
  nessesary, but easier on the eyes than the default error message
'''

def ticker(inPu):
    match inPu:
        case 'a':
            match cState[0]:
                case 1:
                    cState[0] = 0
                case 0:
                    cState[0] = 1
        case 'b':
            match cState[1]:
                case 0:
                    cState[1] = 1
                case 1:
                    cState[1] = 2
                case 2:
                    cState[1] = 0
        case _:
            print("\nValue: '"+inPu+"'")
            print( "\033[91m" + "INVALID INPUT" + "\033[0m" + "\n" )
            sys.exit(1)


#following function could probably be squeezed into main()
def DFA(input):
    for x in input:
        ticker(x)
    return cState == [0,0]

def main():
    # Read in the input_string
    input_string = str(sys.argv[1])
    #input_string = input()
    #print(input_string)
    final_state = DFA(input_string) # Run the DFA in the input_string

    if final_state:
        print("\nAccept\n")
    else:
        print("\nReject\n")

if __name__ == "__main__":
    main()
