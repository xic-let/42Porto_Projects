<h1> pipex </h1>
<h2>  it's all about handling pipes - a 42 Project </h2>

pipex is a project that aims to recreate the behavior of the shell command "< file1 cmd1 | cmd2 > file2", using the C programming language. The project includes a custom implementation of the pipex function as well as several helper functions.

<h1> Functionality </h1>

The pipex program uses the fork, execve, pipe, dup2, and waitpid system calls to redirect the input and output of two commands. The program creates two child processes, one for each command, and uses a pipe to redirect the output of the first command to the input of the second command.

The program reads the command line arguments and opens the input and output files using the open system call. It then creates a pipe using the pipe system call and forks two child processes. The first child process executes the first command using the execve system call, and redirects its output to the write end of the pipe using the dup2 system call. The second child process executes the second command using the execve system call, and redirects its input to the read end of the pipe using the dup2 system call. The parent process waits for the two child processes to complete using the waitpid system call, and writes the output of the second command to the output file using the write system call.

<h1> Contributions </h1>

Contributions to this project are welcome! If you have any suggestions or improvements, feel free to create a pull request or open an issue on GitHub.
