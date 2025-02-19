# Pipex

## Introduction
`Pipex` is a project that explores UNIX pipes and process management by replicating the behavior of shell pipelines. The program takes file input, executes two commands using pipes, and writes the output to a specified file. This provides hands-on experience with system calls like `fork`, `pipe`, `dup2` and `execve`.

## Features
- Executes two commands in a pipeline.
- Handles file redirections.
- Implements process creation and execution.
- Proper error handling and memory management.

## Usage
### Compilation
To compile `pipex`, use the provided `Makefile`:
```sh
git clone https://github.com/ElmehdiBennix/Pipex_42.git
cd Pipex_42
make
```
This will generate the `pipex` executable.

### Running the Program
To execute `pipex`, use the following syntax:
```sh
./pipex file1 cmd1 cmd2 file2
```
This should behave like the shell command:
```sh
< file1 cmd1 | cmd2 > file2
```

### Example
```sh
./pipex infile "ls -l" "wc -l" outfile
```
Equivalent to:
```sh
< infile ls -l | wc -l > outfile
```

## Error Handling
The program ensures proper error handling by:
- Validating file access and command execution.
- Preventing segmentation faults and memory leaks.
- Handling invalid arguments and permissions.

## Bonus Features
- Support for multiple pipes:
  ```sh
  ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
  ```
- Support for `here_doc` input:
  ```sh
  ./pipex here_doc LIMITER cmd cmd1 file
  ```

## Makefile Targets
- `make`: Compile `pipex`.
- `make clean`: Remove object files.
- `make fclean`: Remove executables and object files.
- `make re`: Recompile everything.
