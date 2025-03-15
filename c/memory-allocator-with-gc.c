#include <stdio.h>

typedef struct header
{
    unsigned int size;
    struct header *next;
} header_t;

static header_t base;
static header_t *freep = &base;
static header_t *used;

static void
add_to_free_list(header_t *bp)
{
    header_t *p;

    // encontra o local apropriado para inserir o bloco
    // que foi liberado.
    // deve estar entre dois blocos consecutivos na lista de blocos livres (freep).
    for (p = freep; !(bp > p && bp < p->next); p = p->next)
    {
        // verifica se p já alcançou o final da lista
        // caso sim, saimos do loop
        if (p >= p->next && (bp > p || bp < p->next))
        {
            break;
        }
    }

    // verifica se conseguimos juntar o bloco a ser liberado (bp) e o
    // bloco inicial que encontramos (p)
    if (bp + bp->size == p->next)
    {
        bp->size += p->next->size;
        bp->next = p->next->next;
    }
    else
    {
        bp->next = p->next;
    }

    if (p + p->size == bp)
    {
        p->size += bp->size;
        p->next = bp->next;
    }
    else
    {
        p->next = bp;
    }

    freep = p;
}

#define MIN_ALLOC_SIZE 4096

static header_t *morecore(size_t num_units)
{
    void *vp;
    header_t *up;

    if (num_units > MIN_ALLOC_SIZE)
    {
        num_units = MIN_ALLOC_SIZE / sizeof(header_t);
    }

    if ((vp = sbrk(num_units * sizeof(header_t))) == (void *)-1)
    {
        return NULL;
    }

    up = (header_t *)vp;
    up->size = num_units;
    add_to_free_list(up);
    return freep;
}