To run this parser follow these steps:
1) Docker build --tag=parser .
2) Docker run -it parser
3) ./bin/parser ../Path/To/Sample/


Currently the type checking for the following has not been implemented
    Typecase and Type alternatives
    calling methods on sub-classes 'bubbling' up to the super class
    some login within is_init with while loops
    Generally some logic around typing in returns isn't working

I plan to fix this stuff while working on code generation hopefully.
