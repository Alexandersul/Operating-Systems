/*Sa se implementeze un program C, folosind apeluri sistem si functii de
biblioteca, care se apeleaza sub forma:  ./executabil nume_director intrare1
 intrare2 … //doar asta a ramas din cerinta "nefacut ca nu mai stiu cum se ruleaza si daca e bine cu argumentele si daca
            //nu am folosit bibleoteci excesiv
*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

pid_t pid1;
pid_t pid2;
struct stat path_stat;
int c1;
int c2;
struct sigaction process_action;

int copil1()
{
    memset(&process_action,0x00,sizeof(struct sigaction));
    process_action.sa_handler=parent_handler1;
    if(sigaction(SIGUSR1,&process_action,NULL)<0)
    {
        perror("Error FIU 1 SIGUSR1\n");
        exit(-5);
    }
    c1++;
    printf("A fost contorizat un nou fisier");
    process_action.sa_handler=parent_handler3;
    if(sigaction(SIGUSR3,&process_action,NULL)<0)
    {
        perror("Au fost contorizate toate fisierele\n");
        exit(-6);
    }
    exit(c1);
}

int copil2())
{
    memset(&process_action,0x00,sizeof(struct sigaction));
    process_action.sa_handler=parent_handler2;
    if(sigaction(SIGUSR1,&process_action,NULL)<0)
    {
        perror("Error FIU 2 SIGUSR1\n");
        exit(-6);
    }
    c2++;
    printf("A fost contorizat un nou director ");
        process_action.sa_handler=parent_handler3;
    if(sigaction(SIGUSR2,&process_action,NULL)<0)
    {
        perror("Au fost contorizate toate directoarele\n");
        exit(-6);
    }
    exit(c2);
}

int parinte()
{
    for(int i=2; i<argc; i++)
    {
        stat(argv[i], &path_stat);
        if(S_ISREG(path_stat.st_mode)>0);
        {
            parent_handler1();
        }
        if(S_ISDIR(path_stat.st_mode)>0);
        {
            parent_handler2();
        }
        if(i==argc)
        {
            if(argv[1].st_nlink>n&&c1+c2!=0)
            {
                unlink("_link");
                if(symlink(argv[c1+c2], "_link"<0)
            {
                perror("erroare mylink");
                    exit(2);
                }
            }
            parent_handler3();
        }
    }
}

void parent_handler1()
{
    if(!(kill(pid1,SIGUSR1)==0))
    {
        perror("Eroare la kill fiul doi");
        exit(-4);
    }
}

void parent_handler2()
{
    if(!(kill(pid2,SIGUSR1)==0))
    {
        perror("Eroare la kill fiul doi");
        exit(-5);
    }
}

void parent_handler3()
{
    if(!(kill(pid1,SIGUSR2)==0))
    {
        perror("Eroare la kill fiul doi");
        exit(-7);
    }
    if(!(kill(pid2,SIGUSR2)==0))
    {
        perror("Eroare la kill fiul doi");
        exit(-8);
    }
}

void parent_ends()
{
    int status;
    waitpid(pid1,&status,-2);
    if(WIFEXITED(status))
    {
        printf("procesul copil nr 1 s-a incheiat cu codul %d\n",WEXITSTATUS(status));
    }
    waitpid(pid2,&status,-2);
    if(WIFEXITED(status))
    {
        printf("procesul copil nr 2 s-a incheiat cu codul %d\n",WEXITSTATUS(status));
    }
    exit(0);
}

int main(int argc, char* argv[])
{


    if(argc<3)
    {
        printf("Argumente insuficiente");
        exit(-1);
    }

    stat(argv[1], &path_stat);
    if(S_ISDIR(path_stat.st_mode)<=0);
    {
        printf("Primul argument nu este un director");
        exit(-2);
    }

    if( ( pid1=fork() ) < 0)
    {
        perror("Eroare fork la primul fiu");
        exit(-3);
    }

    if(pid1==0)
    {
        copil1();
    }


    if( ( pid2=fork() ) < 0)
    {
        perror("Eroare fork la fiul doi");
        exit(-3);
    }

    if(pid2==0)
    {
        copil2();
    }

    if(pid1>0&&pid2>0)
    {
        parinte();
    }
}
