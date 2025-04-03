#include <errno.h>

extern char _end[];
extern char _heap_end[];

static char *_cur_brk = _end;
void *_sbrk_r(struct _reent *reent, ptrdiff_t diff)
{
    char *_old_brk = _cur_brk;
    if (_cur_brk + diff > _heap_end)
    {
        errno = ENOMEM;
        return (void *)-1;
    }
    _cur_brk += diff;
    return _old_brk;
}