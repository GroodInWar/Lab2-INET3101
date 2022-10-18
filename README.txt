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
    1. print_all_records()
        Input Type(s) (if any):
            void
        Output Type:
            void
        Algorithm Description:
            The algorithm iterates though the database by using pointer arithmatics, and prints the contents of each structure the pointer is pointing at. The 
        algorithm has a complexity of O(n).

    2. print_num_records()
        Input Type(s) (if any):
            void
        Output Type:
            void
        Algorithm Description:
            The algorithm prints the value contained in the global variable num_records. The algorithm has a complexity of O(1).

    3. print_size_database()
        Input Type(s) (if any):
            void
        Output Type:
            void
        Algorithm Description:
            The algorithm iterates through the database by using pointer arithmatics, and adds the size of each attribute in the record (in case of pointers,
        the algorithm adds the size of the pointer plus the ammount of memory allocated for each of them). After the loop reaches its end, the algorithm 
        prints the size of the database in bytes. The Algorithm has a complexity of O(n).

    4. add_record()
        Input Type(s) (if any):
            struct record *stdrecord
        Output Type:
            int
        Algorithm Description: 
            The algorithm takes in a pointer to a struct record. If stdrecord pointer is null, the algorithm returns 1. If num_records is equal to 0, the 
        algorithm initiates a database, moves stdrecord to the space allocated for database (also icrements num_records and num_of_accesses), and returns 0. 
        If num_records is equal to 1, the algorithm initiates a new database with enough space for 2 struct records, moves the struct in the old database to 
        the new database, moves the stdrecord to the second space that was allocated for the database (also increments num_records and num_of_accesses), and
        returns 0. Otherwise, the algorithm allocates space for num_records+1 struct records, iterates through the old database and move its struct records 
        from it to the new database, moves stdrecord to the final space allocated (also increments num_records and num_of_accesses), and reutrns 0. The 
        algorithm has a complexity of O(n) in the worst case.

    5. delete_record()
        Input Type(s) (if any):
            void
        Output Type:
            int
        Algorithm Description:
            The algorithm uses a pointer to point to the last struct record in the database if num_records is greater than 0, frees its attributes, 
        decrements num_records and num_of_accesses, and returns 0. Otherwise, returns -1. The algorithm has a complexity of O(1).

    6.print_number_of_accesses()
        Input Type(s) (if any):
            void
        Output Type:
            void
        Algorithm Description:
            The algorithm prints the value stored in num_of_accesses. The algorithm has a complexity of O(1).