// OS Concepts Project 1
// By Ben Rust - Feb 22nd, 2020
//
//


#include <iostream>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


using namespace std;

int main(){

	cout << "Hello World!\n";

	
//*************************************
//CREATE PIPES AND THEN DO THE FORK

	int pfds1[2]; // send input from parent to child
	int pfds2[2]; // send input from child to parent 
	
	if((pipe(pfds1) == -1) || (pipe(pfds2) == -1)){
		cout << "Piping failed, FIXME" << endl;
	return -1;
	}


// CREATE THE FORK
	int pid = fork();
	
	if(pid < 0){
		cout << "Failed to create child process, FIXME to retry" << endl;
	}else if(pid == 0){
	// Child Process
		string cs1 = "child";
		cout << "This is the child writing to parent" << endl;
		write(pfds2[1], "Hewwo", 7);	// write the value of cs1 to parent 
		

	}else{
	// Parent Process 
		string ps1 = "parent";
		char buf[30];
		cout << "This is the parent, the pid of the child is " << pid << endl; 

		read(pfds2[0], buf, 12); 
	cout << "This is the string from child: " << buf << "!" << endl;


	}


//***************************************



	return 0;
}

	


















