To run this parser follow these steps:
1) Docker build --tag=parser .
2) Docker run -it parser
//Once in the image
3) bash quack.sh <path/to/quackfile>


Currently the following has not been implemented:
    -Typecase and Type alternatives
    -No string PLUS
    

Working and choices:
    -(As far as I can tell) Dynamic Dispatch
    -If a variable is supposed to be instantiated within a control statement (like one in both branches of an if) it must be instantiated before the control statement
    -INT has all basic arithmatic (add, subtract, multiply) but no divide


I plan to fix this stuff while working on code generation hopefully.
