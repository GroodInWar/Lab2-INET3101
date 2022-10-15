struct record {
    char *studentFullName;
    int studentID;
    char *className;
    char *classID;
};

struct record *DataBase;

int num_records = 0;

int num_of_accesses = 0;

// Prints all records in the database
void print_all_records();

// prints the number of records in the database
void print_num_records();

// Prints the size of the data base
void print_size_database();

// Prints the number of times the database has been accessed
void print_number_of_accesses();

// Adds a record to the database
int add_record(struct record *stdrecord);

// Deletes the the last structure in the database
int delete_record(); 