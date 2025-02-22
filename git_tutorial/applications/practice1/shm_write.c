#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *shm_name = "/my_shared_mem";
    int fd;

    // Create or open shared memory object
    fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open");
        return 1;
    }

    // Set the size of the shared memory object
    if (ftruncate(fd, 1024) == -1) {
        perror("ftruncate");
        return 1;
    }

    // Map the shared memory object into the process's address space
    void *shm_ptr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write data to the shared memory
    const char *message = "Hello from shared memory!";
    strncpy(shm_ptr, message, strlen(message) + 1);  // +1 for the null terminator

    printf("Writer: Written message to shared memory.\n");

    // Clean up
    munmap(shm_ptr, 1024);
    close(fd);

    return 0;
}
