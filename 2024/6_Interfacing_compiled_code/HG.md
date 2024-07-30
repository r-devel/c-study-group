This package uses instructions from https://blog.davisvaughan.com/posts/2019-03-02-now-you-c-me/ to implement a C version of the `rle()` base function:

https://github.com/Bisaloo/myrle

The proposed `myrle()` function only covers a subset of cases (x is `numeric()`) & Paul Murrell pointed out important shortcomings, noted as comments in the source code.

The discussion during the zoom meeting centered on:

- how to structure C code for functions that can take different types of outputs
- memory vs speed optimization and calculating the output size early
- performance vs readability and the benefit (or lack of) of converting an R function to C
- style for C code in base R
- setting attributes and checking inputs in the R wrapper vs C code
