#include "get_next_line.h"

char *get_next_line(int fd){
    t_string ret;
    int c;
    ret.str = NULL;
    ret.len = 0;
    ret.capa = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    while(1){
        c = ft_getc(fd);
        if(c == EOF){
            break;
        }

        if(ft_putc(&ret, c)==-1){
            free(ret.str);
            return NULL;
        }
        if(c == '\n'){
            break;
        }
    }

    if(ret.len > 0){
        ft_putc(&ret, '\0');
        return ret.str;
    } else {
        free(ret.str);
        return NULL;
    }
}

#include <fcntl.h>
#include <stdio.h>
int main(void){
    int fd;
    char *line;
    int line_count;
    line_count = 0;

    fd = open("text.txt", O_RDONLY);
    if(fd < 0){
        perror("open");
        return 1;
    }

    printf("ファイルの内容を1行ずつ読み込みます:\n");
    printf("========================================\n");
    
    while((line = get_next_line(fd)) != NULL){
        line_count++;
        printf("行 %d: %s", line_count, line);
        
        free(line);
    }
    
    printf("\n========================================\n");
    printf("読み込み完了。総行数: %d行\n", line_count);

    close(fd);
    return 0;
}