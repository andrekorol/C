#include <stdio.h>

int main() {
    /*! \enum months
     *
     *  Relates months names to its numbers
     */
    enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
    printf("January is the month number %d of the year\n", JAN);

    return 0;
}
