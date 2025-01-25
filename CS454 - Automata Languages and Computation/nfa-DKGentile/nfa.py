# NFA
#
# By: Michael Soltys
#
# An NFA simulator
# Usage: 
#   python3 nfa.py

class FA:
  def __init__(self, alphabet, states, transition, accepting_states):
    self.alphabet = alphabet
    self.states = states
    self.transition = transition
    self.accepting_states = accepting_states

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
            x = nfa.transition[i][j] #uses 'i' and 'j' to navigate the transition table
        current_states = x
    return current_states


def main():
    # Read in the input_string
    input_string = input()

    # Define a DFA
    dfa1 = FA(['0','1'],['q','r'],[['r','q'],['q','r']],{'q'})

    # Define the NFA given in Figure 8.2 for n=5
    nfa1 = FA( ['0', '1'], ['q0', 'q1', 'q2', 'q3', 'q4', 'q5'], 
              [    
                  [{'q0'}, {'q1'}],    # if input = 0, stay in q0. if input = 1, move to q1
                  [{'q2'}, {'q2'}],    # keep transitioning no matter the input 
                  [{'q3'}, {'q3'}],    
                  [{'q4'}, {'q4'}],    
                  [{'q5'}, {'q5'}],    
                  [{'q0'}, {'q1'}],    # if we reached q5, but there is more input, then:
                                       # revert to q0  when '0', go to q1 when '1'
              ],                        
              {'q5'}  #accepting state
    )
    #FA( ['0','1'] , ['q','r'], [['q','r'],['r','q']], {'q'} )
    # Run the DFA on the input string
    # final_state = DFA(input_string, dfa1)
    # if final_state in dfa1.accepting_states:
    #     print("Accept")
    # else:
    #     print("Reject")

    # Run the NFA on the input string
    final_states = NFA(input_string, nfa1)
    if set(final_states) & set(nfa1.accepting_states):
        print("Accept")
    else:
        print("Reject")

if __name__ == "__main__":
    main()
