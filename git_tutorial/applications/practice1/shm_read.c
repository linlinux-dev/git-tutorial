#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *shm_name = "/my_shared_mem";
    int fd;

    // Open the shared memory object
    fd = shm_open(shm_name, O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open");
        return 1;
    }

    // Map the shared memory object into the process's address space
    void *shm_ptr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Read data from shared memory
    printf("Reader: Read message from shared memory: %s\n", (char *)shm_ptr);

    // Clean up
    munmap(shm_ptr, 1024);
    close(fd);

    return 0;
}
