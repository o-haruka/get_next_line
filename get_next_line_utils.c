#include "get_next_line.h"

int ft_getc(int fd){
    static char buf[BUFFER_SIZE];
    static char *p;
    static int n = 0;

    if(n == 0){
        n = read(fd, buf, BUFFER_SIZE);
        if(n < 0) {
            n = 0;
            return EOF;
        }
        if(n == 0) {
            return EOF;
        }
        p = buf;
    }
    if(n > 0){
        n--;
        return (unsigned char)*p++;
    }
    return (EOF);
}

int ft_putc(t_string *s, char c) {
    if(s->len + 1 > s->capa) {
        size_t new_capa;
        char *new_str;
        size_t i;
        if (s->capa == 0) {
            new_capa = 16;
        } else {
            new_capa = s->capa * 2;
        }
        new_str = malloc(new_capa);
        if (new_str == NULL)
            return -1;
        
        i = 0;
        while (i < s->len) {
            new_str[i] = s->str[i];
            i++;
        }
        if (s->str != NULL)
            free(s->str);
        s->str = new_str;
        s->capa = new_capa;
    }
    s->str[s->len] = c;
    s->len++;
    return 0;
}
