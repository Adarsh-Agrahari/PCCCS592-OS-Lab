# Linux Commands

## 1. `pwd`

**Common Name:** Print Working Directory

**Syntax:** `pwd`

**Purpose:** Display the current working directory.

**Example:**
```bash
$ pwd
/home/user/documents
```

## 2. `ls`

**Common Name:** List

**Syntax:** `ls [options] [directory]`

**Purpose:** List files and directories in the specified directory.

**Example:**
```bash
$ ls
file1.txt  file2.txt  folder1  folder2
```

## 3. `mkdir`

**Common Name:** Make Directory

**Syntax:** `mkdir [directory]`

**Purpose:** Create a new directory.

**Example:**
```bash
$ mkdir new_folder
(No output on success)
```

## 4. `rm`

**Common Name:** Remove

**Syntax:** `rm [options] [file/directory]`

**Purpose:** Remove files or directories.

**Example:**
```bash
$ rm old_file.txt
(No output on success)
```
## 5. cd`

**Common Name:** Change Directory

**Syntax:** `cd [directory]`

**Purpose:** Change the current working directory.

**Example:**
```bash
$ cd new_folder
(No output on success)
```

## 6. `cat`

**Common Name:** Concatenate

**Syntax:** `cat [file]`

**Purpose:** Display the content of a file.

**Example:**
```bash
$ cat file1.txt
Contents of file1.txt
```

## 7. `rmdir`

**Common Name:** Remove Directory

**Syntax:** `rmdir [directory]`

**Purpose:** Remove an empty directory.

**Example:**
```bash
$ rmdir empty_folder
(No output on success)
```

## 8. `cp`

**Common Name:** Copy

**Syntax:** `cp [options] source destination`

**Purpose:** Copy files or directories.

**Example:**
```bash
$ cp file1.txt new_folder/
(No output on success)
```

## 9. `mv`

**Common Name:** Move

**Syntax:** `mv [options] source destination`

**Purpose:**  Move or rename files or directories.

**Example:**
```bash
$ mv file1.txt new_folder/
(No output on success)
```

## 10. `uname`

**Common Name:** Print System Information

**Syntax:** `uname [options]`

**Purpose:** Print information about the system.

**Example:**
```bash
$ uname -a
Linux hostname 4.15.0-20-generic #21-Ubuntu SMP Tue Apr 24 06:16:15 UTC 2018 x86_64 GNU/Linux
```

## 11. `locate`

**Common Name:** Find by Name

**Syntax:** `locate [file/directory]`

**Purpose:** Quickly find the location of files or directories.

**Example:**
```bash
$ locate file1.txt
/path/to/file1.txt
```

## 12. `touch`

**Common Name:** Touch

**Syntax:** `touch [file]`

**Purpose:** Create an empty file or update file timestamps.

**Example:**
```bash
$ touch new_file.txt
(No output on success)
```

## 13. `ln`

**Common Name:** Link

**Syntax:** `ln [options] source [link_name]`

**Purpose:** Create links between files.

**Example:**
```bash
$ ln -s file1.txt link1
(No output on success)
```

## 14. `clear`

**Common Name:** Clear Screen

**Syntax:** `clear`

**Purpose:** Clear the terminal screen.

**Example:**
```bash
$ clear
(Clears the screen)
```

## 15. `ps`

**Common Name:** Process Status

**Syntax:** `ps [options]`

**Purpose:** Display information about active processes.

**Example:**
```bash
$ ps aux
USER       PID  %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
user     12345  0.0  0.0 123456 7890 pts/0    S+   10:00   0:00 command
```

## 16. `man`

**Common Name:** Manual

**Syntax:** `man [command]`

**Purpose:** Display the manual page for a command.

**Example:**
```bash
$ man ls
LS(1)                          User Commands                          LS(1)
```

## 17. `grep`

**Common Name:** Global Regular Expression Print

**Syntax:** `grep [options] pattern [file]`

**Purpose:** Search for a pattern in a file.

**Example:**
```bash
$ grep "keyword" file.txt
Lines containing 'keyword' in file.txt
```

## 18. `echo`

**Common Name:** Echo

**Syntax:** `echo [options] [string]`

**Purpose:** Print a message to the terminal.

**Example:**
```bash
$ echo "Hello, World!"
Hello, World!
```

## 19. `wget`

**Common Name:** Web Get

**Syntax:** `wget [options] [URL]`

**Purpose:** Download files from the internet.

**Example:**
```bash
$ wget https://example.com/file.zip
(Download progress)
```

## 20. `whoami`

**Common Name:** Who Am I

**Syntax:** `whoami`

**Purpose:** Print the current username.

**Example:**
```bash
$ whoami
user
```

## 21. `sort`

**Common Name:** Sort

**Syntax:** `sort [options] [file]`

**Purpose:** Sort lines of text files.

**Example:**
```bash
$ sort unsorted.txt
Sorted content of unsorted.txt
```

## 22. `cal`

**Common Name:** Calendar

**Syntax:** `cal [options] [month] [year]`

**Purpose:** Display a calendar.

**Example:**
```bash
$ cal
    November 2023      
Su Mo Tu We Th Fr Sa  
          1  2  3  4  
 5  6  7  8  9 10 11  
12 13 14 15 16 17 18  
19 20 21 22 23 24 25  
26 27 28 29 30  
```
