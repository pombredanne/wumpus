/**
 * Copyright (C) 2007 Stefan Buettcher. All rights reserved.
 * This is free software with ABSOLUTELY NO WARRANTY.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA
 **/


#include <stdlib.h>
#include "header.h"


extern struct SN_env * SN_create_env(int S_size, int I_size, int B_size)
{   struct SN_env * z = (struct SN_env *) calloc(1, sizeof(struct SN_env));
    z->p = create_s();
    if (S_size)
    {   z->S = (symbol * *) calloc(S_size, sizeof(symbol *));
        {   int i;
            for (i = 0; i < S_size; i++) z->S[i] = create_s();
        }
        z->S_size = S_size;
    }

    if (I_size)
    {   z->I = (int *) calloc(I_size, sizeof(int));
        z->I_size = I_size;
    }

    if (B_size)
    {   z->B = (symbol *) calloc(B_size, sizeof(symbol));
        z->B_size = B_size;
    }

    return z;
}

extern void SN_close_env(struct SN_env * z)
{
    if (z->S_size)
    {
        {   int i;
            for (i = 0; i < z->S_size; i++) lose_s(z->S[i]);
        }
        free(z->S);
    }
    if (z->I_size) free(z->I);
    if (z->B_size) free(z->B);
    if (z->p) lose_s(z->p);
    free(z);
}

extern void SN_set_current(struct SN_env * z, int size, const symbol * s)
{
    replace_s(z, 0, z->l, size, s);
    z->c = 0;
}

