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



# Q2. import calender module and use it to print the calender of given year and month.
import calendar
yy = 2025
mm = 8
print(calendar.month(yy,mm))




# Q3. Create a student grading system using Python that has the following functionalities:
# 1. Entering the Grades of a student
# 2. Removing a student from the system
# 3. Calculating the average grades of students
# The user should be able to select whether he/she wants to remove a student, enter grades for a
# student or find the average grades.
# Also add login system to the Grade Central -- only admins can access Grade Central.

ex_dict = {'sam' : [43, 65]}          
admins = {
    'Dev' : 'pass123',
    'user1' : 'pass1'             
}

def Enter_grade():
    name = input("Student name : ")
    grade = int((input("Grade : ")))
    if name in ex_dict :
        print("Adding Grade...")
        ex_dict[name].append(grade)
    else:
        print("Adding new student data to the Grade Central...")
        ex_dict[name] = [grade]
    print(ex_dict , '\n') 

def Remove_grade():
    name = input("Which Student to remove : ")
    print("Removing Student...")
    if name in ex_dict :
        del ex_dict[name]
        print(ex_dict)
    else :
        print("Student does not exits.")
    
def Average():
    name = input("Which Student average you want to calculate : ")
    avg = 0
    cnt = 0
    if name in ex_dict:
        list = ex_dict[name]
        for i in list :
            cnt += 1
            avg = avg + i
        avg = avg / cnt
        print("Average is" , avg , '\n')
    else:
        print("Student not exist.")
    
def main():
    run = False
    username = input("Enter username : ")
    password = input("Enter password : ")
    
    if username in admins :
        if admins[username] == password:
            run = True
        else:
            print("Wrong password. Please try again later.")
    else:
        print("Wrong username. Please try again later.")
    
    while(run):
        print("\nWelcome", username ,"to Grade Central\n")
        print("[1] Enter Grade")
        print("[2] Remove Student")
        print("[3] Students Average Grade")
        print("[4] Exit")
        
        choice = input("What would you like to do today? [Enter a number] : ")
        
        if(choice == "1"):
            Enter_grade()
        
        elif(choice == "2"):
            Remove_grade()
        elif(choice == "3"):
            Average()
        elif(choice == "4") :
            print("Exit Grade Central. Visit again.")
            break
        else :
            print("Invaid input.")

if __name__ == '__main__':
    main()
    

#Q4.          ...(To be added next)...
