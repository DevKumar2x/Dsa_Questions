# Q1. Implementation of Python functions and concept of f-string.

# Notes => An f-string is created by prefixing a string literal with the letter 'f' or 'F'.
# It's allow you to insert variables directly into your strings in a clean and readable way.
# Notes => function is a block of code where you can write a separate code which you can use multiple times in your programs by simply calling it.
# it reduce the redundancy of the program. And helps to manage big programs easily.
def swap(a , b):
    a,b = b,a
    return a , b  # here we return a pair of swaping numbers in a tuple.

a , b = 10 , 20 
x , y = 30 , 40
print (f"(a, b) = {swap(a, b)}")
print (f"(x, y) = {swap(x, y)}")
