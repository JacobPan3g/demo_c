#include <stdio.h>
#include <time.h>
 
int main(int argc, const char * argv[])
{
    struct tm tmp_time = {0};
    //strptime("20131120","%Y%m%d",&tmp_time);
    strptime("20131120-00:00:01","%Y%m%d-%H:%M:%S",&tmp_time);
    time_t t = mktime(&tmp_time);
    printf("%ld\n",t);
    return 0;
}
