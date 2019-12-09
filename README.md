To run this parser follow these steps:
1) Docker build --tag=parser .
2) Docker run -it parser
//Once in the image
3) bash quack.sh <path/to/quackfile>


Currently the following has not been implemented:
    -Typecase and Type alternatives
    -No string PLUS
    -Some typing rules probably don't work correctly (I had to add a lot of spaghetti code to typechecking to make codegen work so hopefully it is all fixed)
    -There are a lot of memory leaks probably. It has been a while since I've done a non-garbage collected language so my Type checking doesn't really do a good job with memory management (since it has to pass structures to the codegen so it can't clean them up)

Working and choices:
    -(As far as I can tell) Dynamic Dispatch, Inheritance, Methods and such
    -If a variable is supposed to be instantiated within a control statement (like one in both branches of an if) it must be instantiated before the control statement
    -INT has all basic arithmatic (add, subtract, multiply) but no divide
    -All but 4 of the testbench tests complete succesfully, and 3 of those are because of no typecasing


