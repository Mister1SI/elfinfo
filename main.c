#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/io.h>
#include <sys/stat.h>
#include <sys/mman.h>

void help(void);

int main(int argc, char** argv) {

    if (argc == 1) {
        help();
        _exit(0);
    }

    char* filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        puts("Failed to open file");
        _exit(2);
    }

    struct stat st;
    fstat(fd, &st);
    size_t filesize = st.st_size;
    
    char* data = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED) {
        puts("Failed to map file to memory");
        _exit(3);
    }
    close(fd);

    munmap(data, filesize);
	return 0;
}

void help(void) {
    char* help_text = "elfinfo: elf file information dumper\n";
    puts(help_text);
}


