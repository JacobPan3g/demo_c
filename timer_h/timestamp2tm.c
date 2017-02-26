/* output:
 * 1384936600: 2013-11-20 08:36:40
 */
#include <stdio.h>
#include <time.h>
 
int main(int argc, const char * argv[])
{
    time_t t;
    struct tm *p;
    t=1384936600;
    p=gmtime(&t);   // p don't need to free?
    char s[100];
    strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", p);
    printf("%d: %s\n", (int)t, s);
    //printf("year: %d\n", p->tm_year);
    return 0;
}
