# Switch statement: 

Switch statement allows you to execute different parts of code based on the value of a single variable.

switch(variable)
{
    case value:
}

## Break

When a break statement is encountered inside a case block, 
the control of the program exits the switch statement entirely. 

Without a break statement, if a case block is matched, 
the program will continue executing the code in subsequent case blocks regardless of whether their conditions are true. 
This behavior is known as fall-through.