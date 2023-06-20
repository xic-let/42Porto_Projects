<h1>get_next_line</h1>

get_next_line is a project that aims to read a file descriptor line by line, until the end of file is reached.

<h1> Functionality </h1>

The get_next_line function reads a file descriptor (fd) line by line, until the end of file is reached. The function returns 1 if a line has been read, 0 if the end of file has been reached, or -1 if an error has occurred.

The function uses a static variable to keep track of the buffer between function calls. The function reads from the buffer if there is anything remaining, and reads from the file descriptor if the buffer is empty. 

<h1>Contributions</h1>

Contributions to this project are welcome! If you have any suggestions or improvements, feel free to create a pull request or open an issue on GitHub.
