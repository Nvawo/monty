# Move the starting point right to create a safety buffer zone
>>

# Layout now:
# Cell 0: Empty | Cell 1: Empty | Cell 2: Num1 | Cell 3: Num2 | Cell 4: Result | Cell 5: Temp

,------------------------------------------------  Read first digit into Cell 2
>,------------------------------------------------ Read second digit into Cell 3
<                                                  Return to Cell 2 (Loop Counter)

[                                                  While Cell 2 != 0
    >                                              Move to Cell 3
    [>+>+<<-]                                      Move Cell 3 to Cell 4 and Cell 5 (Ends on Cell 3)
    >>                                             Move to Cell 5
    [<<+>>-]                                       Restore Cell 3 from Cell 5 (Ends on Cell 5)
    <<< -                                          Move back to Cell 2 and decrement
]

>>++++++++++++++++++++++++++++++++++++++++++++++++ Move to Cell 4, add 48 for ASCII
.                                                  Print the result
