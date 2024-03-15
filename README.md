# minishell
This project is about creating a simple shell. Yes, me own little bash. This project teach about processes and file descriptors.

### Allowed functions

There are 18 allowed functions for Pipex. All of them belong to the set of 51 functions allowed in minishell. I summarize them here. It is work in advance to understand minishell.


|Library|Function|Description|
|-------|-----|-------------------------------------------------------------------------------------|
|dirent.h|closedir||
|dirent.h|opendir||
|dirent.h|readdir||
|fcntl.h|open|The open() system call opens/creates the file specified by pathname in read/write mode if currente permission allow it. I used it with file1 and file2. <br> O_CLOEXEC Enable  the  close‐on‐exec  flag for the new file descriptor. It is essential in some multithreaded programs to avoid race conditions where one thread opens a file descriptor and attempts to set its close‐on‐exec flag using fcntl(2) at the same  time  as  another  thread  does  a fork(2)  plus execve(2).  Depending on the order of execution, the race may lead to the file descriptor returned by open() being unintentionally leaked to the program executed by the child process created by fork(2). |
|history.h|add_history||
|readline.h|readline||
|readline.h|rl_clear_history||
|readline.h|rl_on_new_line||
|readline.h|rl_redisplay||
|readline.h|rl_replace_line||
|signal.h|kill||
|signal.h|sigaction||
|signal.h|signal||
|stdio.h|perror|The perror() function produces a message on standard error describing the last error encountered during a call to a system or library function. The argument string s is printed, followed by a colon and a blank. Then an error message corresponding to the current value of errno and a new‐line. Joining "__func__" and "__LINE__" to string s i managed a more verbose error message.|
|stdio.h|printf||
|stdlib.h|exit|The exit() function causes normal process termination and the least significant byte of status (i.e., status & 0xFF) is returned to the parent. The C standard specifies two constants, EXIT_SUCCESS and EXIT_FAILURE, that may be passed to exit() to indicate successful or unsuccessful termination, respectively. All open streams are flushed and closed. Temporal files created are removed.|
|stdlib.h|free|The free() function frees the memory space pointed to by ptr, which must have been returned by a previous call to malloc().|
|stdlib.h|malloc|The malloc() function allocates size bytes and returns a pointer to the allocated memory. The memory is not initialized.|
|string.h|strerror|The strerror() function returns a pointer to a string that describes the error code passed in the argument errnum or "Unknown error nnn" if the error number is unknown. This string must not be modified by the application.|
|sys/ioctl.h|ioctl||
|sys/ioctl.h|fstat||
|sys/ioctl.h|lstat||
|sys/ioctl.h|stat||
|sys/wait.h|wait|All of these system calls are used to wait for state changes in a child of the calling process, and obtain information about the child whose state has changed. A state change is considered to be:<br><ul>the child terminated;</ul><br><ul> the child was stopped by a signal;</ul><br><ul> or the child was resumed by a signal.</ul><br><br>In the case of a terminated child, performing a wait allows the system to release the resources associated with the child; if a wait is not performed, then the terminated child remains in a "zombie" state (see NOTES below). The wait() system call suspends execution of the calling thread until one of its children terminates.|
|sys/wait.h|wait3||
|sys/wait.h|wait4||
|sys/wait.h|waitpid|The waitpid() system call suspends execution of the calling thread until a child specified by pid argument has changed state. By default, waitpid() waits only for terminated children, but this behavior is modifiable via the options argument, as described below.|
|term.h|tgetent||
|term.h|tgetflag||
|term.h|tgetnum||
|term.h|tgetstr||
|term.h|tgoto||
|term.h|tputs||
|termios.h|tcgetattr||
|termios.h|tcsetattr||
|unistd.h|access|access() checks whether the calling process can access the file pathname. With mode F_OK cheks if file exists. On success, zero is returned. On error -1 is returned and errno indicates the error.|
|unistd.h|chdir||
|unistd.h|close| close()  closes  a file descriptor, so that it no longer refers to any file and may be reused.  Any record locks (see fcntl(2)) held on the file it was associated with, and owned by the process, are removed (regardless of the file descriptor that was used to obtain the lock).  If fd is the last file descriptor referring to the underlying open file description (see open(2)), the resources associated with the open file description are freed; if the  file descriptor was the last reference to a file which has been removed using unlink(2), the file is deleted. Returns zero on succsess. On error returns -1 and errno indicates the error.  |
|unistd.h|dup|The  dup()  system call allocates a new file descriptor(unused lowest-numbered) that refers to the same open file description as the descriptor oldfd.After a successful return, the old and new file descriptors may be used interchangeably.  Since the two file descriptors refer to the same open file description, they share  file offset and file status flags |
|unistd.h|dup2| The  dup2()  system  call performs the same task as dup(), but instead of using the lowest‐numbered unused file descriptor, it uses the file descriptor number specified in newfd.  In other words, the file descriptor newfd is adjusted so that it now refers to the same open file description as oldfd.  If the file descriptor newfd was previously open, it is closed silently (no error reported) before being reused. on success returns the new file descriptor. On error returns -1 and errno indicates the error.|
|unistd.h|execve|execve()  executes  the program referred to by pathname, that can be a binary executable or a script starting with a shebang line. This causes the program that is currently being run by the calling process to be replaced with a new program, with newly initialized stack, heap, and (initialized and uninitialized) data segments.<br>execve()  does  not return on success, and the text, initialized data, uninitialized data (bss), and stack of the calling process are overwritten according to the contents of the newly loaded program. on error, -1 is returned and errno indicates the error. |
|unistd.h|fork| fork() creates a new process by duplicating the calling process.  The new process is referred to as the child process.  The calling process is referred to as the parent process.The child inherits copies of the parent’s set of open file descriptors.  Each file descriptor in the child refers to the same open file description (see open(2)) as the corresponding file descriptor in the parent.  On  success,  the  PID of the child process is returned in the parent, and 0 is returned in the child.  On failure, -1 is returned in the parent, no child process is created, and errno is set to indicate the error. |
|unistd.h|getcwd|Returns a null‐terminated string containing an absolute pathname that is the current working directory of the calling process.  The pathname is returned as the function result *and* via the argument buf, if present.<br> The getcwd() function copies an absolute pathname of the current working directory to the array pointed to  by  buf,  which  is  of length size. If  the  length of the absolute pathname of the current working directory, including the terminating null byte, exceeds size bytes, NULL is returned, and errno is set to ERANGE(allocate more memroy and try again); an application should check for this error, and allocate a larger  buffer  if  necessary. in \<limits.h\> there is PATH_MAX. getcwd() allocates the buffer dynamically using malloc(3) if buf is NULL.  In this  case,  the  allocated  buffer has the length size unless size is zero, when buf is allocated as big as necessary.  The caller should free(3) the returned buffer. |
|unistd.h|getenv||
|unistd.h|isatty|Tests whether a file descriptor refers to a terminal returnning 1. Otherwise 0 is returned and errno (EBAFF or ENOTTY). Fds 0, 1, 2 are attached to a TTY or PTS|
|unistd.h|pipe| pipe()  creates  a  pipe, a unidirectional data channel that can be used for interprocess communication.  The array pipefd is used to return two file descriptors referring to the ends of the pipe.  pipefd[0] refers to the read end of the pipe.  pipefd[1] refers to the write end of the pipe.  Data written to the write end of the pipe  is  buffered  by  the kernel until it is read from the read end of the pipe.|
|unistd.h|read| read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.If count is zero, read() may detect error EISDIR to check that fd is a directory. on success, the number of bytes read is returned.|
|unistd.h|ttyname|Returns a pointer to the null‐terminated pathname of the terminal device that is open on the file descriptor fd, or NULL on error (for example, if fd is not connected to a terminal) and errno is set to indicate the error. The return value may point to static data, possibly overwritten by the next call. ttyname(ttyslot()) returns current terminal name, either if it is a TTY (TeleTYpewriter) /dev/ttyn or a PTS(Pseudo-Terminal Slave) /dev/pts/n|
|unistd.h|ttyslot|Finds the slot ot the current user's terminal in some file.|
|unistd.h|unlink|unlink() deletes a name from the filesystem.  If that name was the last link to a file and no processes have the file open, the file is deleted and the space it was using is made available for reuse.  |
|unistd.h|write|write() writes up to count bytes from the buffer starting at buf to the file referred to by the file descriptor fd. If  count is zero and fd refers to a regular file, then write() may return a failure status EPIPE for a file descriptor conected to a pipe whose reading end is closed |


