//
//  CreateProcess.c
//  This program forks two seperate process and three process print 'a'
//  'b' and 'c' respectively.
//
//  Created by YeWenting. on 26/10/2016.
//  Copyright © 2016 School of Computer Science. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid = -1;
    
    /* Create the first child process */
    while (pid < 0) pid = fork();
    if (pid == 0)           /* child */
        printf("I'm the child A\n");
    
    /* Create the second child process */
    else
    {
        pid = -1;
        
        while (pid < 0) pid = fork();
        if (pid == 0)       /* child */
            printf("I'm the child B\n");
        else
            printf("I'm the parent\n");
    }
    return 0;
}
