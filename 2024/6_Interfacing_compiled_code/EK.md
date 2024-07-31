It is easier for this session to link to repos on my own GitHub account, since both are full R packages.

## cpackagedemo

- <https://github.com/EllaKaye/cpackagedemo>. 

- This is forked from <https://github.com/gagolews/cpackagedemo>

- Added scripts [c_rle.c](https://github.com/EllaKaye/cpackagedemo/blob/master/inst/examples/c_rle.c) and [c_rle.R](https://github.com/EllaKaye/cpackagedemo/blob/master/inst/examples/c_rle.R) which give an implementation of the base `rle()` function, written using R's C API, and an R script for testing it, respectively.

## crle

- <https://github.com/EllaKaye/crle>

- An R package which contains the C implementation of `c_rle()` and an R wrapper function. Same function as in package above, but this time practicing creating the entire package structure around it from scratch (following the [Now You C Me](https://blog.davisvaughan.com/posts/2019-03-02-now-you-c-me/) blog post by Davis Vaughn.)
