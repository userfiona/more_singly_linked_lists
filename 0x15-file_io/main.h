#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

ssize_t read_textfile(const char *fn, size_t num_letters);
int create_file(const char *fn, char *text_content);
int append_text_to_file(const char *fn, char *text_content);

#endif /* _MAIN_H_ */
