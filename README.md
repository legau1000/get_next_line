# get_next_line
The goal of this project is to write a function that returns a read line from a file descriptor.
If there are no more lines to return, or if there is an error during the reading, the function will come back
NULL
.
You must define a macro called READ_SIZE
in your get_next_line.h file, which indicates the amount of characters to be read for each read() call.
#ifndef  READ_SIZE
#define READ_SIZE (/* value here */)
#endif  /* !READ_SIZE  */

The function should be prototyped as follows:
    char *get_next_line(int fd);

get_next_line must return the results without the ‘\n’

For test, write: make tests_run
A like this you will tests my criterions tests (Units_tests)
