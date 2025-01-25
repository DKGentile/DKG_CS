# Deterministic PDA
#
# By: Michael Soltys
#
# An NFA with epsilon transitions simulator
# Usage: 
#   python3 nfa-e.py

class FA:
  def __init__(self, alphabet, states, transition, accepting_states):
    self.alphabet = alphabet
    self.states = states
    self.transition = transition
    self.accepting_states = accepting_states

class PDA:
    # We make two simplifying assumptions:
    #   1. The stack alphabet is the same as input alphabet plus the 'bottom of stack' extra symbol
    #   2. The stack is initialized with a single 'bottom of stack' symbol
    def __init__(self, alphabet, states, transition, accepting_states, stack):
        self.alphabet = alphabet
        self.states = states
        self.transition = transition
        self.accepting_states = accepting_states
        self.stack = stack

    def push(self, symbol):
        self.stack.append(symbol)

    def pop(self):
        if len(self.stack)>1:
            self.stack.pop()
    
    def peek(self):
        return self.stack[-1]

def DFA(input_string, dfa):
    # set current_state to initial state
    current_state = dfa.states[0]
    # run through the input string
    for symbol in input_string:
        i = dfa.states.index(current_state) 
        j = dfa.alphabet.index(symbol) 
        current_state = dfa.transition[i][j]
    return current_state

def NFA(input_string, nfa):
    # set current_state to initial state
    current_states = {nfa.states[0]}
    # run through the input string
    for symbol in input_string:
        x = set()
        for state in current_states:
            i = nfa.states.index(state) 
            j = nfa.alphabet.index(symbol)
            x = x.union(nfa.transition[i][j]) 
        current_states = x
    return current_states

def ECLOSURE(states, nfa):
    x = xe = states
    while True:
        for y in x:
            i = nfa.states.index(y)
            j = nfa.alphabet.index('e')
            xe = xe.union(nfa.transition[i][j])
        if len(x) == len(xe):
            break
        else:
            x = xe
    return xe

def NFAe(input_string, nfa):
    # set current_state to initial state
    current_states = ECLOSURE({nfa.states[0]},nfa)
    # run through the input string
    for symbol in input_string:
        x = set()
        for state in current_states:
            i = nfa.states.index(state) 
            j = nfa.alphabet.index(symbol)
            x = x.union(nfa.transition[i][j]) 
        current_states = ECLOSURE(x, nfa)
    return current_states

def PDAdet(input_string, pda):
    current_state   =   pda.states[0]  
    stack   =   pda.stack[:]
    l1,l2=')','('
    nod =   list(input_string)
    for x in input_string:
        top = stack[-1]
        state = (current_state, x, top)        
        if state in pda.transition:
            stack_action = pda.transition[state]    
            if stack_action == []:
                pda.pop()
            else:
                for action in stack_action:
                    pda.push(action)
    c1, c2 = 0, 0
    for x in nod:
        if x == l1:
            c1+=1
        elif x == l2:
            c2+=1
    return c1==c2

    


def main():
    # Read in the input_string
    input_string = input()

    # Define a DFA
    dfa1 = FA(['0','1'],['q','r'],[['r','q'],['q','r']],{'q'})

    # Define the NFA given in Figure 8.2
    nfa1 = FA(['0','1'],['0','1','2','3','4','5'],
            [[{'0'},{'0','1'}],[{'2'},{'2'}],[{'3'},{'3'}],[{'4'},{'4'}],[{'5'},{'5'}],[{},{}]],{'5'})

    # Define the NFA with epsilon transitions given in Figure 8.3
    nfa2 = FA(['0','1','2','3','4','5','6','7','8','9','+','-','.','e'],
              ['0','1','2','3','4','5'],
              [[{},{},{},{},{},{},{},{},{},{},{'1'},{'1'},{},{'1'}],
               [{'1','4'},{'1','4'},{'1','4'},{'1','4'},{'1','4'},{'1','4'},{'1','4'},{'1','4'},{'1','4'},{'1','4'},{},{},{'2'},{}],
               [{'3'},{'3'},{'3'},{'3'},{'3'},{'3'},{'3'},{'3'},{'3'},{'3'},{},{},{},{}],
               [{'3'},{'3'},{'3'},{'3'},{'3'},{'3'},{'3'},{'3'},{'3'},{'3'},{},{},{},{'5'}],
               [{},{},{},{},{},{},{},{},{},{},{},{},{'3'},{}],
               [{},{},{},{},{},{},{},{},{},{},{},{},{},{}]],
              {'5'})
    

    pda1 = PDA(['0','1','e'],                                       # Alphabet (input & stack) with epsilon (e)
               ['0','1','2']                                        # States
               ,
               [[[{('0','00'),('1','e')},{('0','01')},{('0','0')}], # Transition
                 [{('0','10')},{('0','11'),('1','e')},{('0','1')}], # First row
                 [{},{},{('2','e')}]]                               # 
                    ,
                [[{('1','e')},{},{}],                               # Transition
                 [{},{('1','e')},{}],                               # Second row
                 [{},{},{('2','e')}]]                               # 
                    ,
                [[{},{},{}],                                        # Transition
                 [{},{},{}],                                        # Third row
                 [{},{},{}]]                                        #
                 ]
                ,
                 {'2'},                                             # Accepting states
                 ['bottom'])                                        # Bottom of the stack symbol
    
    pda2 = PDA(
            ['(', ')','e'],['q', 'e'],                                            
            {('q', '(', 'e'): ('q', ['(', 'e']),('q', '(', '('): ('q', ['(', '(']),('q', ')', '('): ('q', []),                             
                ('q', '', 'e'): ('q', ['e'])             
            },
            {'e'},
            ['bottom']                                                  
            )  
    # Run the DFA on the input string
    #final_state = DFA(input_string, dfa1)
    # if final_state in dfa1.accepting_states:
    #     print("Accept")
    #else:
    #     print("Reject")

    # Run the NFA on the input string
    # final_states = NFA(input_string, nfa1)
    #if set(final_states) & set(nfa1.accepting_states):
    #   print("Accept")
    #else:
    #   print("Reject")

    # Run the NFAe on the input string
    #final_states = NFAe(input_string, nfa2)
    #if set(final_states) & set(nfa2.accepting_states):
    #   print("Accept")
    #else:
    #   print("Reject")

    # Run the PDA on the input string
    final_states = PDAdet(input_string, pda1)
    if final_states:#set(final_states) & set(pda2.accepting_states):
        print("Accept")
    else:
        print("Reject")

if __name__ == "__main__":
    main()
