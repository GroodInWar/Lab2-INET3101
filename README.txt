Gustavo Sakamoto de Toledo (detol001)

Description:
        The program was designed to take input information from the user and let the user manipulate it as it wants. The user can run the program in 
    two modes, debug and no-debug modes. The program can perform 7 operations/functions: print_all_records(), print_num_records(), reverse(), 
    print_size_database(), add_record(), delete_record(), print_number_of_accesses(), and exit(). 

Menu Definition and Usage:
    The menu has five options that a user can type to perform an operation after the '>' character printed on the screen. They are:
        1 - Performs the print_all_records() function
        2 - Performs the print_num_records() function
        3 - Performs the print_size_database() function
        4 - Performs the add_record() function
        5 - Performs the delete_record() function
        6 - Performs the print_number_of_accesses() function
        7 - Exits the program

Functions:
    1. add()
        Input Type(s) (if any):
            int num1 
            int num2
        Output Type:
            int
        Algorithm Description:
            Takes in two integers, num1 and num2, and returns the sum of the num1 and num2 as int data type. It has a complexity 
            of O(1).

    2. multiply()
        Input Type(s) (if any):
            float num1
            float num2
        Output Type:
            float
        Algorithm Description:
            Takes in two floats, num1 and num2, and returns the product of num1 and num2 as float data type. It has a complexity 
            of O(1).

    3. reverse()
        Input Type(s) (if any):
            char *str
        Output Type:
            void
        Algorithm Description:
            Takes in a character pointer, str, and defines a chararacter pointer, ptr, at the last char in the memory sequence 
            of str. Then, iteratively decrements ptr, until it reaches the first char in that str points to. It has a 
            complexity of O(n).

    4. compare()
        Input Type(s) (if any):
            char *str1
            char *str2
        Output Type:
            int
        Algorithm Description:
            Takes in two character pointers, str1 and str2, and iterates through both of them, while both of them are
            different than the '\0' character and they have they have the same character value. Finally, if they are 
            still the same after the iteration, then the function return 0, and 1 otherwise.