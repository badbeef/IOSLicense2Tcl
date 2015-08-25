/*
The MIT License (MIT)

Copyright (c) 2015 Chui-Tin Yen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>

main()
{
    int i, c;
    printf("tclsh\n");
    printf("set f [open \"flash:file.lic\" w+]\n");
    for (i = 1; (c = getchar()) != EOF; i++) {
        if (i == 1) printf("puts -nonewline $f {");
        switch (c) {
        case '?':
        case '{':
        case '}':
        case '\\':
            printf("}\nputs -nonewline $f \\x%02x\n", c);
            i = 0;
            break;
        default:
            putchar(c);
        }
        if (i > 230) {
            printf("}\n");
            i = 0;
        }
    }
    if (i) printf("}\n");
    printf("exit\nlicense install flash:file.lic\n");
}
