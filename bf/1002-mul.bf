# Brainfuck script to multiply two single-digit numbers (< 10)

,------------------------------------------------  Read first digit into Cell 0 and subtract 48
>,------------------------------------------------ Read second digit into Cell 1 and subtract 48
<                                                  Move back to Cell 0 (our main loop counter)

[                                                  While Cell 0 != 0
    >                                              Move to Cell 1
    [>+>+<<-]                                      Move Cell 1 to Cell 2 and Cell 3 (Ends on Cell 1)
    
    >>                                             Move from Cell 1 to Cell 3
    [<<+>>-]                                       Restore Cell 1 from Cell 3 (Ends on Cell 3)
    
    <<< -                                          Move from Cell 3 back to Cell 0, and decrement counter
]

>>++++++++++++++++++++++++++++++++++++++++++++++++ Move to Cell 2 and add 48 to convert back to ASCII
.                                                  Print the result
