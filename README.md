<h1> SIMPLE SHELL PROJECT </h1>
<h2> Description </h2>
<p> This repositry contains the files to simulate a basic Unix shell with it respective commands. It uses the POSIX API to implement many of the same functionalities of the first Ken Thompson's Shell.</p>

<p> This predominantly used calls are read, write, open, execve, exit,fflush, fork, free, malloc, getline, isatty, perror, strtok, wait and waitpid.
</p>

<p>This simple shell is a Shell interface written in C programming language that gives to the user a prompt *Hell_Shell>>*, after it accepts, it executes a user inputted command in a separate process called child process.
</p>
<h2> FEATURES </h2>
<ul>
 <li>This program dipalys a promt and waits that the user types a command. A command line always ends with a newline (when uer push ENTER key).</li>
<li> The prompt displayed again each time a command has been executed. </li>
<li> When the uer enter exit, Hell shell willl end and return the sttus 0.</li>
<li> When the user enter exit [status],Hell hell will end and returns the inputted status, where status is a vlaue from 0 to 255</li>
<li>The user could top the program using Ctrl+D(end of file).</li>
<li>The shell handles the command line with arguments and pathways.</li>
<li> The program does not quit when the user imputs ^C(Ctrl+C).
<li> The program print the current environment when the user types env.</li>
<li> This program executes the most common shell commands as ls, grep, find, pwd, rm, cp, mv, exit,env, history, etc.. wit arguments</li>
<li> If an executable cannot be found , it prints an error message and displays the prompt again </li>
<li> This Shell support commentaries using #,</li>
<li>The Hell Shell does Not support wildcard characters such as ls asteric.dat in parameters(or commands).</li>
<li> This shell does Not support pipes|, shell logical operators as && or ||, neither commands separator;</li>


<h2> Proccess Description </h2>
<p> The next steps are a brief description about hoe the shell works: </p>
<ol>
<li> First, the parent process is created when the user run the program. </li>
<li> Then, the isatty() function using STDIN_FILENO file descriptor -fd- to tests if there is an open file descriptor referring to the terminal. If isatty() return 1, the prompt is showed using write() with STDOUT_FILENO as fd and waits for an input user command line.</li>

<li> When the user types a command, getline() function reads an entire line from the stream and strtok() function breaks the inputted commad into a sequence of non-empty tokens.
<li>Next, it creates a separate child process using fork() that perfors the iputted command.Unless otherwise is specifed, the parent waits for the child to exit before continuing.</li>
<li> After tokening the command ,execve() function brings and executes it, it frees all allocated emory with free().</li>
<li> Finally, the program returns the main process: prints the prompt, waits for another user input.</li>
