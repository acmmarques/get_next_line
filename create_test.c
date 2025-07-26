#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filename = "tests/single_no_nl_exact.txt"; // New filename for clarity
    const char *content = "This is the only line.";
    int fd;
    ssize_t bytes_written;

    // Ensure the 'tests' directory exists if you're creating the file there
    // (This is usually done beforehand, but for completeness...)
    // mkdir("tests", 0755); // You might need to include <sys/stat.h> for mkdir

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file for writing");
        return 1;
    }

    bytes_written = write(fd, content, strlen(content));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        unlink(filename); // Clean up partially written file
        return 1;
    }

    // Crucially, we do NOT write a newline character here.
    // The 'write' call above only writes the bytes of 'content'.

    close(fd); // Close the file descriptor

    printf("File '%s' created successfully with content: \"%s\"\n", filename, content);

    return 0;
}

