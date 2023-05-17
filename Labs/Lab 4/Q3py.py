#part a
# in python, you don't use typedef structure. the student1
# is initialized using an array, like in third last line.

# in functions 2,3 a pointer is passed any edits you make 
# in the function are reflected outside. there is no
# such thing as pointers in python, but any edits you make To 
# the contents of the array are reflected outside the function.

# in function 1, the data item itself is sent through,
# so the function edits a local copy of the data item

#part b

def change_name1_wrong(student1):
    student1[0] = "ac"



student1 = ["ab", 20]
change_name1_wrong(student1)
print(student1)