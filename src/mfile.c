#include "mfile.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int32_t mfile_size(const char *path)
{
    int ret;
    int32_t size = -1;
    struct stat buf = {0};

    ret = stat(path, &buf);
    if (ret == 0)
    {
        size = buf.st_size;
    }

    return size;
}

char *mfile_load(const char *path, int32_t *size)
{
    FILE *pfile = NULL;
    char *buf = NULL;
    int32_t buf_size = 0;

    // get file size
    buf_size = mfile_size(path);
    if (buf_size == -1)
    {
        return NULL;
    }

    // open file
    pfile = fopen(path, "r");
    if (pfile == NULL)
    {
        return NULL;
    }

    // alloc memory
    buf = malloc(buf_size);
    if (buf == NULL)
    {
        fclose(pfile);
        return NULL;
    }

    // read file
    fread(buf, buf_size, 1, pfile);

    // close file
    fclose(pfile);

    return buf;
}

void mfile_unload(char *buf)
{
    if (buf == NULL)
    {
        return;
    }

    free(buf);
}
