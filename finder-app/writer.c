#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);
    if(argc != 3) {
        syslog(LOG_ERR, "Invaid number of arguments.Usage: %s <filename> <text>", argv[0]);
        fprintf(stderr, "Error:Invaid number of arguments.Usage: %s <filename> <text>", argv[0]);
        closelog();
        exit(EXIT_FAILURE);

    }

    const char *writefile= argv[1];
    const char *writestr = argv[2];

    FILE *file=fopen(writefile, "w");
    if(file == NULL) {
        syslog(LOG_ERR, "Error opening file: %s", strerror(errno));
        fprintf(stderr, "Error opening file: %s", strerror(errno));
        closelog();
        exit(EXIT_FAILURE);
    }
    if(fprintf(file, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Error writing to file: %s", strerror(errno));
        fprintf(stderr, "Error writing to file: %s", strerror(errno));
        fclose(file);
        closelog();
        exit(EXIT_FAILURE);
    }
    syslog(LOG_DEBUG, "Writing '%s' to %s", writestr, writefile);
    fclose(file);
    closelog();

    return EXIT_SUCCESS;
}