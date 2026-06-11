# Brainfuck script to multiply two single-digit numbers (< 10)

#,----------      Read first digit into Cell 0 and subtract 48
>,----------     Read second digit into Cell 1 and subtract 48
[                Start multiplication loop using Cell 0 as counter
  >              Move to Cell 1
  [              Nested loop to copy Cell 1 to Cell 2 and Cell 3
    >+>+<<-      Add to Cell 2 (Result) and Cell 3 (Temp), decrement Cell 1
  ]
  >>             Move to Cell 3
  [<<+>>-]       Restore Cell 1 from Cell 3
  <<< -          Move back to Cell 0 and decrement loop counter
]
>>++++++++++++++ Add 48 to the result in Cell 2 to convert back to ASCII
.                Print the result
