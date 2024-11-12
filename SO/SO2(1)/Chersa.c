/*
T3. Să se scrie un program C ce utilizează apeluri sistem şi se apelează:
 prog_name file1 file2. Argumentele sunt nume de fişiere aflate în 
 directorul curent; dacă lipsesc argumentele, se va afişa un mesaj de 
 eroare. Procesul părinte creează patru fii, din care primii doi 
 afişează conţinutul fişierelor date (a se lansa în execuţie comanda 
 corectă): primul fiu pentru file1 şi al doilea fiu pentru file2. Al 
 treilea fiu filtrează doar liniile care încep cu majusculă din file1 
 (NU citeşte fişierul, ci PREIA ceea ce trimite primul fiu). Al 
 patrulea fiu filtrează liniile care se termină cu “!” din file2
 (preluate de la al doilea fiu). Pentru filtrare, folosiți comanda 
 corespunzătoare. Procesul părinte primeşte rezultatele de la ultimii 
 doi fii, calculează numărul total de majuscule şi îl afişează. 
 Părintele aşteaptă terminarea fiilor şi afişează starea de exit a 
 fiecăruia, apoi se termină. Se pot folosi funcţii de bibliotecă DOAR 
 pentru formatări (printf), verificări de tip de caracter şi lansarea 
 în execuţie a comenzilor. Se vor verifica toate cazurile de eroare 
 pentru apelurile sistem și se vor afișa mesaje specifice, urmate de 
 terminarea execuției programului.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>

int temp;

void child_end()
{
	int pid_fiu'
	++temp;
	int status;
	
	if((pid_fiu=wait(&status))<0)
	{
		prerror("Error wait");
		exit(-9);
	}
	if(WIFEEXITED(status)){
		printf("S-a incheiat procesul fiu %d avand codul %d\n", pid_fiu,WEXITSTATUS(status));
	}
	else{
		printf("Eroare la WIFEEXITED %d\n",pid_fiu);
		exit(-10);
	}
	if(temp==4)
	{
		exit(0);
	}
}

int main(int argc, char* argv[])
{
		int inf1[2],inf2[2];
		pid_t pid1;
		pid_t pid2;
		pid_t pid3;
		pid_t pid4;
		
		if(argc == 3)//cu tot cu prog_name ar trebui sa fie 3
		{
			printf("putine argumente\n");
			exit(-1);
		}
		
		if(pipe(inf1) < 0  pipe(inf2)<0)
		{
			prerror("pipe");
			exit(-2);
		}
		
		int reader,writer;
			
		if((pid1=fork())<0)
		{
			prerror("fork1");
			exit(-3);
		}
		
		if(pid1==0)
		{
			int fd1 = open(argv[1],O_EDONLY);
		    char *buffer1 = (char*)calloc(20,sizeof(char));
			
			if(fd < 0)
			{
					prerror("open");
					exit(-4);
			}
			
			if(!buffer)
			{
				printf("memorie");
				exit(-5);
			}
			
			int reader,writer;
			
			while((readder = read(fd,(void*)buffer,3))>0)
				writer = write(inf1[1],buffer,reader);
			close(inf2);
		}
		
		if((pid2=fork())<0)
		{
			prerror("fork2");
			exit(-13);
		}
		
		if(pid2==0)
		{
			int fd2 = open(argv[2],O_EDONLY);
		    char *buffer2 = (char*)calloc(20,sizeof(char));	
			
			if(fd < 0)
			{
					prerror("open");
					exit(-6);
			}
			
			if(!buffer)
			{
				printf("memorie");
				exit(-7);
			}
			
			while((readder = read(fd,(void*)buffer,3))>0)
				writer = write(inf2[1],buffer,reader);
			close(inf2);
		}
		
		if((pid3=fork())<0)
		{
			prerror("fork3");
			exit(-14);
		}
		
		if(pid3==0)
		{
			if(dup2(inf1[1],0)<0);
			{
				printf("dup2 pipe1 cap intrare");
				exit(-12);
			}
			if(dup2(inf1[0],1)<0);
			{
				printf("dup2 pipe1 cap iesite");
				exit(-13);
			}
			execlp("grep","grep","[A-Z]{1}",(char*NULL));
			prerror("execlp\n");
			exit(1);
		}
		
		if((pid4=fork())<0)
		{
			prerror("fork4");
			exit(-15);
		}
		
		if(pid4==0)
		{
			if(dup2(inf2[1],0)<0)
			{
				printf("dup2 pipe2 cap intrare");
				exit(-15);
			}
			if(dup2(inf2[0],1)<0)
			{
				printf("dup2 pipe2 cap iesire");
				exit(-16);
			}
			execlp("grep","grep","!",(char*NULL));
			prerror("execlp\n");
			exit(1);
		}
		
		if(pid1>0&&pid2>0&&pid3>0&&pid4)
		{
			if(temp==4)
			{
				int c1;
				while((reader=read(inf1[0],(void*)buffer1,10))>0)
				{
					for(int i=0;i<reader;i++)
						if(buffer[i]>'A'&&buffer[i]<'Z')
						c1++
				}
			
				int c2;
				while((reader=read(inf2[0],(void*)buffer2,10))>0)
				{
					for(int i=0;i<reader;i++)
						if(buffer[i]>'A'&&buffer[i]<'Z')
						c2++
				}
			
				close(inf1);
				close(inf2);
				printf("%d",c1+c2);
			}
			struct sigaction action;
			memset(&action,0X00,sizeof(struct sigaction);
			action.sa_flags=0;
			action.sa_handler=child_end;
			if(sigaction(SIGCHLD,&action,NULL)<0)
			{
				prerror("Error SIGCHLD\n");
				exit(-8);
			}
			while(1)
			exit(0);
		}
}











