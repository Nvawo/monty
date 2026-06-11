# Brainfuck script to multiply two single-digit numbers (< 10)

,------------------------------------------------  Read first digit into Cell 0 and subtract 48
>,------------------------------------------------ Read second digit into Cell 1 and subtract 48
<                                                  Move back to Cell 0 (our loop counter)

[                                                  Loop while Cell 0 is not 0
    >                                              Move to Cell 1
    [
        >+>+<<-                                    Move Cell 1 value to Cell 2 (Result) and Cell 3 (Temp)
    ]
    >>                                             Move to Cell 3
    [<<+>>-]                                       Restore Cell 1 from Cell 3
    <<< -                                          Move back to Cell 0 and decrement
]

>>++++++++++++++++++++++++++++++++++++++++++++++++ Add 48 to Cell 2 to convert back to ASCII
.                                                  Print the result
